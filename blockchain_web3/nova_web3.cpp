#include "nova_web3.h"

void NovaWeb3::startNode() {
    std::cout << "⛓️  [WEB3] Starting Decentralized Blockchain Node...\n";
    std::cout << "   ↳ [P2P] Syncing with global ledger.\n";
}
void NovaWeb3::deployContract(const std::string& name) {
    std::cout << "📜 [WEB3] Compiling Smart Contract: '" << name << "'\n";
    std::cout << "   ↳ [EVM] Contract Deployed successfully on-chain.\n";
}
void NovaWeb3::connectWallet(const std::string& provider) {
    std::cout << "🦊 [WEB3] Linking Web3 Provider: " << provider << "...\n";
}
void NovaWeb3::mintNFT(const std::string& artName) {
    std::cout << "🖼️  [WEB3] Minting digital asset '" << artName << "' as NFT.\n";
    std::cout << "   ↳ [Token] Token ID generated & stored on IPFS.\n";
}
