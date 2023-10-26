#!/bin/bash
if [ "$1" == "" ] 
then
  echo "PING SWEEP TOOL"
  echo "usage - ./pingnet.sh <network>"
  echo "e.g: ./pingnet.sh 192.168.0"
else
  for host in {1..254};
  do
    ping -c 1 $1.$host | grep "64 bytes" | cut -d " " -f 4 | sed 's/.$//'
  done
fi
