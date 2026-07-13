#include "nova_logger.h"
#include <ctime>

void NovaLogger::logEvent(const std::string& level, const std::string& message) {
    std::ofstream logFile("system_logs/nova_runtime.log", std::ios_base::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    std::string timestamp(dt);
    timestamp.pop_back(); // Remove newline
    
    logFile << "[" << timestamp << "] [" << level << "] " << message << "\n";
    logFile.close();
}
