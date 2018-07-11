#pragma once

#include <string>
#include <algorithm>
#include <windows.h>
#include <cctype>
#include <map>

std::string getFileName(const std::string& path);
std::string getModuleFileName();
std::string toUpperCase(std::string str);
std::string getWorldName (std::string zenFile);
std::string utf8Encode(const std::wstring &wstr);
std::map<std::string, std::string> getCommandLineArgs();
std::string getModTitle(std::string modIniPath);
std::string getExeDirectory();
std::string getModText();
