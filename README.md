![](header.png?raw=true)
# **SUPPORT THE OFFICIAL RELEASE OF SONIC 1 & SONIC 2**
+ Without assets from the official releases this decompilation will not run.
+ Video tutorial on how to find your legally obtained Data.rsdk file: https://www.youtube.com/watch?v=gzIfRW91IxE

+ You can get the official release of Sonic 1 & Sonic 2 from:
  * [Sonic 1 (iOS, Via the App Store)](https://apps.apple.com/au/app/sonic-the-hedgehog-classic/id316050001)
  * [Sonic 2 (iOS, Via the App Store)](https://apps.apple.com/au/app/sonic-the-hedgehog-2-classic/id347415188)
  * [Sonic 1 (Android, Via Google Play)](https://play.google.com/store/apps/details?id=com.sega.sonic1px&hl=en_AU&gl=US)
  * [Sonic 2 (Android, Via Google Play)](https://play.google.com/store/apps/details?id=com.sega.sonic2.runner&hl=en_AU&gl=US)
  * [Sonic 1 (Android, Via Amazon)](https://www.amazon.com.au/Sega-of-America-Sonic-Hedgehog/dp/B00D74DVKM)
  * [Sonic 2 (Android, Via Amazon)](https://www.amazon.com.au/Sega-of-America-Sonic-Hedgehog/dp/B00HAPRVWS)

Even if your platform isn't supported by the official releases, you **must** buy it for the assets (you don't need to run the official release, you just need the game assets)

If you want to transfer your save from the official mobile versions, the **Android pre-forever** file path is `Android/data/com.sega.sonic1 or 2/SGame.bin` (other versions may have different file paths). Copy that file to the `SData.bin` in the EXE folder.

# Additional Tweaks
* Added a built in script compiler. Similar to the one found in RSDKv3, but tweaked up to match the new syntax for the scripts used in RSDKv4.
* Added a built in mod loader and API allowing to easily create and play mods with features such as save file redirection, custom achievements and XML GameConfig/StageConfig data.
* Custom menu and networking system for Sonic 2 multiplayer, allowing anyone to host and join servers and play 2P VS.
* There is now a `settings.ini` file that the game uses to load all settings, similar to Sonic Mania.
* Dev menu can now be accessed from anywhere by pressing the `ESC` key if enabled in the config.
* The `F12` pause, `F11` step over & fast forward debug features from Sonic Mania have all been ported and are enabled if `devMenu` is enabled in the config.
* If `devMenu` is enabled in the config, pressing `F9` will visualize hitboxes, and `F10` will activate a palette overlay that shows the game's 8 internal palettes in real time.
* Added the idle screen dimming feature from Sonic Mania Plus, as well as allowing the user to disable it or set how long it takes for the screen to dim.
* DISCORD RPC SUPPORT

# How to build:
## Windows:
* Clone the repo, then follow the instructions in the [depencencies readme for Windows](./dependencies/windows/dependencies.txt) to setup dependencies, then build via the visual studio solution
* or grab a prebuilt executable from the releases section

## Windows via MSYS2 (64-bit Only):
### Decompilation
* Download the newest version of the MSYS2 installer from [here](https://www.msys2.org/) and install it.
* Run the MINGW64 prompt (from the windows Start Menu/MSYS2 64-bit/MSYS2 MinGW 64-bit), when the program starts enter `pacman -Syuu` in the prompt and hit Enter. Press `Y` when it asks if you want to update packages. If it asks you to close the prompt, do so, then restart it and run the same command again. This updates the packages to their latest versions.
* Now install the dependencies with the following command: `pacman -S make git mingw-w64-i686-gcc mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2 mingw-w64-x86_64-libogg mingw-w64-x86_64-libvorbis mingw-w64-x86_64-glew`
* Clone the repo with the following command: `git clone https://github.com/mrneptune64/RSDKv4N.git`
* Go into the repo you just cloned with `cd RSDKv4N`
* Then run `make -f Makefile.msys2 CXX=x86_64-w64-mingw32-g++ CXXFLAGS=-static -j4` (-j switch is optional but will make building faster, it's based on the number of cores you have +1 so 8 cores wold be -j9)
### Server (Only required to host Sonic 2 multiplayer servers)
* Go into Server directory using the command `cd Server` when in the root of the decompilation source folder.
* Then run `make -f Makefile.msys2 CXXFLAGS=-static -j4` to create the Server executable (-j switch is optional but will make building faster, it's based on the number of cores you have +1 so 8 cores wold be -j9)

## Windows UWP (Phone, Xbox, etc.):
* Clone the repo, then follow the instructions in the [depencencies readme for Windows](./dependencies/windows/dependencies.txt) and [depencencies readme for UWP](./dependencies/windows-uwp/dependencies.txt) to setup dependencies, copy your `Data.rsdk` folder into `Sonic1Decomp.UWP` or `Sonic2Decomp.UWP` depending on the game, then build and deploy via `Sonic12Decomp.UWP.sln`
* You may also need to generate visual assets, to do so, open the Package.appxmanifest file in the designer, under the Visual Assets tab, select an image of your choice and click generate.

## Linux:
* To setup your build enviroment and library dependecies run the following commands:
* Ubuntu (Mint, Pop!_OS, etc...): `sudo apt install build-essential git libsdl2-dev libvorbis-dev libogg-dev libglew-dev libasio-dev`
* Arch Linux: `sudo pacman -S base-devel git sdl2 libvorbis libogg libglew libasio`
* Clone the repo with the following command: `git clone https://github.com/mrneptune64/RSDKv4N.git`
* Go into the repo you just cloned with `cd RSDKv4N`
* Clone the following repos with these commands: 
*  Tinyxml2: `git clone https://github.com/leethomason/tinyxml2.git ./dependencies/all/tinyxml2`
*  Stb-image: `git clone https://github.com/nothings/stb.git ./dependencies/all/stb-image`
* Run `make -j5` , if your distro is using gcc 8.x.x then add the argument `LIBS=-lstdc++fs`
* (-j switch is optional but will make building faster, it's based on the number of cores you have +1 so 8 cores wold be -j9)

## Other platforms:
Currently the only supported platforms are the ones listed above, however the backend uses libogg, libvorbis & SDL2 to power it, so the codebase is very multiplatform.
if you've cloned this repo and ported it to a platform not on the list or made some changes you'd like to see added to this repo, submit a pull request and it'll most likely be added

# Special Thanks
* basically everyone who worked on the original RSDKv4 decomp and Team Forever

# Contact:
mrneptune64 on disdcord
