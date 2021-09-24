#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <queue>

namespace slesk {
	
	class Echo {
		
	public:
		
		Echo(std::ostream& _stream);
		
		void flush();
		
		void trace(const std::string& message, const std::string& sender = "");
		void info(const std::string& message, const std::string& sender = "");
		void warning(const std::string& message, const std::string& sender = "");
		void error(const std::string& message, const std::string& sender = "");
		void fatal(const std::string& message, const std::string& sender = "");
		
		inline std::ostream& stream() {
			return m_stream;
		}
		
	private:
		
		std::ostream& m_stream;
		
		std::queue <std::string> m_pending;
		
	};
	
} /// namespace slesk
