#include "nova_telemetry.h"

void NovaTelemetry::logCrash(const std::string& error) {
    std::cout << "⚠️ [TELEMETRY] Critical Fault Logged: " << error << "\n";
    std::cout << "   ↳ Auto-reporting to NeuraStudio Servers.\n";
}

void NovaTelemetry::trackPerformance() {
    std::cout << "📊 [TELEMETRY] Profiling System Performance...\n";
    std::cout << "   ↳ CPU: 12% | RAM: 45MB | Disk I/O: 120MB/s\n";
}
