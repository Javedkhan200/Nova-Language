#include "ffi.h"
#include "../universal_packages/python_bridge/py_interop.h"
#include <cstdlib>

void FFI_Bridge::executeNativeOS(const std::string& command) {
    std::cout << "   ↳ [J-Kernel Native] Executing: " << command << "\n";
}
void FFI_Bridge::executePython(const std::string& pythonCode) {
    PythonBridge::executeScript(pythonCode);
}
void FFI_Bridge::executeJS(const std::string& jsCode) {
    std::cout << "   ↳ [Nova HyperWeb] Rendering: " << jsCode << "\n";
}
void FFI_Bridge::executeRobotics(const std::string& action, const std::string& arg) {
    std::cout << "🦾 [ROBOTICS FFI] Executing Action: " << action << " -> " << arg << "\n";
}
