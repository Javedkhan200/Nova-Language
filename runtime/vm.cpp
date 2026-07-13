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

void VirtualMachine::executeNode(ASTNode* node) {
    if (auto* assign = dynamic_cast<AssignmentNode*>(node)) { memory[assign->varName] = assign->value; }
    else if (auto* cmd = dynamic_cast<CommandNode*>(node)) {
        if (cmd->domain == "show") std::cout << "▶️  " << (memory.count(cmd->argument) ? memory[cmd->argument] : cmd->argument) << "\n";
        else if (cmd->domain == "call") {
             if (functions.count(cmd->argument)) {
                std::cout << "⚡ [NOVA CORE] Executing Function: " << cmd->argument << "()\n";
                for (const auto& stmt : functions[cmd->argument]->body) executeNode(stmt.get());
             }
        }
        else if (cmd->domain == "os") JKernel::bootSystem("Nova OS");
        else if (cmd->domain == "ai") NeuraBrain::runInference(cmd->argument);
        else if (cmd->domain == "robot") FFI_Bridge::executeRobotics(cmd->action, cmd->argument);
        else if (cmd->domain == "finance") NovaFinance::sendTransaction(cmd->argument);
        else if (cmd->domain == "security") NovaSecurity::startFirewall();
        // ... (यह VM अब पूरी तरह मॉड्यूलर है)
    }
}
void VirtualMachine::execute(const std::vector<std::unique_ptr<ASTNode>>& ast) {
    for (auto& node : ast) { if (auto* fn = dynamic_cast<FunctionNode*>(node.get())) functions[fn->funcName] = fn; }
    for (auto& node : ast) { if (!dynamic_cast<FunctionNode*>(node.get())) executeNode(node.get()); }
}
