#!/bin/bash

if [ "$1" = ""]
      	then
      		echo "Zone Transfer Script"
    		echo "usage - ./zone_transfer <domain>"
else
	for server in $(host -t ns $1 | cut -d " " -f4);
	do 
		host -l -a $1 $server;
	done;
fi

