#!/usr/bin/python
import socket, sys

ip = sys.argv[1]
porta = int(sys.argv[2])

meu_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Jogar o resultado para uma variável para verificação
resp = meu_socket.connect_ex((ip, porta))

if (resp == 0):
    print("Porta Aberta")
else:
    print("Porta Fechada")

