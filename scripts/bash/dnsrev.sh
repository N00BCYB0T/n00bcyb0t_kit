#!/bin/bash

if [ "$1" == "" ]
then
	echo "DNS-Rev"
	echo "usage - $0 <ip address> <min> <max>"
      	echo "e.g: $0 37.59.174 224 239"
else
	for ip in $(seq $2 $3);do
		host -t ptr $1.$ip | egrep -v "$1|NXDOMAIN" 
	done
fi

