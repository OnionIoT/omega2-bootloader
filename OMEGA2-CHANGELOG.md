# Omega2 Bootloader Changelog

Log of changes made to the Onion Omega2 Bootloader

* 2022-11-18
    * Updated write device MAC address command (from bootloader menu) to support new Onion MAC address range
* 2020-05-12
    * Fixed issue with flashing new firmware from USB by reducing bootloader binary size
* 2019-11-11
    * Added bootloader menu option to write device MAC Address to factory partition
        * Will write input MAC addr for ra0 interface, input + 1 for eth0, and input + 2 for apcli0
        * ![](./menu-write-mac-addr.jpg)
* 2019-10-17
    * GPIO2_MODE register now unchanged during init - all LED pins being left to default GPIO mode
      * Resolves issue where GPIOs 39-42 flap right after boot
* 2019-08-19
    * EPHY P1-P4 pins set to digital (no more random voltages during boot), while still keeping P0 as ethernet port
    * GPIO37 now works in gpio test
* ~~2019-04-12~~
    * ~~Fix to ensure EPHY P1-P4 pins are **always** set to Digital Pads - Resolves issues where these pins had fluctuating voltages during boot~~
    * Reverted this change - new setting was disabling all ethernet ports, resulted in web recovery mode not working
* 2019-03-01
    * Changed default setting: eth port0 LED to act as GPIO *Required for Omega2 Pro Amber System LED proper operation*
* 2019-01-25
    * Resolved USB flashing error by reducing bootloader binary size
    * Accomplished by refactoring gpio test function
* 2017-09-19
    * Initial bootloader release
