# Coragem

This repository aims to support software development using the Coragem board and MBED.

The file mbed_app.json in the root directory is used to create a program in MBED that will be write in Coragem through nRF52840_DK, Ulink, Jlink or other device.

The Path DFU (Device Firmware Update) gives suport fot using the Firmware update OTA (Over the air).
The file boot_soft_dfu.hex needs to be write on Coragem to it start to run DFU mode.
The file dfu_public_keys is used to generate a packet with nrfutil.
The command below is an example to create the packet to be write using DFU.
nrfutil pkg generate --application aplication_name.hex --application-version 1 --hw-version 52 --sd-req 0xB6 --key-file dfu_public_key.pem output_name.zip
The file coragem_systick.zip is an example of a package created with the above command.
