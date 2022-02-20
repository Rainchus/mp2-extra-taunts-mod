/*
Here we create declarations for a few functions and variables in Mario Party 2 so they can be referenced from our C code.
Later we will tell armips their addresses by defining labels for them in mp2.asm.
*/

#define NULL 0

/* Buttons */

#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G	    0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001

/* Nintendo's official button names */

#define A_BUTTON	CONT_A
#define B_BUTTON	CONT_B
#define L_TRIG		CONT_L
#define R_TRIG		CONT_R
#define Z_TRIG		CONT_G
#define START_BUTTON	CONT_START
#define U_JPAD		CONT_UP
#define L_JPAD		CONT_LEFT
#define R_JPAD		CONT_RIGHT
#define D_JPAD		CONT_DOWN
#define U_CBUTTONS	CONT_E
#define L_CBUTTONS	CONT_C
#define R_CBUTTONS	CONT_F
#define D_CBUTTONS	CONT_D

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef char s8;
typedef unsigned char u8;

typedef struct {
/* 0x00 */ char unk_00; //unused?
/* 0x01 */ u8 cpu_difficulty;
/* 0x02 */ u8 cpu_difficulty2; //copied from 0x01 for some reason..?
/* 0x03 */ u8 controller_port;
/* 0x04 */ u8 characterID;
/* 0x05 */ char padding_05;
/* 0x06 */ s16 flags;
/* 0x08 */ s16 coins;
/* 0x0A */ s16 extra_coins_collected_during_minigame;
/* 0x0C */ s16 minigameCoinsWon; //coins won on current minigame, also stores battle placement briefly
/* 0x0E */ s16 stars;
/* 0x10 */ s16 cur_chain_index;
/* 0x12 */ s16 cur_space_index;
/* 0x14 */ s16 next_chain_index;
/* 0x16 */ s16 next_space_index;
/* 0x18 */ char unk_18;
/* 0x19 */ s8 item;
/* 0x1A */ s8 turn_status;
/* 0x1B */ s8 player_space_color; //(color for minigame dividing)
/* 0x1C */ char unk_1C[0x0C];
/* 0x28 */ s16 minigame_coins_collected;
/* 0x2A */ s16 coinPeak; //used for coin star
/* 0x2C */ u8 happening_spaces_landed_on;
/* 0x2D */ u8 red_spaces_landed_on;
/* 0x2E */ u8 blue_spaces_landed_on;
/* 0x2F */ u8 chance_spaces_landed_on;
/* 0x30 */ u8 bowser_spaces_landed_on;
/* 0x31 */ u8 battle_spaces_landed_on;
/* 0x32 */ u8 item_spaces_landed_on;
/* 0x33 */ u8 bank_spaces_landed_on;
} playerMain; //sizeof 0x34
//P1 - 800FD2C0
//P2 - 800FD2F4
//P3 - 800FD328
//P4 - 800FD35C

typedef struct OSContStatus {
    u16 type;
    u8 status;
    u8 errno;
} OSContStatus;

typedef struct OSContPad {
    u16 button;
    s8 stick_x;
    s8 stick_y;
    u8 errno;
} OSContPad;


//data
extern OSContStatus p1OSContStatus;
extern OSContPad p1OSContPad;

extern OSContStatus p2OSContStatus;
extern OSContPad p2OSContPad;

extern OSContStatus p3OSContStatus;
extern OSContPad p3OSContPad;

extern OSContStatus p4OSContStatus;
extern OSContPad p4OSContPad;


extern s16 p1HeldButtonsPrevious;
extern s16 p1HeldButtonsCurrent;
extern s16 p1PressedButtons;

extern s16 p2HeldButtonsPrevious;
extern s16 p2HeldButtonsCurrent;
extern s16 p2PressedButtons;

extern s16 p3HeldButtonsPrevious;
extern s16 p3HeldButtonsCurrent;
extern s16 p3PressedButtons;

extern s16 p4HeldButtonsPrevious;
extern s16 p4HeldButtonsCurrent;
extern s16 p4PressedButtons;

extern s16 playerPressedButtonsArrayCustom[4];


extern s16 globalTaunt;
extern s16 canTauntDuringYourTurn;
extern s16  PlayerPressedButtonsArray[4]; //0x800C9520
extern s16	Player1Pressedbuttons;	//0x800C9520
extern s16	Player2Pressedbuttons;	//0x800C9522
extern s16	Player3Pressedbuttons;	//0x800C9524
extern s16	Player4Pressedbuttons;	//0x800C9526

//functions
extern s32 GetCurrentPlayerIndex(void);
extern playerMain* GetPlayerStruct(s32 playerIndex);
extern void PlaySound(s32 soundIndex);



