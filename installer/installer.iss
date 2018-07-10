#define MyAppName "Discord Rich Presence for Gothic 2 Night of the Raven"
#define MyAppVersion "pre-release"

[Setup]
AppName={#MyAppName}
AppVersion={#MyAppVersion}
DefaultDirName=C:\Program Files\JoWood\Gothic II Night of the Raven
AppendDefaultDirName=no
AllowNoIcons=yes
OutputDir=.
OutputBaseFilename=g2rpc-{#MyAppVersion}
Compression=lzma
SolidCompression=yes
Uninstallable=no

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "polish"; MessagesFile: "compiler:Languages\Polish.isl"

[Files]
Source: "..\output\bin\*.dll"; DestDir: "{app}\System"; Flags: ignoreversion
