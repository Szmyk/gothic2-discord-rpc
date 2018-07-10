#pragma once

#include <string>
#include <algorithm>
#include <windows.h>
#include <cctype>

std::string getFileName(const std::string& path);
std::string getModuleFileName();
std::string toUpperCase(std::string str);
std::string getWorldName (std::string zenFile);
