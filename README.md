# Boot sector test
Minimal boot sector program that I created when learning the boot process of x86 system.

The boot.txt file contains the x86 opcodes in a format that can be easily edited. t2b.c converts the text format to a binary file (boot.bin).

A bootable USB drive can be created using dd program:
    sudo dd if=path/to/boot.bin of=/path/to/the/usb/device bs=512 count=1

## Boot program
Opcodes:
    b4 0e
    b0 3a
    cd 10
    b0 29
    cd 10
    f4

In assembly:
    mov    ah,0xe    // Set output type
    mov    al,0x3a   // Set ':' to 'al' register
    int    0x10      // print the character in 'al' register
    mov    al,0x29   // Set ')' to 'al' register
    int    0x10      // print the character in 'al' register
    hlt              // Halt the cpu

In order to boot the program in BIOS a boot sector signature must be placed in the end of the file. Therefore, the last two bytes must be 0x55 and 0xaa.
The rest of the file is zeroed out so that the total size is exactly 512MB which is the size of a boot sector that is loaded into RAM for execution.

The program should print ':)' to the screen and halt.
