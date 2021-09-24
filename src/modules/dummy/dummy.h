#pragma once

#include <module_util.h>
#include <echoes.h>

#include <memory>

class Dummy : public slesk::Module {
	
public:
	
	Dummy(const std::shared_ptr <slesk::Echo>& _echo);
	
	void command(const slesk::Command& c) override;
	
	bool valid_alias(const slesk::CommandToken& ct) override;
	
private:
	
	std::shared_ptr <slesk::Echo> m_echo;
	
};
