#!/bin/bash
if [ "$1" == "" ]
then
	echo "PORTSCAN TOOL"
	echo "usage - $0 <ip address> <tcp port>"
	echo "e.g: $0 172.16.1 80"
else
	for host in {1..254}
	do
		hping3 -S -p $2 -c 1 $1.$host 2> /dev/null | grep "flags=SA"| cut -d " " -f 2 | sed 's/ip=//';
	done
fi