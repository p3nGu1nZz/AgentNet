// AgentNetTerm.cpp : Defines the entry point for the application.
//

#include "AgentNetTerm.h"

namespace fs = std::filesystem;

const auto UpdateInterval = std::chrono::milliseconds(250);

std::vector<std::string> get_available_drives() {
	std::vector<std::string> drives;
	for (char drive = 'C'; drive <= 'Z'; ++drive) {
		std::string drive_str(1, drive);
		drive_str += ":/";
		if (fs::exists(drive_str) && fs::is_directory(drive_str)) {
			drives.emplace_back(std::move(drive_str));
		}
	}
	return drives;
}

void print_waiting_indicator(unsigned long long count, int& indicator_state) {
	const char indicators[] = { '|', '/', '-', '\\' };
	std::cout << '\r' << indicators[indicator_state] << " - Files Searched: [" << count << ']' << std::flush;
	indicator_state = (indicator_state + 1) % 4;
}

void search_drives(const std::vector<std::string>& drives, const std::set<std::string>& directories_to_search) {
	unsigned long long current_file_count = 0;
	std::vector<std::string> found_models;
	auto last_update_time = std::chrono::steady_clock::now();
	int indicator_state = 0;

	for (const auto& drive : drives) {
		for (const auto& entry : fs::recursive_directory_iterator(drive, fs::directory_options::skip_permission_denied)) {
			try {
				if (entry.is_regular_file()) {
					++current_file_count;
				}
				else if (entry.is_directory() && directories_to_search.find(entry.path().filename().string()) != directories_to_search.end()) {
					if (!entry.is_symlink()) {
						found_models.push_back(entry.path().filename().string());
					}
				}
			}
			catch (const fs::filesystem_error&) {
				// Skip logging filesystem errors
			}

			auto current_time = std::chrono::steady_clock::now();
			if (current_time - last_update_time >= UpdateInterval) {
				print_waiting_indicator(current_file_count, indicator_state);
				last_update_time = current_time;
			}
		}
	}
	std::cout << '\n' << "Total file count: [" << current_file_count << "]\n";
	for (const auto& model : found_models) {
		std::cout << "Model found: \"" << model << "\"\n";
	}
}

int main() {
	std::cout << "Starting the search for models...\n";
	std::set<std::string> directories_to_search = { "llama-2-7b", "llama-2-13b", "llama-2-70b" };
	auto drives = get_available_drives();
	search_drives(drives, directories_to_search);
	return 0;
}
