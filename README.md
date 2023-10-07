# game-sdl2-vita

I'm doing this project to start and keep training my skills about game development.

## Steps to build it:

- Install VitaSDK using [vdpm](https://github.com/vitasdk/vdpm)
- Install [Vita3K](https://vita3k.org/quickstart.html) or use your console
- Clone this project
- Open the terminal inside this project and `run cmake . && make`, or edit `build.sh` and adjust paths according your installation.

I use `build.sh` as an easy way to build and copy generated vpk to my `vita3k` dir, and to get a eboot.bin when I wish to test in my PS Vita directly using a previous installed vpk.

## Tips:

I'm using Manjaro Mate as OS. If you got a error while building Vita3K, like "pkgver is not allowed to be empty", try to alter the pkgver in PKGBUILD file. Ex.: pkgver=3409.6911ed3 to pkgver=3409 (it worked for me)
