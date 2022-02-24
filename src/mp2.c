#include "../include/mp2.h"

//mario happy1 0xF5
//mario sad1 0xFC
//mario happy2 0x103
//mario happy3 0x10A (got star?)
//mario sad2 0x111
//mario happy4 0x118 (same as 0xf9)

s16 characterVoiceBase[] = {
	0x10A, //win mini (dpad up)
	0x103, //good choice (dpad right)
	0x0FC, //despair 1 (dpad-left)
	0x111, //despair 2 (dpad-down)
	0x4B6, //taunt (L)
};

s16 tauntButtonsArray[] = {
	U_JPAD, //win game (dpad up)
	R_JPAD, //win mini (dpad right)
	L_JPAD, //win star (dpad left)
	D_JPAD, //win item (dpad down)
	L_TRIG, //taunt (L)
};

void updateCustomPlayerPressedButtons(void) {
    s16 buttonsTemp;

	if (!(p1OSContStatus.status & 0x80)) {//controller is plugged in, update variables
		p1HeldButtonsPrevious = p1HeldButtonsCurrent;
		p1HeldButtonsCurrent = p1OSContPad.button;
		buttonsTemp = p1HeldButtonsCurrent & p1HeldButtonsPrevious;
		p1PressedButtons = buttonsTemp ^ p1HeldButtonsCurrent;
	}


	if (!(p2OSContStatus.status & 0x80)) { //controller is plugged in, update variables
		p2HeldButtonsPrevious = p2HeldButtonsCurrent;
		p2HeldButtonsCurrent = p2OSContPad.button;
		buttonsTemp = p2HeldButtonsCurrent & p2HeldButtonsPrevious;
		p2PressedButtons = buttonsTemp ^ p2HeldButtonsCurrent;
	}

	if (!(p3OSContStatus.status & 0x80)) { //controller is plugged in, update variables
		p3HeldButtonsPrevious = p3HeldButtonsCurrent;
		p3HeldButtonsCurrent = p3OSContPad.button;
		buttonsTemp = p3HeldButtonsCurrent & p3HeldButtonsPrevious;
		p3PressedButtons = buttonsTemp ^ p3HeldButtonsCurrent;
	}

	if (!(p4OSContStatus.status & 0x80)) { //controller is plugged in, update variables
		p4HeldButtonsPrevious = p4HeldButtonsCurrent;
		p4HeldButtonsCurrent = p4OSContPad.button;
		buttonsTemp = p4HeldButtonsCurrent & p4HeldButtonsPrevious;
		p4PressedButtons = buttonsTemp ^ p4HeldButtonsCurrent;
	}
}


playerMain* getPlayerStructCustom(s32 playerIndex) { //same as `GetPlayerStruct` just loaded into ram from boot sooner
	return (playerMain*)0x800FD2C0 + playerIndex;
}

void checkPlayerTaunt(s32 playerIndex) { //check if current player in loop should taunt
	playerMain* player = getPlayerStructCustom(playerIndex);
	if (!(player->flags & 1)) { //if player is not cpu
		s16 currentVoiceOffset = -1;
		if ((playerPressedButtonsArrayCustom[player->controller_port] & 0xFFFFFFFF) != 0) { //player has pressed *something*, check what
			for (s32 j = 0; j < sizeof(tauntButtonsArray) / sizeof(s16); j++) { //check what button was pressed
				if (playerPressedButtonsArrayCustom[player->controller_port] == tauntButtonsArray[j]) {
					currentVoiceOffset = j;
					break;
				} else {
					currentVoiceOffset = -1;
				}
			}

			if (currentVoiceOffset != -1) {
				if (tauntButtonsArray[currentVoiceOffset] == 0x4B6) {
					//PlaySoundInternal((characterVoiceBase[currentVoiceOffset] + player->characterID), 0);
					anotherSoundFunction(characterVoiceBase[currentVoiceOffset], playerIndex);
				} else {
					PlaySound(characterVoiceBase[currentVoiceOffset] + player->characterID);
				}
				
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
	//globalTaunt = 1;
	//canTauntDuringYourTurn = 1;
	updateCustomPlayerPressedButtons();
	playerTauntsMain();
}

