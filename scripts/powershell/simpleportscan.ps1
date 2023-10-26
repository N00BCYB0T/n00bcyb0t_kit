param($ip,$porta)
if(!$ip -or !$porta) {
	echo "PORTSCANNER"
	echo ".\portscan.ps1 192.168.0.1 80"
}else{
	if(Test-NetConnection $ip -Port $porta -WarningAction silentlyContinue -InformationLevel Quiet){
		echo "Porta $porta Aberta"
	}else{
		echo "Porta $porta Fechada"
	}
}