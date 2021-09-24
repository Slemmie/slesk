#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <iostream>

namespace slesk {
	
	struct CommandToken {
		
		unsigned int ind;
		std::string str;
		
		CommandToken(unsigned int _ind = 1 << 30, const std::string& _str = "") :
		ind(_ind),
		str(_str)
		{ }
		
	};
	
	class Command {
		
	public:
		
		Command(const std::string& _command) :
		m_command(std::string(_command.begin() + 1, _command.end() - 1))
		{
			assert(_command.front() == '{');
			assert(_command.back() == '}');
			std::stringstream stream(std::string(_command.begin() + 1, _command.end() - 1));
			std::string buf;
			unsigned int i = 0;
			while (std::getline(stream, buf, ' ')) {
				if (buf.empty()) {
					continue;
				}
				if (m_module.ind == (1 << 30)) {
					m_module = CommandToken(i++, buf);
					continue;
				}
				if (buf[0] == '-') {
					m_flags.push_back(CommandToken(i++, buf));
					continue;
				}
				m_vars.push_back(CommandToken(i++, buf));
			}
		}
		
		inline const std::string& command() const {
			return m_command;
		}
		
		inline const CommandToken& module() const {
			return m_module;
		}
		
		inline const std::vector <CommandToken>& vars() const {
			return m_vars;
		}
		
		inline const std::vector <CommandToken>& flags() const {
			return m_flags;
		}
		
		inline std::string command_args() const {
			return m_command.substr(m_module.str.length() + (m_command[m_module.str.length()] == ' '));
		}
		
		inline const std::string& str() const {
			return m_command;
		}
		
		inline std::ostream& operator << (std::ostream& stream) const {
			stream << this->str();
			return stream;
		}
		
	private:
		
		std::string m_command;
		CommandToken m_module;
		std::vector <CommandToken> m_vars;
		std::vector <CommandToken> m_flags;
		
	};
	
} /// namespace slesk
