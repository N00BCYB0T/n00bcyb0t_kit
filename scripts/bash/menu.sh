#!/bin/bash
echo "Lista de comandos"
echo "0 - Verificar interfaces de rede"
echo "1 - Verificar processos"
echo "2 - Verificar serviços"
echo "3 - Verificar rede interna"
read resp
case $resp in
"0")
  ifconfig
;;
"1")
  ps -aux
;;
"2")
  netstat -nlpt
;;
"3")
  ip a
;;
esac
