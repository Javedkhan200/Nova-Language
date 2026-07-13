#ifndef FFI_H
#define FFI_H
#include <string>
#include <iostream>
#include "../robotics_control/robot_core.h"

class FFI_Bridge {
public:
    static void executeNativeOS(const std::string& command);
    static void executePython(const std::string& pythonCode);
    static void executeJS(const std::string& jsCode);
    static void executeRobotics(const std::string& action, const std::string& arg);
};
#endif
