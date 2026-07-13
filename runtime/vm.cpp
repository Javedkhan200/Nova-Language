#include "vm.h"
#include "ffi.h"
#include "../advanced_ai_core/ai_core.h"
#include "../operating_system_layer/j_kernel.h"
#include "../full_stack_dev/hyperweb.h"
#include "../standard_library/database/nova_db.h"
#include "../security/nova_security.h"
#include "../networking/nova_network.h"
#include "../standard_library/finance/nova_finance.h"
#include "../standard_library/health/nova_health.h"
#include "../game_engine/nova_game.h"
#include "../blockchain_web3/nova_web3.h"
#include "../package_ecosystem/nova_pm.h"
#include "../tooling/nova_tools.h"
#include "../universal_packages/python_bridge/py_interop.h"
#include "../ide/vscode_extension/nova_lsp.h"
#include "../hardware_control/embedded_targets/nova_iot.h"
#include "../deployment/nova_deploy.h"
#include "../experiments/quantum/nova_quantum.h"
#include "../graphics/nova_graphics.h"
#include "../physics_engine/nova_physics.h"
#include "../ui/nova_ui.h"
#include "../testing/nova_test.h"
#include "../analytics/nova_telemetry.h"
#include "../docs/nova_docgen.h"
#include <iostream>
#include <string>

void VirtualMachine::executeNode(ASTNode* node) {
    if (auto* assign = dynamic_cast<AssignmentNode*>(node)) { memory[assign->varName] = assign->value; }
    else if (auto* cmd = dynamic_cast<CommandNode*>(node)) {
        std::string arg = cmd->argument;
        
        if (cmd->domain == "show") std::cout << "▶️  " << (memory.count(arg) ? memory[arg] : arg) << "\n";
        else if (cmd->domain == "show.image") std::cout << "🖼️  [NOVA DISPLAY] Rendering Image output on screen.\n";
        else if (cmd->domain == "show.video") std::cout << "🎥 [NOVA DISPLAY] Playing Video output on screen.\n";
        
        else if (cmd->domain == "ask") std::cout << "🌐 [API BRIDGE] Fetching data from: " << arg << "...\n";
        else if (cmd->domain == "ask.user") {
            std::cout << "💬 " << arg << " ";
            std::string input = "Javed"; // Simulated input for fast execution
            memory["name"] = input;
            std::cout << "[User Input Saved: " << input << "]\n";
        }
        
        else if (cmd->domain == "os") {
            if (cmd->action == "name" || cmd->action == "version" || cmd->action == "type") memory["os_"+cmd->action] = arg;
            else if (cmd->action == "start") JKernel::bootSystem(memory.count("os_name") ? memory["os_name"] : "Nova OS");
            else std::cout << "💻 [OS CORE] Configured OS " << cmd->action << " to: " << arg << "\n";
        }
        
        else if (cmd->domain == "hardware") {
            if (cmd->action == "scan") JKernel::scanHardware(arg);
            else if (cmd->action == "fix") std::cout << "🔧 [HARDWARE] Running diagnostics & fixing: " << arg << "...\n";
            else std::cout << "⚙️  [HARDWARE] " << cmd->action << " set to: " << arg << "\n";
        }
        
        else if (cmd->domain == "robot") {
            if (cmd->action == "speak") std::cout << "🔊 [ROBOT VOICE] Synthesizing: \"" << arg << "\"\n";
            else FFI_Bridge::executeRobotics(cmd->action, arg);
        }
        
        else if (cmd->domain == "ai") {
            if (cmd->action == "name") NeuraBrain::initializeModel(arg);
            else if (cmd->action == "learn") NeuraBrain::trainDataset(arg);
            else if (cmd->action == "think") NeuraBrain::runInference(arg);
            else if (cmd->action == "answer") std::cout << "🤖 [AI RESPONSE] Generating contextual answer...\n";
            else if (cmd->action == "generate.image") std::cout << "🎨 [AI VISION] Generating image for: " << arg << "\n";
            else if (cmd->action == "generate.video") std::cout << "🎬 [AI STUDIO] Generating video for: " << arg << "\n";
        }
        
        else if (cmd->domain == "app" || cmd->domain == "web") {
            if (cmd->action == "name" || cmd->action == "theme") std::cout << "📦 [UI ENGINE] Configuring " << cmd->domain << " " << cmd->action << ": " << arg << "\n";
            else if (cmd->action == "add.button" || cmd->action == "add.link") std::cout << "🖱️ [UI ENGINE] Added UI Element: " << arg << "\n";
            else if (cmd->action == "build" || cmd->action == "publish") HyperWebEngine::deployApp(arg);
            else std::cout << "⚙️  [" << cmd->domain << "] Action executed: " << cmd->action << "\n";
        }

        else if (cmd->domain == "home") {
            std::cout << "🏠 [SMART HOME] Executing " << cmd->action << " command: " << arg << "\n";
        }
    }
}

void VirtualMachine::execute(const std::vector<std::unique_ptr<ASTNode>>& ast) {
    for (auto& node : ast) { if (auto* fn = dynamic_cast<FunctionNode*>(node.get())) functions[fn->funcName] = fn; }
    for (auto& node : ast) { if (!dynamic_cast<FunctionNode*>(node.get())) executeNode(node.get()); }
}
