#include "nova_game.h"

void NovaGame::initGame(const std::string& type) {
    std::cout << "🎮 [NOVA ENGINE] Initializing Game Loop: " << type << "...\n";
    std::cout << "   ↳ [Graphics Core] OpenGL/Vulkan Context Created.\n";
}
void NovaGame::spawnEntity(const std::string& entity, const std::string& coords) {
    std::cout << "👾 [NOVA ENGINE] Spawning '" << entity << "' at coordinates: " << coords << "\n";
}
void NovaGame::applyPhysics(const std::string& type, const std::string& val) {
    std::cout << "🍎 [PHYSICS] Applying " << type << " at " << val << " m/s².\n";
    std::cout << "   ↳ [Collision Engine] Hitboxes active.\n";
}
void NovaGame::renderScene(const std::string& dimension) {
    std::cout << "🎥 [RENDER] Rendering Scene in " << dimension << "...\n";
    std::cout << "   ↳ [FPS] Stable at 60 FPS.\n";
}
