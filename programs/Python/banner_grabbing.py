#!/usr/bin/python

import socket, sys

ip = sys.argv[1]
port = int(sys.argv[2])

sock_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock_fd.connect((ip, port))
banner = sock_fd.recv(1024)
print(banner)

