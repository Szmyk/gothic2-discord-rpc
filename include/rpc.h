#pragma once

#include <cstring>

#include "../libs/discord-rpc/include/discord_rpc.h"

void initPresence();
void updatePresenceState (char* text);
