#!/bin/sh

## script to build bootloader binaries for:
##  Omega2  - 64MB DRAM = 512Mb
##  Omega2+ - 128MB DRAM = 1024Mb

CONFIG=".config"
BIN="uboot.bin"
DATE=`date +%Y%m%d`

# disable all dram components
resetDramSelection () {
    sed -i "s/ON_BOARD_\(.*\)_DRAM_COMPONENT=y/\# ON_BOARD_\1_DRAM_COMPONENT is not set/" $CONFIG    
}

# set a specific dram component
#   $1 - Mb of DRAM
setDramSelection () {
    sed -i "s/\# ON_BOARD_${1}M_DRAM_COMPONENT is not set/ON_BOARD_${1}M_DRAM_COMPONENT=y/" $CONFIG    
}

# build bootloader binary for specific 
#   $1 - device name
#   $2 - device DRAM in Mb
buildBinary () {
    local device="$1"
    local dram="$2"
    make clean 
    
    # make DRAM selection
    resetDramSelection
    setDramSelection "$dram"
    
    # apply the new config
    (
    	echo x
    	echo y
    ) | make menuconfig
    
    # build and rename the image
    make
    mv $BIN "uboot-${device}-${DATE}.bin"
}

# main program
buildBinary "omega2" "512"
buildBinary "omega2p" "1024"

echo "> Done"