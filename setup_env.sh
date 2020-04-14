#!/bin/sh

# install x86 (32bit) libs (For 64bit host computers only) and bison
sudo apt-get update
sudo apt-get install -y gcc-multilib bison

# prepare variables
COMPILER_DIRNAME="compiler"
SDK="openwrt-sdk-19.07.2-ramips-mt76x8_gcc-7.5.0_musl.Linux-x86_64"
SDK_ZIP="${SDK}.tar.xz"
SDK_URL="https://downloads.openwrt.org/releases/19.07.2/targets/ramips/mt76x8/$SDK_ZIP"
TOOLCHAIN="toolchain-mipsel_24kc_gcc-7.5.0_musl"

# prepare sdk
rm -rf $COMPILER_DIRNAME
mkdir $COMPILER_DIRNAME
wget -P $COMPILER_DIRNAME $SDK_URL
cd $COMPILER_DIRNAME
tar -xvf $SDK_ZIP

# add path
cd $SDK/staging_dir/$TOOLCHAIN/bin
export PATH=`pwd`:$PATH

# config cross compiler 
CROSS_COMPILE=mipsel-openwrt-linux-musl-
export CROSS_COMPILE

# set staging dir
cd -
STAGING_DIR=`pwd`/$SDK/staging_dir
export STAGING_DIR

cd ..
