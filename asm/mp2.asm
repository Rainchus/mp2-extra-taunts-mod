//data
.definelabel playerpressedbuttonsarray,	0x800F6098
.definelabel Player1Pressedbuttons,	0x800F6098
.definelabel Player2Pressedbuttons,	0x800F609A
.definelabel Player3Pressedbuttons,	0x800F609C
.definelabel Player4Pressedbuttons,	0x800F609E

.definelabel p1OSContStatus, 0x800F8F90
.definelabel p1OSContPad, 0x800F8F94

.definelabel p2OSContStatus, 0x800F8F98
.definelabel p2OSContPad, 0x800F8F9C

.definelabel p3OSContStatus, 0x800F8FA0
.definelabel p3OSContPad, 0x800F8FA4

.definelabel p4OSContStatus, 0x800F8FA8
.definelabel p4OSContPad, 0x800F8FAC


//custom data
.definelabel globalTaunt, 0x800BF900
.definelabel canTauntDuringYourTurn, 0x800BF902



.definelabel p1HeldButtonsPrevious, 0x800BF904
.definelabel p1HeldButtonsCurrent, 0x800BF906

.definelabel p2HeldButtonsPrevious, 0x800BF908
.definelabel p2HeldButtonsCurrent, 0x800BF90A

.definelabel p3HeldButtonsPrevious, 0x800BF90C
.definelabel p3HeldButtonsCurrent, 0x800BF90E

.definelabel p4HeldButtonsPrevious, 0x800BF910
.definelabel p4HeldButtonsCurrent, 0x800BF912

.definelabel playerPressedButtonsArrayCustom, 0x800BF914
.definelabel p1PressedButtons, 0x800BF914
.definelabel p2PressedButtons, 0x800BF916
.definelabel p3PressedButtons, 0x800BF918
.definelabel p4PressedButtons, 0x800BF91A


//functions
.definelabel GetCurrentPlayerIndex, 0x8005DC30
.definelabel GetPlayerStruct, 0x8005DC3C
.definelabel PlaySound, 0x80014B14