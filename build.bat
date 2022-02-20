mkdir obj
mips64-elf-gcc -Wall -O2 -mtune=vr4300 -march=vr4300 -mabi=32 -fomit-frame-pointer -G0 -c src/mp2.c
mv mp2.o obj/
armips asm/main.asm
n64crc "rom/mp2mod.z64"