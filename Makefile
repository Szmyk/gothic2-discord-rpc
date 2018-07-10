ifndef ORIGINAL_VDFS_LIB_PATH
$(error ORIGINAL_VDFS_LIB_PATH is not set)
endif

all: vdfs32g.dll

output/bin/libdiscord-rpc.dll:
	if not exist "output/bin" mkdir "output/bin"
	cmake libs/discord-rpc -DBUILD_SHARED_LIBS=TRUE -B"output/discord-rpc" -G "MinGW Makefiles"
	cmake --build output/discord-rpc --config Release
	copy output\discord-rpc\src\libdiscord-rpc.dll output\bin\libdiscord-rpc.dll

output/liborgvdfs32g.a:
	expdef "$(ORIGINAL_VDFS_LIB_PATH)" -d"output/vdfs32g.def" -p
	go get github.com/Szmyk/go-utils/files
	go run tools/prepareDef.go
	dlltool -d output/vdfs32g.def -l output/liborgvdfs32g.a

vdfs32g.dll: output/bin/libdiscord-rpc.dll output/liborgvdfs32g.a
	g++ -c src/main.cpp -o output/main.o
	dllwrap -o output/bin/vdfs32g.dll -def output/vdfs32g.def output/main.o -lstdc++ output/liborgvdfs32g.a -static output/bin/libdiscord-rpc.dll
	copy "$(ORIGINAL_VDFS_LIB_PATH)" "output\bin\orgVdfs32g.dll"

clean:
	if exist output rmdir output /s /q
