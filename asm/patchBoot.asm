/*
    DMA method (makes use of expansion pak)
    .headersize 0x7FFFF400
    .org 0x8000C2C0
    NOP

    //Payload related information
    .definelabel PAYLOAD_START_ROM, 0x983D0
    .definelabel PAYLOAD_START_RAM, 0x80400000
    .definelabel MP3_MOD_ROM, PAYLOAD_START_ROM + 0x1000
    .definelabel MP3_MOD_RAM, PAYLOAD_START_RAM + 0x1000

    .definelabel PAYLOAD_SIZE, 0x7F40

    PAYLOAD_START:
    .headersize 0x7FFFF400
    .org 0x8000C2C8
    LUI a0, hi(PAYLOAD_START_ROM)
    ADDIU a0, a0, lo(PAYLOAD_START_ROM)
    LUI a1, hi(PAYLOAD_START_RAM)
    ADDIU a1, a1, lo(PAYLOAD_START_RAM)
    JAL unknownDMAFunc
    ORI a2, r0, (PAYLOAD_SIZE)
    J originalCode
    NOP


    //.headersize 0x7F86E000 // Set the displacement between ROM and RAM addresses (0xB92000)
    .headersize (PAYLOAD_START_RAM - PAYLOAD_START_ROM)
    .org 0x80400000 //ct1.asm max size of 0x1000, otherwise will overwrite ct1.o
    originalCode:
    //insert hook
    LUI t1, hi(mainASMFunctionJump)
    LW t1, lo(mainASMFunctionJump) (t1)
    LUI t0, 0x8001
    SW t1, 0xE7F0 (t0) //store hook to 0x8000E7F0 (in main game loop)
    //restore code overwritten by dma hook
    LUI a0, 0x800D
    ADDIU a0, a0, 0xE1A0
    ADDU a1, r0, r0
    LUI a2, 0x800D
    ADDIU a2, a2, 0x0E50
    JAL 0x80072590
    ADDIU a3, r0, 0x0008

    BEQZ v0, jump1
    NOP
    J 0x8000C2E8
    NOP

    jump1:
    J 0x8000C2F0
    NOP




    mainASMFunctionJump:
    J mainASMFunction //instruction copied and used as a hook
    NOP

    .org 0x80400080
    mainASMFunction:
    JAL mainCFunction
    NOP
    J 0x8000E7C0
    NOP

    .headersize MP3_MOD_RAM - MP3_MOD_ROM
    .org MP3_MOD_RAM
    .align 8
    .importobj "obj/mp3.o"
*/

//Non DMA method (makes use of free ram space by unused font)
//.headersize 0x7FFFF400
//.org 0x8000C2C0
//NOP

.headersize 0x7FFFF400
.org 0x8001C880
J mainASMFunction //instruction copied and used as a hook
NOP

//ROM addr 0xC0510
.org 0x800BF910
mainASMFunction:
JAL mainCFunction
NOP
J 0x8001C870
NOP

.align 8
.importobj "obj/mp2.o"