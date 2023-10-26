#!/bin/bash
if [ "$1" == "" ]
then
	echo "METAFIND"
	echo "usage - ./metafind.sh <domain> <filetype/extension>"
	echo "e.g: ./metafind.sh www.businesscorp.com.br pdf"
else
	ALVO=$1
	EXT=$2

	echo "Pesquisando por arquivos $EXT no domínio $ALVO"
	lynx --dump "https://google.com/search?&q=site:$ALVO+ext:$EXT" | grep ".$EXT" | cut -d "=" -f2 | egrep -v "site|google|UTF" | sed 's/...$//' | grep \.$EXT > coleta 
	echo "Baixando arquivos"
	for url in $(cat coleta);
	do 
		wget -q $url;
	done

	echo "METADADOS ENCONTRADOS"
	exiftool *.$EXT
	rm *.$EXT coleta
fi
