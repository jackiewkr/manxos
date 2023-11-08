# ManxOS

ManxOS is an operating system built for me to understand the inner workings
of an operating system better and to further my knowledge of C and asm.
This is currently a clone of the meaty-skeleton tutorial on the OSDev wiki.

The operating system aims to be terminal-based with the ability to run 
simple programs.

## How to Build
In order to build, you must already have a cross-compiler for i386/i686 in your
path. Follow the procedure here from the [OSDev Wiki](https://wiki.osdev.org/GCC_Cross-Compiler).

Dependencies:
 - GRUB
 - Xorriso
 - QEMU

The build system is shell-script based for the moment.
 - `clean.sh` to clean the source tree. 
 - `headers.sh` to move the system headers into the sysroot
 - `iso.sh` to build the kernel into an executable ISO image with GRUB.
 - `qemu.sh` to run the ISO in a VM.
