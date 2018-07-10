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
