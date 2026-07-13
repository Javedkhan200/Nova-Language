cmake_minimum_required(VERSION 3.10)
project(NovaCompiler)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -flto -Wall -Wextra")

add_executable(nova
    compiler/main.cpp compiler/lexer.cpp compiler/parser.cpp compiler/bytecode.cpp
    runtime/vm.cpp runtime/ffi.cpp
    robotics_control/robot_core.cpp advanced_ai_core/ai_core.cpp
    operating_system_layer/j_kernel.cpp full_stack_dev/hyperweb.cpp
    standard_library/database/nova_db.cpp security/nova_security.cpp
    networking/nova_network.cpp standard_library/finance/nova_finance.cpp
    standard_library/health/nova_health.cpp game_engine/nova_game.cpp 
    blockchain_web3/nova_web3.cpp package_ecosystem/nova_pm.cpp 
    tooling/nova_tools.cpp universal_packages/python_bridge/py_interop.cpp
    ide/vscode_extension/nova_lsp.cpp hardware_control/embedded_targets/nova_iot.cpp
    deployment/nova_deploy.cpp experiments/quantum/nova_quantum.cpp
    graphics/nova_graphics.cpp physics_engine/nova_physics.cpp ui/nova_ui.cpp
    testing/nova_test.cpp analytics/nova_telemetry.cpp docs/nova_docgen.cpp
    system_logs/nova_logger.cpp
)
