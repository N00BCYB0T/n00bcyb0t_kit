#!/usr/bin/python
import socket

print("Interagindo com o FTP Server")

ip = input("IP: ")
port = 21

sock_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock_fd.connect((ip, port))
banner = sock_fd.recv(1024)
print(banner.decode())

print("Enviando usuário")
msg = "USER carlos\r\n"
sock_fd.send(msg.encode())
banner = sock_fd.recv(1024)

print("Enviando senha")
msg = "PASS pass@123"
sock_fd.send(msg.encode())
banner = sock_fd.recv(1024)
print(banner)
