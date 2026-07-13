#ifndef NOVA_GAME_H
#define NOVA_GAME_H
#include <string>
#include <iostream>

class NovaGame {
public:
    static void initGame(const std::string& type);
    static void spawnEntity(const std::string& entity, const std::string& coords);
    static void applyPhysics(const std::string& type, const std::string& val);
    static void renderScene(const std::string& dimension);
};
#endif
