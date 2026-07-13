let selectedOS = "";
let selectedIDE = "";

function selectOS(os, iconClass) {
    selectedOS = os;
    document.getElementById('step-1').classList.add('hidden');
    document.getElementById('step-1').classList.remove('active');
    
    document.getElementById('selected-os-title').innerHTML = `Selected: <i class="${iconClass}"></i> ${os}`;
    
    document.getElementById('step-2').classList.remove('hidden');
    document.getElementById('step-2').classList.add('active');
}

function selectIDE(ide) {
    selectedIDE = ide;
    document.getElementById('step-2').classList.add('hidden');
    document.getElementById('step-2').classList.remove('active');
    
    let cmd = "";
    let osLower = selectedOS.toLowerCase();
    let ideLower = selectedIDE.toLowerCase().replace(' ', '');
    
    cmd = `curl -sL https://get.neurastudio.com/nova?os=${osLower}&target=${ideLower} | bash`;
    if(selectedOS === 'Windows') {
        cmd = `iwr -useb https://get.neurastudio.com/nova.ps1 | Invoke-Expression`;
    }

    document.getElementById('install-command').innerText = cmd;
    
    document.getElementById('step-3').classList.remove('hidden');
    document.getElementById('step-3').classList.add('active');
}

function copyCmd() {
    const text = document.getElementById('install-command').innerText;
    navigator.clipboard.writeText(text);
    alert("Command copied! Paste it in your terminal.");
}

function resetInstaller() {
    selectedOS = ""; selectedIDE = "";
    document.getElementById('step-3').classList.add('hidden');
    document.getElementById('step-3').classList.remove('active');
    document.getElementById('step-1').classList.remove('hidden');
    document.getElementById('step-1').classList.add('active');
}
