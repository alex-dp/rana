#!/bin/bash

g++ -o rana main.cpp
chmod 777 rana
sudo mv rana /usr/bin/
echo "Done - Rana was installed. type 'rana' to see it in action"
