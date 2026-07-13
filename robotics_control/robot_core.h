#ifndef ROBOT_CORE_H
#define ROBOT_CORE_H
#include <string>
#include <iostream>

// NeuraStudio Robotics Subsystem
class NeuraRobot {
public:
    static void connectHardware(const std::string& model);
    static void setEnginePower(const std::string& state);
    static void moveKinematics(const std::string& direction, const std::string& units);
    static void actuateServos(const std::string& action, const std::string& object);
    static void streamOptics(const std::string& state);
    static void vocalizeAudio(const std::string& text);
};
#endif
