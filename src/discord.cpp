#include "../include/discord.h"
#include "../include/rpc.h"

const char* ApplicationId = "465897417980641281";

void handleDiscordReady(const DiscordUser* connectedUser) {
	initPresence();
}

void discordInit() {
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
	handlers.ready = handleDiscordReady;

    Discord_Initialize(ApplicationId, &handlers, true, NULL);
}
