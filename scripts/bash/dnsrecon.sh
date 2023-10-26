#!/bin/bash

if [ "$1" == "" ]
then
	echo "DNS Recon"
	echo "usage - $0 <domain> <list.txt>"
	echo "e.g: $0 businesscorp.com list.txt"
else
	for palavra in $(cat $2);
	do
		host $palavra.$1 | grep -v "NXDOMAIN"
	done
fi
