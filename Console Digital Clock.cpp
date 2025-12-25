// Simple console clock that updates every second
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <ctime>

void clearConsole() {
    // Platform-specific clear command
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    while(true) {
        clearConsole();
        
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        std::tm* localTime = std::localtime(&time);
        
        std::cout << "========== DIGITAL CLOCK ==========\n\n";
        std::cout << "    " << std::put_time(localTime, "%H:%M:%S") << "\n\n";
        std::cout << "===================================\n";
        std::cout << "Date: " << std::put_time(localTime, "%Y-%m-%d") << "\n";
        std::cout << "Day: " << std::put_time(localTime, "%A") << "\n";
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}