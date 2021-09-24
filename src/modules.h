// includes of all modules

#pragma once

#include <module_util.h>
#include <echoes.h>
#include <command.h>

#include <memory>

std::shared_ptr <slesk::Echo> echo = std::make_shared <slesk::Echo> (std::cout);

#include <modules/dummy/dummy.h>
std::shared_ptr <Dummy> dummy = std::make_shared <Dummy> (echo);

static void distribute_command(const slesk::Command& c) {
	// Dummy
	if (dummy->valid_alias(c.module())) {
		dummy->command(c);
	}
	// ...
}
