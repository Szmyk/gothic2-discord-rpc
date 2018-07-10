#include "../include/rpc.h"

DiscordRichPresence discordPresence;

void initPresence() {
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.largeImageKey = "default";
    Discord_UpdatePresence(&discordPresence);
}

void updatePresenceDetails (char* text) {
	discordPresence.details = text;

	Discord_UpdatePresence(&discordPresence);
}
