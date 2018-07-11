#include "../include/rpc.h"
#include "../include/utils.h"

DiscordRichPresence discordPresence;

std::string discordPresenceDetails;

void initPresence() {
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.largeImageKey = "default";
    discordPresence.details = getModText().c_str();

    discordPresenceDetails = discordPresence.details;

    Discord_UpdatePresence(&discordPresence);
}

void updatePresenceState (char* text) {
	discordPresence.state = text;
    discordPresence.details = discordPresenceDetails.c_str();

	Discord_UpdatePresence(&discordPresence);
}
