#!/usr/bin/python3
import urllib.request, sys

site = urllib.request.urlopen(sys.argv[1])
info = site.info()

print("O servidor WEB está rodando")
print(info['Server'])
