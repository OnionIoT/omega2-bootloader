#!/bin/bash

cd tools
sudo tar xvfj buildroot-gcc342.tar.bz2 -C /opt/


# install x86 (32bit) libs
sudo apt-get update
sudo apt-get install gcc-multilib
