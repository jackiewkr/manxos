#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/manxos.kernel isodir/boot/manxos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "ManxOS" {
	multiboot /boot/manxos.kernel
}
EOF
grub-mkrescue -o manxos.iso isodir
