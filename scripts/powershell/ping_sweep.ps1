#PING SWEEP
param($p1)
if (!$p1){
	echo "PING SWEEP TOOL"
	echo "Exemplo de uso: .\ping_sweep.ps1 192.168.0"
}else{
	foreach ($ip in 1..254){
		try{
			#Similar ao: ping -c 1 $1.$host | grep "bytes-32" | cut -d " " -f 3 | sed 's/://'
			$resp = ping -n 1 "$p1.$ip" | Select-String "bytes=32"
			$resp.Line.split(" ")[2] -replace ":",""
		} catch {} #Interceptando os erros "Redirecionando a saída"
	}
}