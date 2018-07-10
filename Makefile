all: output/bin/libdiscord-rpc.dll

output/bin/libdiscord-rpc.dll:
	if not exist "output/bin" mkdir "output/bin"
	cmake libs/discord-rpc -DBUILD_SHARED_LIBS=TRUE -B"output/discord-rpc" -G "MinGW Makefiles"
	cmake --build output/discord-rpc --config Release
	copy output\discord-rpc\src\libdiscord-rpc.dll output\bin\libdiscord-rpc.dll

clean:
	if exist output rmdir output /s /q
