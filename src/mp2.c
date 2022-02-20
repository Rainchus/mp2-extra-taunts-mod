#include "../include/mp2.h"

s16 characterVoiceBase[] = {
0x0FC, //despair 1 (c-right)
0x111, //despair 2 (c-left)
0x107, //good choice (c-down)
0x26C, //lose mini (c-up) [invalid id, change]
0x4B6, //taunt (L)
0x2C5, //super star (Z and (copied from existing mod, unused?))
0x102, //win mini (dpad right)
0x10A, //win star (dpad left)
0x275, //win item (dpad down) [invalid id, change]
0x10E, //win game (dpad up)
};

s16 tauntButtonsArray[] = {
R_CBUTTONS, //despair 1 (c-right)
L_CBUTTONS, //despair 2 (c-left)
D_CBUTTONS, //good choice (c-down)
U_CBUTTONS, //lose mini (c-up)
L_TRIG, //taunt (L)
(Z_TRIG & L_TRIG), //super star (Z and L (copied from existing mod, unused?))
R_JPAD, //win mini (dpad right)
L_JPAD, //win star (dpad left)
D_JPAD, //win item (dpad down)
U_JPAD, //win game (dpad up)
};

playerMain* getPlayerStructCustom(s32 playerIndex) { //same as `GetPlayerStruct` just loaded into ram from boot sooner
	return (playerMain*)0x800FD2C0 + playerIndex;
}

void checkPlayerTaunt(s32 playerIndex) { //check if current player in loop should taunt
	playerMain* player = getPlayerStructCustom(playerIndex);
	if (!(player->flags & 1)) { //if player is not cpu
		s16 currentVoiceOffset = -1;
		if ((PlayerPressedButtonsArray[player->controller_port] & 0xFFFFFFFF) != 0) { //player has pressed *something*, check what
			for (s32 j = 0; j < sizeof(tauntButtonsArray) / sizeof(s16); j++) { //check what button was pressed
				if (PlayerPressedButtonsArray[player->controller_port] == tauntButtonsArray[j]) {
					currentVoiceOffset = j;
					break;
				} else {
					currentVoiceOffset = -1;
				}
			}

			if (currentVoiceOffset != -1) {
				PlaySound(characterVoiceBase[currentVoiceOffset] + player->characterID);
			}
		}
	}
}

void playerTauntsMain() {
	if (globalTaunt == 1) {
		for (s32 i = 0; i < 4; i++) { //iterate over 4 players
			checkPlayerTaunt(i);
		}
	} else {
		if (canTauntDuringYourTurn == 1) {
			for (s32 i = 0; i < 4; i++) { //iterate over 4 players
				checkPlayerTaunt(i);
			}
		} else {
			for (s32 i = 0; i < 4; i++) { //iterate over 4 players
				if (GetCurrentPlayerIndex() != i) { //if not current player
					checkPlayerTaunt(i);
				}
			}
		}
	}
}

void mainCFunction() {
	playerTauntsMain();
}

