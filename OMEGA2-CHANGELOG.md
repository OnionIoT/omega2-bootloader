# Omega2 Bootloader Changelog

Log of changes made to the Onion Omega2 Bootloader

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
