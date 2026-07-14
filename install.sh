#!/bin/bash
echo "========================================"
echo "   🚀 Installing Nova Engine... "
echo "========================================"

echo "[1/4] Installing required system dependencies (Clang, CMake, Make, Git)..."
pkg update -y
pkg install clang cmake make git -y

echo "[2/4] Fetching Nova core from Neura Studio GitHub..."
rm -rf ~/.nova_engine
git clone https://github.com/Javedkhan200/Nova-Language.git ~/.nova_engine

echo "[3/4] Compiling Nova Source Code (Bootstrapping)..."
cd ~/.nova_engine
cmake .
make

echo "[4/4] Setting up Global Environment..."
cp nova $PREFIX/bin/nova
chmod +x $PREFIX/bin/nova

echo "========================================"
echo "✅ Nova Language installed successfully!"
echo "👉 Type 'nova' anywhere in your terminal to start."
echo "========================================"
