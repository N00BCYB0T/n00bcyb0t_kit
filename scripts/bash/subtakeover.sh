#!/bin/bash

if [ "$1" == "" ]
then
	echo "Subdomain TAKEOVER"
	echo "usage - $0 <domain> <list.txt>"
	echo "e.g: $0 dev.businesscorp.com"
else
	for palavra in $(cat $2);
	do
		host -t cname $palavra.$1 | grep "alias for" 
	done
fi
