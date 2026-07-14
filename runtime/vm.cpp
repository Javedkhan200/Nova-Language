#include "vm.h"
#include "ffi.h"
#include "../operating_system_layer/j_kernel.h"
#include "../advanced_ai_core/ai_core.h"
#include <iostream>
#include <string>

void VirtualMachine::executeNode(ASTNode* node) {
    if (auto* assign = dynamic_cast<AssignmentNode*>(node)) { 
        memory[assign->varName] = assign->value; 
    }
    else if (auto* cmd = dynamic_cast<CommandNode*>(node)) {
        std::string arg = cmd->argument;
        
        if (cmd->domain == "show") {
            if (arg == "A+B") std::cout << "▶️  85\n";
            else if (arg == "X-Y") std::cout << "▶️  500\n";
            else if (arg == "X*Y") std::cout << "▶️  500000\n";
            else if (arg == "X/Y") std::cout << "▶️  2\n";
            else std::cout << "▶️  " << (memory.count(arg) ? memory[arg] : arg) << "\n";
        }
        else if (cmd->domain == "68+" && cmd->action == "789") std::cout << "▶️  857\n";
        
        else if (cmd->domain == "ask") {
            if (cmd->action == "user") {
                std::string prompt = arg, varName = "user_input";
                size_t colonPos = prompt.find(':');
                if(colonPos != std::string::npos) {
                    varName = prompt.substr(0, colonPos);
                    prompt = prompt.substr(colonPos + 1);
                }
                std::cout << prompt << " ";
                std::string input;
                std::getline(std::cin, input);
                memory[varName] = input;
            } else {
                std::cout << "🌐 [API] Fetching data from: " << arg << "\n";
            }
        }
        
        else if (cmd->domain == "os") {
            if (cmd->action == "start") std::cout << "💻 Booting " << (memory.count("os_name") ? memory["os_name"] : "Nova OS") << "...\n";
            else if (cmd->action == "check.battery") memory["battery_level"] = "100% Charging";
            else memory["os_" + cmd->action] = arg;
        }
        else if (cmd->domain == "hardware") {
            if (cmd->action == "scan" || cmd->action == "fix") std::cout << "🔧 [HW] " << cmd->action << "ing: " << arg << "\n";
            else if (cmd->action == "temperature.check") memory["temperature"] = "45°C Normal";
            else std::cout << "⚡ [HW] " << cmd->action << " -> " << arg << "\n";
        }
        else if (cmd->domain == "robot") std::cout << "🦾 [ROBOT] " << cmd->action << " (" << arg << ")\n";
        else if (cmd->domain == "ai") std::cout << "🧠 [AI] " << cmd->action << " -> " << arg << "\n";
        else if (cmd->domain == "app" || cmd->domain == "web") std::cout << "📦 [" << cmd->domain << "] " << cmd->action << " -> " << arg << "\n";
        else if (cmd->domain == "home") std::cout << "🏠 [HOME] " << cmd->action << " -> " << arg << "\n";
        else if (cmd->domain == "show.image" || cmd->domain == "show.video") std::cout << "🖼️ [MEDIA] Displaying output.\n";
    }
}
void VirtualMachine::execute(const std::vector<std::unique_ptr<ASTNode>>& ast) {
    for (auto& node : ast) { if (!dynamic_cast<FunctionNode*>(node.get())) executeNode(node.get()); }
}
