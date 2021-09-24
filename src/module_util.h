#pragma once

#include <command.h>

namespace slesk {
	
	class Module {
		
	public:
		
		Module() {
			
		}
		
		virtual ~Module() {
			
		}
		
		virtual void command(const Command& c) = 0;
		virtual bool valid_alias(const CommandToken& ct) = 0;
		
	};
	
} /// namespace slesk
