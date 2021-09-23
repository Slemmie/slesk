#pragma once

#include <chrono>
#include <thread>
#include <cassert>
#include <random>
#include <filesystem>
#include <vector>
#include <string>

namespace slesk {
	
	static inline void sleep(uint64_t millis) {
		std::this_thread::sleep_for(std::chrono::milliseconds(millis));
	}
	
	static inline std::vector <std::string> ls(const char* dirpath) {
		std::vector <std::string> result;
		for (const auto& entry : std::filesystem::directory_iterator(dirpath)) {
			result.push_back(entry.path());
		}
		return result;
	}
	
	static inline bool has_suffix(const std::string& str, const std::string& pattern) {
		if (str.size() < pattern.size()) {
			return false;
		}
		return std::string(str.end() - pattern.size(), str.end()) == pattern;
	}
	
	static inline long long milli_timestamp() {
		return std::chrono::duration_cast <std::chrono::milliseconds> (
		std::chrono::system_clock::now().time_since_epoch()).count();
	}
	
	static inline std::string concat(const std::vector <std::string>& v) {
		std::string result;
		for (const std::string& s : v) {
			result += s;
		}
		return result;
	}
	
	struct Random {
		
		static inline long long range(long long lb, long long ub) {
			assert(lb <= ub);
			static std::random_device device;
			static std::mt19937 generator(device());
			std::uniform_int_distribution <long long> distribution(lb, ub);
			return distribution(generator);
		}
		
	};
	
} /// namespace slesk
