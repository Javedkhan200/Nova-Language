// Terminal Typing Animation
const terminalText = [
    "Nova.os.start('Nova Engine')",
    "Nova.import('python:tensorflow')",
    "Nova.ai.think('Quantum Architecture')",
    "System Ready. God-Mode Activated."
];
let textIndex = 0;
let charIndex = 0;
const typewriter = document.getElementById('typewriter');

function type() {
    if (charIndex < terminalText[textIndex].length) {
        typewriter.textContent += terminalText[textIndex].charAt(charIndex);
        charIndex++;
        setTimeout(type, 50);
    } else {
        setTimeout(erase, 2000);
    }
}

function erase() {
    if (charIndex > 0) {
        typewriter.textContent = terminalText[textIndex].substring(0, charIndex - 1);
        charIndex--;
        setTimeout(erase, 25);
    } else {
        textIndex++;
        if (textIndex >= terminalText.length) textIndex = 0;
        setTimeout(type, 500);
    }
}
document.addEventListener("DOMContentLoaded", () => { setTimeout(type, 1000); });

// Installer Logic
let selectedOS = "";
let selectedIDE = "";

function selectOS(os, iconClass) {
    selectedOS = os;
    document.getElementById('step-1').classList.replace('active', 'hidden');
    setTimeout(() => {
        document.getElementById('selected-os-display').innerHTML = `Selected OS: <i class="${iconClass}"></i> ${os} <br><br> 2. Select Target IDE`;
        document.getElementById('step-2').classList.replace('hidden', 'active');
    }, 300);
}

function selectIDE(ide) {
    selectedIDE = ide;
    document.getElementById('step-2').classList.replace('active', 'hidden');
    
    let cmd = "";
    let osLower = selectedOS.toLowerCase();
    
    if(selectedOS === 'Windows') {
        cmd = `iwr -useb https://nova.neurastudio.com/install.ps1 | Invoke-Expression`;
    } else {
        cmd = `curl -sL https://nova.neurastudio.com/install.sh | bash`;
    }

    // Append IDE config flags
    if(ide === 'VS Code') cmd += " --setup-vscode";
    if(ide === 'PyCharm') cmd += " --setup-pycharm";

    document.getElementById('final-command').innerText = cmd;
    
    setTimeout(() => {
        document.getElementById('step-3').classList.replace('hidden', 'active');
    }, 300);
}

function copyCommand() {
    const text = document.getElementById('final-command').innerText;
    navigator.clipboard.writeText(text);
    const btn = document.querySelector('.copy-btn');
    btn.innerHTML = '<i class="fa-solid fa-check"></i> Copied!';
    btn.style.color = "#3fb950";
    setTimeout(() => {
        btn.innerHTML = '<i class="fa-solid fa-copy"></i> Copy';
        btn.style.color = "#c9d1d9";
    }, 2000);
}

function resetInstaller() {
    document.getElementById('step-3').classList.replace('active', 'hidden');
    setTimeout(() => {
        document.getElementById('step-1').classList.replace('hidden', 'active');
    }, 300);
}
