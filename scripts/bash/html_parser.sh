#!/bin/bash
if [ "$1" ==  "" ]
then
  echo -e "\e[32m+===========================================================+\e[0m"
  echo -e "\e[35m                    HTML PARSER TOOL\e[0m"
  echo -e "\e[32m+===========================================================+\e[0m"
  echo -e "\e[37m        usage: ./$0 <domain name>\e[0m"
  echo -e "\e[37m          e.g: ./$0 www.businesscorp.com.br\e[0m"
  echo -e "\e[32m+===========================================================+\e[0m"
else
  echo -e "\e[32m+===========================================================+\e[0m"
  echo -e "\e[35m                    HTML PARSER TOOL\e[0m"
  echo -e "\e[32m+===========================================================+\e[0m"
  echo -e "\e[35m              Downloading... index.html\e[0m"
  wget $1 2>/dev/null
  grep "href" index.html | cut -d "/" -f3 | grep "\." | cut -d '"' -f1 | egrep -v ",|link" | sort -u >> list 
  echo -e "\e[32m+===========================================================+\e[0m"
  echo -e "\e[37m                        Looking...\e[0m" 
  for url in $(cat list);
  do
    host $url | grep "has address" | sed 's/has address//'  >> ip_list;
  done
  echo -e "\e[35m                      [+] Report [+]\e[0m"
cat ip_list
rm index.html list ip_list
fi
