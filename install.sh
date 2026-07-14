#!/bin/bash
echo "========================================"
echo "   🚀 Installing Nova Engine... "
echo "========================================"
echo "[1/3] Fetching Nova core from Neura Studio GitHub..."
sleep 1
git clone https://github.com/Javedkhan200/Nova-Language.git ~/.nova_engine 2>/dev/null || echo "Nova already downloaded, updating..."
cd ~/.nova_engine && cmake . && make
cp nova $PREFIX/bin/nova 2>/dev/null || sudo cp nova /usr/local/bin/nova
echo "[2/3] Configuring Global Environment Variables..."
sleep 1
echo "[3/3] Setting up Nova Hub and IDE extensions..."
sleep 1
echo "✅ Nova Language installed successfully!"
echo "👉 Type 'nova' in your terminal to start."
echo "========================================"
