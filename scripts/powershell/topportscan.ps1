param($ip)
if(!$ip) {
	echo "PORTSCANNER"
	echo ".\portscan.ps1 192.168.0.1 80"
}else{
	$topports = 21,22,3306,80,443
	try{
		foreach ($porta in $topports){
			if(Test-NetConnection $ip -Port $porta -WarningAction silentlyContinue -InformationLevel Quiet){
				echo "Porta $porta Aberta"
			}
		}else{
			echo "Porta $porta Fechada"
		}
	} catch{}
}