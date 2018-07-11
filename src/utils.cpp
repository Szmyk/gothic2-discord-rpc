#include "../include/utils.h"

std::string getFileName(const std::string& path)
{
    return {std::find_if(path.rbegin(), path.rend(),
            [](char c) { return c == '/' || c == '\\'; }).base(),
            path.end()};
}

std::string getModuleFileName()
{
    char modulePath[MAX_PATH];
	GetModuleFileName(NULL, modulePath, MAX_PATH);

    return getFileName(modulePath);
}

std::string toUpperCase(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    return str;
}

std::string getWorldName (std::string zenFile) {
    std::string zen = toUpperCase(zenFile);

    if (zen == "NEWWORLD.ZEN") {
        return "Khorinis";
    } else if (zen == "OLDWORLD.ZEN") {
        return "Colony";
    } else if (zen == "DRAGONISLAND.ZEN") {
        return "Irdorath";
    } else if (zen == "ADDONWORLD.ZEN") {
        return "Jarkendar";
    }  else {
        return zenFile;
    }
}

std::string utf8Encode (const std::wstring &wstr) {
    if (wstr.empty())  {
        return std::string();
    }

    size_t sizeRequired = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);

    std::string strTo(sizeRequired, 0);

    WideCharToMultiByte (CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], sizeRequired, NULL, NULL);

    return strTo;
}

std::map<std::string, std::string> getCommandLineArgs () {
    std::map<std::string, std::string> arguments;

    int argsCount;
	LPWSTR *argsList = CommandLineToArgvW(GetCommandLineW(), &argsCount);

    if (argsList != NULL) {
		for (int i = 1; i < argsCount; i++) {
			std::string arg = utf8Encode(argsList[i]);

			arg = arg.substr(arg.find("-") + 1);

            if (arg.find(":") != std::string::npos) {
                std::string value = arg.substr(arg.find(":") + 1);
                arg = arg.substr(0, arg.find_last_of(":"));

                arguments.insert (std::pair<std::string, std::string>(arg, value));
            } else {
                arguments.insert (std::pair<std::string, std::string>(arg, ""));
            }
		}
	}

    return arguments;
}

std::string getModTitle (std::string modIniPath) {
    char modTitle[MAX_PATH];
    GetPrivateProfileString("INFO", "Title", "", modTitle, MAX_PATH, modIniPath.c_str());

    return modTitle;
}

std::string getExeDirectory () {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);

    std::string exePath(buffer);

    return exePath.substr(0, exePath.find_last_of("\\"));
}

std::string getModText () {
    std::map<std::string, std::string> args = getCommandLineArgs();

    if (args.empty()) {
        return std::string();
    }

    std::string modIni = args["game"];

    if (modIni != "" && toUpperCase(modIni) != "GOTHICGAME.INI") {
        std::string gothicExeDirectory = getExeDirectory();

        std::string modIniPath = gothicExeDirectory;
        modIniPath.append("\\");
        modIniPath.append(modIni);

        std::string modTitle = getModTitle(modIniPath);

        if (modTitle != "") {
            return std::string("Mod: ") + std::string(modTitle);
        } else {
            return std::string();
        }
    } else {
        return std::string();
    }
}
