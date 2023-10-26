import os, sys

if (sys.argv[1] == ""):
    print("Zone-Transfer Script")
    print("usage - python zone_transfer.py <domain>")
else:
    servers = os.system("host -t ns " + sys.argv[1] + " | cut - d " " -f4")
    print(servers)
    for server in servers:
        os.system("host -l -a " + sys.argv[1] + " " + server)


