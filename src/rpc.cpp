#include "../include/rpc.h"

void initPresence() {
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.largeImageKey = "default";
    Discord_UpdatePresence(&discordPresence);
}
