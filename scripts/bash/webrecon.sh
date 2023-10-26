#!/bin/bash
for palavra in $(cat $2)
do
	resposta_file=$(curl -s -H "$4" -o /dev/null -w "%{http_code}" $1/$palavra.$3)
	resposta_dir=$(curl -s -H "$4" -o /dev/null -w "%{http_code}" $1/$palavra/) #Utilizamos a barra para declarar que estamos buscando por diretório.
	if [ $resposta_file == "200" ] 
	then
		echo "Arquivo encontrador: $1/$palavra.$3"
	fi

	if [ $resposta_dir == "200" ]
	then
		echo "Diretório encontrado: $1/$palavra/"
	fi
done


