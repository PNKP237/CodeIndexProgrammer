# DISCLAIMER: THERE IS NO WARRANTY TO THIS CODE. EVERYTHING YOU DO IS ON YOUR OWN VOLITION AND I'M NOT RESPONSIBLE FOR WHATEVER COULD GO WRONG - BE IT YOUR WIRING, YOUR CHARGER/POWERBANK/PC FAILING OR YOUR VEHICLE GOING UP IN FLAMES.

# CodeIndexProgrammer

This Arduino sketch can be used to enable the Aux input in your CD70 Navi or DVD90 Navi headunit by simply flashing the headunit's Code Index to 01201. The only required hardware is an ESP32 and a CAN transceiver of any kind (which you can later repurpose to put together EHU32). No need for OP-COM!

Note that this requires your headunit to be running 10.10.2007 or 20.06.2008 version of Navi software in order to perform the Code Index update. Can't share the CD image with you here, but I'm sure you can find it somewhere on the internet. Use ImgBurn on windows to burn a CD-R with that image, remember to force the lowest writing speed of the compact disc - anything over 10x WILL brick your headunit, but set it to 1x just to be sure. Insert the burned CD-R into the Navi slot and wait patiently - don't attempt to start the engine or stop it if it's already running.

You also need to solder several additional components to the headunit's PCB in order to make use of the Auxiliary audio input, please refer to my guides on EHU32 wiki page. If all you hear after switching to Aux are repeated pops, you're lacking these components on the headunit's motherboard.

## Usage:
- flash your ESP32 board as per instructions in the [Github Releases](https://github.com/PNKP237/CodeIndexProgrammer/releases)
- wire up the [ESP32 with a CAN transceiver of choice](https://github.com/PNKP237/EHU32/blob/main/EHU32_wiring.pdf) (for example MCP2551, just be vary of the input voltage)
- make sure your radio is turned off
- wire up your CAN transceiver up to the OBD-II port in your radio - pin 3 is for CAN-H while pin 11 is for CAN-L
- start up the headunit, afterwards press RESET on the ESP32 board
- if you hear a BONG then you're ready to go - press 7 for about 2 seconds until you hear a second BONG
- once you hear another BONG press 7 for another 2 seconds, this will dump the currently used Code Index over serial to your PC at 921600 baud - use that if you want to backup the current Code Index for whatever reason. Once this is complete you will hear yet another BONG
- now you're ready to flash the Code Index by holding 9 for about two seconds
- your headunit will now restart and Aux input should be available in the "Audio" menu. Enjoy!
