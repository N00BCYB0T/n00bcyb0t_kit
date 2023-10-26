#!/bin/bash

echo "Service to be started:"
read var
service $var restart
echo "Active services:"
ps aux | grep $var
echo "Open ports:"
netstat -nlpt
