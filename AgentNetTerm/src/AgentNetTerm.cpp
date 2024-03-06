// AgentNetTerm.cpp : Defines the entry point for the application.
//

#include "AgentNetTerm.h"

namespace fs = std::filesystem;

std::vector<std::string> get_available_drives() {
	std::vector<std::string> drives;
	char drive = 'C';
	for (; drive <= 'Z'; ++drive) {
		std::string drive_str = std::string(1, drive) + ":/";
		if (fs::is_directory(drive_str)) {
			drives.push_back(drive_str);
			std::cout << "Found drive: " << drive_str << std::endl;
		}
	}
	return drives;
}

// Function to print the rotating waiting indicator
void print_waiting_indicator(unsigned long long count, int indicator_state) {
    const char indicators[] = { '|', '/', '-', '\\' };
    std::cout << "\r" << indicators[indicator_state] << " - Files Searched: [" << count << "]" << std::flush;
}

void search_drives(const std::vector<std::string>& drives, const std::set<std::string>& directories_to_search) {
    unsigned long long current_file_count = 0;
    std::vector<fs::path> found_directories;
    auto last_update_time = std::chrono::high_resolution_clock::now();
    int indicator_state = 0;

    for (const auto& drive : drives) {
        auto it = fs::recursive_directory_iterator(drive, fs::directory_options::skip_permission_denied);
        auto end = fs::end(it);

        for (; it != end; ++it) {
            try {
                if (it->is_regular_file()) {
                    ++current_file_count;
                }
                else if (it->is_directory() && directories_to_search.find(it->path().filename().string()) != directories_to_search.end()) {
                    if (fs::is_directory(it->symlink_status()) && !fs::is_symlink(it->symlink_status())) {
                        found_directories.push_back(it->path());
                    }
                }
            }
            catch (const fs::filesystem_error&) {
                // Skip logging filesystem errors
            }

            // Refresh waiting indicator and file count every 250ms
            auto current_time = std::chrono::high_resolution_clock::now();
            if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_update_time).count() >= 250) {
                print_waiting_indicator(current_file_count, indicator_state);
                last_update_time = current_time; // Reset the timer
                indicator_state = (indicator_state + 1) % 4; // Update the indicator state
            }
        }
    }
    std::cout << std::endl; // Move to a new line after the search is complete

    std::cout << "Total file count: [" << current_file_count << "]" << std::endl;
    for (const auto& dir : found_directories) {
        std::cout << "Directory found: " << dir << std::endl;
    }
}

int main() {
	std::set<std::string> directories_to_search = { "llama-2-7b", "llama-2-13b", "llama-2-70b" };
	std::vector<std::string> drives = get_available_drives();
	std::cout << "Total drives found: " << drives.size() << std::endl;

	search_drives(drives, directories_to_search);

	return 0;
}
