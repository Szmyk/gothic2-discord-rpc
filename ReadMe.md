# Discord Rich Presence for Gothic 2 Night of the Raven

## Download

Download installer in [releases](https://github.com/Szmyk/gothic2-discord-rpc/releases/latest).

## Building

### Cloning

Make sure to clone repository with `--recursive` flag.

`git clone --recursive https://github.com/Szmyk/gothic2-discord-rpc.git`

### Requirements

* CMake
* make
* MinGW
* expdef
* Golang

### Building

Use `make` command with `ORIGINAL_VDFS_LIB_PATH` flag which is path to `vdfs32g.dll` from your Gothic 2 Night of the Raven game.

`make ORIGINAL_VDFS_LIB_PATH=C:\ProgramFiles\JoWood\Gothic 2 Night of the Raven\System\vdfs32g.dll`

Files to place in `System` directory will be in  `output/bin` directory.

### Installer

InnoSetup script is placed in `installer` directory.

## Acknowledgments

Huge thanks to Gynvael Coldwind for articles of DLL spoofing and other Windows related articles.
