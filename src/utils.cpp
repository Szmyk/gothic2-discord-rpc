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
