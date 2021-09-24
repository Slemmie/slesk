// driver program

#include <modules.h>
#include <poll_commands.h>
#include <command.h>
#include <util.h>
#include <settings.h>

#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <memory>

#include <iostream>

int main(int argc, char** argv) {
	
	bool launch = false;
	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "--launch")) {
			launch = true;
		}
	}
	
	// slesk ran with a command
	if (!launch) {
		std::string command = "{";
		for (int i = 1; i < argc; i++) {
			command += std::string(argv[i]) + " }"[i + 1 == argc];
		}
		std::string filepath = PATH;
		filepath += std::to_string(slesk::milli_timestamp());
		filepath += "_";
		filepath += std::to_string(slesk::Random::range(0LL, 1LL << 32));
		filepath += ".slcmmd";
		std::ofstream ouf(filepath);
		assert(ouf.is_open());
		ouf << command << "\n";
		ouf.close();
		return 0;
	}
	
	std::queue <slesk::Command> command_queue;
	while (true) {
		std::vector <std::string> now = slesk::Poll::poll_commands(PATH);
		for (const std::string& s : now) {
			slesk::Command command = slesk::Command(s);
			command_queue.push(command);
			echo->trace(slesk::concat({ "recieved: ", command.str() }));
		}
		while (!command_queue.empty()) {
			distribute_command(command_queue.front());
			command_queue.pop();
		}
		echo->flush();
		slesk::sleep(100);
	}
	
}
