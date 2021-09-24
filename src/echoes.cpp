#include <echoes.h>

namespace slesk {
	
	Echo::Echo(std::ostream& _stream) :
	m_stream(_stream)
	{
		
	}
	
	void Echo::flush() {
		while (!m_pending.empty()) {
			m_stream << m_pending.front() << std::endl;
			m_pending.pop();
		}
	}
	
	void Echo::trace(const std::string& message, const std::string& sender) {
		std::stringstream ss;
		if (!sender.empty()) {
			ss << "\033[97;1m(" << sender << ") \033[0m";
		}
		ss << "\033[37m" << message << "\033[0m";
		m_pending.push(ss.str());
	}
	
	void Echo::info(const std::string& message, const std::string& sender) {
		std::stringstream ss;
		ss << "\033[96m" << "[info]: " << "\033[0m";
		if (!sender.empty()) {
			ss << "\033[97;1m(" << sender << ") \033[0m";
		}
		ss << "\033[37m" << message << "\033[0m";
		m_pending.push(ss.str());
	}
	
	void Echo::warning(const std::string& message, const std::string& sender) {
		std::stringstream ss;
		ss << "\033[93m" << "[warning]: " << "\033[0m";
		if (!sender.empty()) {
			ss << "\033[97;1m(" << sender << ") \033[0m";
		}
		ss << "\033[37m" << message << "\033[0m";
		m_pending.push(ss.str());
	}
	
	void Echo::error(const std::string& message, const std::string& sender) {
		std::stringstream ss;
		ss << "\033[91m" << "[error]: " << "\033[0m";
		if (!sender.empty()) {
			ss << "\033[97;1m(" << sender << ") \033[0m";
		}
		ss << "\033[37m" << message << "\033[0m";
		m_pending.push(ss.str());
	}
	
	void Echo::fatal(const std::string& message, const std::string& sender) {
		std::stringstream ss;
		ss << "\033[31;1m" << "[fatal]: " << "\033[0m";
		if (!sender.empty()) {
			ss << "\033[97;1m(" << sender << ") \033[0m";
		}
		ss << "\033[37m" << message << "\033[0m";
		m_pending.push(ss.str());
		flush();
		exit(1);
	}
	
} /// namespace slesk
