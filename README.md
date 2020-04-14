# Omega2 Bootloader

Based on [u-boot](https://github.com/u-boot/u-boot) v2020.04 release. See [original u-boot readme](./README) for more details.

## Setup Build Environment

Install dependencies and the MIPS cross compiler:

```
. setup_env.sh
```

## Build the Bootloader

Configure profile: (TODO: need to make a profile for Omega2 Boards)

```
make linkit-smart-7688_defconfig
```

Build

```
make
```

Output will be `u-boot.bin`