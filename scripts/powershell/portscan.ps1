param($ip)
if(!$ip) {
	echo "PORTSCANNER"
	echo ".\portscan.ps1 192.168.0.1"
}else{
	foreach ($porta in 1..65535){
		if(Test-NetConnection $ip -Port $porta -WarningAction silentlyContinue -InformationLevel Quiet){
			echo "Porta $porta Aberta"
		}
	}
}