let selectedOS = "";
function selectOS(os) {
    selectedOS = os;
    document.getElementById('step-1').classList.replace('active', 'hidden');
    setTimeout(() => { document.getElementById('step-2').classList.replace('hidden', 'active'); }, 300);
}
function selectIDE(ide) {
    document.getElementById('step-2').classList.replace('active', 'hidden');
    let cmd = selectedOS === 'Windows' 
        ? `iwr -useb https://nova.neurastudio.com/install.ps1 | iex` 
        : `curl -sL https://nova.neurastudio.com/install.sh | bash`;
    document.getElementById('final-command').innerText = cmd;
    setTimeout(() => { document.getElementById('step-3').classList.replace('hidden', 'active'); }, 300);
}
function copyCommand() {
    navigator.clipboard.writeText(document.getElementById('final-command').innerText);
    alert("Copied to clipboard!");
}
