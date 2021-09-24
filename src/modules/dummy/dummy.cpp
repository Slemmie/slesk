#include <modules/dummy/dummy.h>

Dummy::Dummy(const std::shared_ptr <slesk::Echo>& _echo) :
m_echo(_echo)
{ }

void Dummy::command(const slesk::Command& c) {
	m_echo->trace(c.command_args(), "dummy");
}

bool Dummy::valid_alias(const slesk::CommandToken& ct) {
	if (ct.str == "dummy") {
		return true;
	}
	return false;
}
