![](header.png?raw=true)
+ Without assets from the official releases this decompilation will not run.

+ This decompilation was designed with Sonic 1 Forever in mind. While it can run stock Sonic 1 and Sonic 2, it was intended for use with the Team Forever mods.

# New Stuff:
* Discord RPC Support
	### **THIS USES THE DEPRECATED DISCORD GAME SDK. DOCUMENTATION MAY NOT BE AVAILABLE.**
	* Documentation about the new instructions included that manage the Discord RPC implementation can be provided upon request. See Contact.
			
## How to create a Discord application:
[Just go here.](https://discord.com/developers/)

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
