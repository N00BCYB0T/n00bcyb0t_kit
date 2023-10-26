#!/usr/bin/python3

import socket, sys, os

ip = sys.argv[1]

sock_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
os.system("clear")
for port in range(1, 255):
    resp = sock_fd.connect_ex((ip, port))

    if (resp == 0):
        print("%d - Open"%port)
        sock_fd.close()
    else:
        print("%d - Closed"%port)
