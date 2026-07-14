#include "vm.h"
#include "ffi.h"
#include "../operating_system_layer/j_kernel.h"
#include "../advanced_ai_core/ai_core.h"
#include <iostream>
#include <string>
#include <unordered_map>

std::string evaluateMath(const std::string& expr, std::unordered_map<std::string, std::string>& mem) {
    std::string cleanExpr = expr;
    if (!cleanExpr.empty() && cleanExpr.front() == '"') cleanExpr.erase(0, 1);
    if (!cleanExpr.empty() && cleanExpr.back() == '"') cleanExpr.pop_back();

    size_t opPos = std::string::npos;
    char op = ' ';
    if (cleanExpr.find('+') != std::string::npos) { opPos = cleanExpr.find('+'); op = '+'; }
    else if (cleanExpr.find('-') != std::string::npos) { opPos = cleanExpr.find('-'); op = '-'; }
    else if (cleanExpr.find('*') != std::string::npos) { opPos = cleanExpr.find('*'); op = '*'; }
    else if (cleanExpr.find('/') != std::string::npos) { opPos = cleanExpr.find('/'); op = '/'; }

    if (opPos != std::string::npos) {
        std::string leftStr = cleanExpr.substr(0, opPos);
        std::string rightStr = cleanExpr.substr(opPos + 1);

        if (mem.count(leftStr)) leftStr = mem[leftStr];
        if (mem.count(rightStr)) rightStr = mem[rightStr];

        try {
            int left = std::stoi(leftStr);
            int right = std::stoi(rightStr);
            if (op == '+') return std::to_string(left + right);
            if (op == '-') return std::to_string(left - right);
            if (op == '*') return std::to_string(left * right);
            if (op == '/') return (right == 0) ? "Error: Div/0" : std::to_string(left / right);
        } catch (...) { 
            // अगर यह मैथ नहीं है (जैसे Self-Hosted), तो असल टेक्स्ट वापस कर दो!
            return mem.count(expr) ? mem[expr] : cleanExpr; 
        }
    }
    return mem.count(expr) ? mem[expr] : cleanExpr;
}

void VirtualMachine::executeNode(ASTNode* node) {
    if (auto* assign = dynamic_cast<AssignmentNode*>(node)) { memory[assign->varName] = assign->value; }
    else if (auto* cmd = dynamic_cast<CommandNode*>(node)) {
        std::string arg = cmd->argument;

        if (cmd->domain == "show") {
            if(arg.find('+') != std::string::npos || arg.find('-') != std::string::npos || arg.find('*') != std::string::npos || arg.find('/') != std::string::npos) {
                std::cout << "▶️  " << evaluateMath(arg, memory) << "\n";
            } else {
                std::string out = memory.count(arg) ? memory[arg] : arg;
                if (!out.empty() && out.front() == '"') out.erase(0, 1);
                if (!out.empty() && out.back() == '"') out.pop_back();
                std::cout << "▶️  " << out << "\n";
            }
        }
        else if (cmd->domain == "math_calc") std::cout << "▶️  " << evaluateMath(arg, memory) << "\n";
        else if (cmd->domain == "ask") {
            if (cmd->action == "user") {
                std::string prompt = arg, varName = "user_input";
                if (arg.find("\"name:\"") == 0) { varName = "name"; prompt = arg.substr(7) + " : "; }
                else if (arg.find("\"password:\"") == 0) { varName = "password"; prompt = arg.substr(11) + " : "; }
                else if (arg.find("\"question:\"") == 0) { varName = "question"; prompt = arg.substr(11) + " : "; }
                else {
                    size_t colonPos = prompt.find(':');
                    if(colonPos != std::string::npos) {
                        varName = prompt.substr(0, colonPos);
                        prompt = prompt.substr(colonPos + 1) + " : ";
                    }
                }
                std::cout << "💬 " << prompt;
                std::string input;
                std::getline(std::cin, input);
                memory[varName] = input;
            } else { std::cout << "🌐 [API] Fetching data from: " << arg << "\n"; }
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
