# U-Boot for Onion Omega2

## SETUP BUILD ENVIRONMENT

```
sh setup_env.sh
```
part of the setup is unpacking the MTK built tool. these tools reqire 32bit gcc libs.

## MEMORY MAPS AND BOARD CONFIGURATION
SoC spaicifc configuration are located in `/include/configs/rt2880.h`.
Web recovery tool can be configured with:
```
#define CONFIG_SERVERIP 192.168.8.1
#define CONFIG_IPADDR   192.168.8.8
#define CONFIG_ETHADDR "00:AA:BB:CC:DD:10"
```
Max uboot upload size can be configured with:
```
#define WEBFAILSAFE_UPLOAD_UBOOT_SIZE_IN_BYTES		( 1024 * 1024 )
```


## NOTE THAT YOU NEED A WIRE
(Only applies to early Omega2 sample firmware)
You need a wire connecting 3.3V pin and 2.5V pin to make the following code getting the WPS button state work
```
val=RALINK_REG(0xb0000624);
```

NOTE ON UBOOT PARTITION SIZE

In case you Omega2 already has a loader installed that supports only upto 128K in web update please switch off some functionality in config.mk that takes up lots of space, for example RALINK_EHCI and/or RALINK_OHCI (except the web update functionality obviously) in order to keep the size withing the limits, compile the limited functionality executable and burn that.

As this version supports up to 192k (don't push the limits) then you will be able to burn the whole complete thing as it is, usually >170k in size. Credits to Zheng Han for coming up with this procedure.


FILENAMES OF IMAGES

The usual name by convention for firmware images is
```
root_uImage
```

Support for files produced by the de facto official buildroot environment exist that will allow you to burn files without renaming them, provided they are named
```
lede-ramips-mt7688-Omega2-squashfs-sysupgrade.bin
```

The latter depends on USB support working perfectly always and that might prove an overconfident assumption. For more on that, see below


CAVEATS ABOUT USING USB STORAGE DEVICES

USB support in the current version is a bit temperamental, so USB sticks are supported at what the USB spec calls "High Speed" ("maximum transfer rate of 480 Mbit/s"), which is on the slower side of today's expectations, so be patient. Furthermore, after testing different sticks from different bottom shelf Chinese manufactures, it was revealed that not all (even Chinese brand name) work as expected. The general rule of thumb would be, keep it simple, the more complicated the USB storage device is, that is, more additional functionality your "U-Disk" has, the higher the chances something might go wrong. With this particular HUB controller timing issues such as communication timeouts, could be observed in the current version of the code that may cropping up in certain situations.


MISCELLANEOUS WEIRDNESS

Sometimes burning stalls and the process hangs. Oddly enough, the only common denominator seems to be the presence of symbol '6' in the string representation of the size of the executable. Thank GOD, it's not '666' :) If that happens to you, don't panic. Just add (or remove) some unimportant functionality, such as printouts for example, that will change the size, and chances are the process of burning will proceed as expected.  
