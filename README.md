# mp2-extra-taunts-mod
MP2 more character taunts mod

You can set the following options with gameshark codes:<br>
800BF900 s16, if taunts are active globally bool<br>
800BF902 s16, if you can taunt when it's your turn on the board<br>
810BF900 00xx<br>
810BF902 00xx<br><br>

To apply mod to vanilla rom:<br>
Download flips (IPS patcher) and apply the .bps patch provided to a vanilla US mp2.z64 rom<br><br>

To build from source:<br>
Create a folder in the root of the project named `rom`<br>
Put a mario party 2 US rom in the folder with the name `mp2.z64`<br>
Run `build.bat` to build the modded rom<br>
The modded rom will output as `mp2mod.z64`
