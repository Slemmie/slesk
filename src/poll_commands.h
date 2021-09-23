#pragma once

#include <util.h>

#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>

namespace slesk {
	
	class Poll {
		
	public:
		
		static std::vector <std::string> poll_commands(const char* dirpath) {
			std::vector <std::string> result;
			std::vector <std::string> files = m_get_current_files(dirpath);
			for (std::string file : files) {
				std::ifstream inf(file.c_str());
				assert(inf.is_open());
				std::string buf;
				std::getline(inf, buf);
				if (!buf.empty() && buf.front() == '{' && buf.back() == '}') {
					result.push_back(buf);
					remove(file.c_str());
				} else {
					m_check_file_age(std::string(dirpath), file);
				}
				inf.close();
			}
			return result;
		}
		
	private:
		
		static inline void m_seek_line(std::ifstream& stream, unsigned int line) {
			stream.seekg(std::ios::beg);
			for (unsigned int i = 0; i < line; i++) {
				stream.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
			}
		}
		
		static void m_check_file_age(const std::string& filedir, const std::string& file) {
			// TODO this
		}
		
		static std::vector <std::string> m_get_current_files(const char* dirpath) {
			std::vector <std::string> result;
			std::vector <std::string> files = ls(dirpath);
			for (const std::string& file : files) {
				if (has_suffix(file, ".slcmmd")) {
					result.push_back(file);
				}
			}
			return result;
		}
		
	};
	
} /// namespace slesk
