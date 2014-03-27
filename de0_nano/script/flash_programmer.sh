#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: C:\Users\gdhunter\Documents\Capstone\ECE492\de0_nano\output_files\de0_nano_system.sof to: "..\flash/de0_nano_system_epcs_flash_controller.flash"
#
sof2flash --input="C:/Users/gdhunter/Documents/Capstone/ECE492/de0_nano/output_files/de0_nano_system.sof" --output="../flash/de0_nano_system_epcs_flash_controller.flash" --epcs --verbose 

#
# Programming File: "..\flash/de0_nano_system_epcs_flash_controller.flash" To Device: epcs_flash_controller
#
nios2-flash-programmer "../flash/de0_nano_system_epcs_flash_controller.flash" --base=0x4001000 --epcs --sidp=0x4002088 --id=0x0 --timestamp=1395955852 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose --erase-all 

#
# Converting ELF File: C:\Users\gdhunter\Documents\Capstone\ECE492\de0_nano\software\gesture_rover\gesture_rover.elf to: "..\flash/gesture_rover_epcs_flash_controller.flash"
#
elf2flash --input="C:/Users/gdhunter/Documents/Capstone/ECE492/de0_nano/software/gesture_rover/gesture_rover.elf" --output="../flash/gesture_rover_epcs_flash_controller.flash" --epcs --after="../flash/de0_nano_system_epcs_flash_controller.flash" --verbose 

#
# Programming File: "..\flash/gesture_rover_epcs_flash_controller.flash" To Device: epcs_flash_controller
#
nios2-flash-programmer "../flash/gesture_rover_epcs_flash_controller.flash" --base=0x4001000 --epcs --sidp=0x4002088 --id=0x0 --timestamp=1395955852 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

