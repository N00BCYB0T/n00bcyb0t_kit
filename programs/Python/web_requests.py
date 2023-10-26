#!/usr/bin/python3
import requests, sys

site = requests.get(sys.argv[1])
status = site.status_code

if (status == 200):
    print("Página Existente")
else:
    print("Página Inexistente")

