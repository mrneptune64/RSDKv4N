#include <iostream> 
#include <sstream>
#include <string>
#include "RetroEngine.hpp"
#include <discord_rpc.h>
#include <discord_register.h>

void handleDiscordReady(const struct DiscordUser* request) {
    printLog("fuck you, ready", request->username, request->userId);
}

void handleDiscordDisconnected(int errorCode, const char* message) {
    printLog("fuck you, disconnected", errorCode, message);
}

void handleDiscordError(int errorCode, const char* message) {
    printLog("fuck you, error", errorCode, message);
}

void handleDiscordJoinGame(const char* joinSecret) {
    printLog("fuck you, joined", joinSecret);
}

void handleDiscordSpectateGame(const char* spectateSecret) {
    printLog("fuck you, spectating", spectateSecret);
}

void handleDiscordJoinRequest(const struct DiscordUser* request) {
    printLog("fuck you, user request join", request->username, request->userId);
}

void InitializeDiscordRPC(const char* data)
{
    // Split the data string
    std::string dataStr(data);
    std::stringstream ss(dataStr);
    std::string item;
    std::string parts[7]; // to store the 7 parts

    int i = 0;
    while (std::getline(ss, item, ',')) {
        parts[i] = item;
        i++;
        if (i >= 7) // break the loop if all 7 parts have been obtained
            break;
    }

    DiscordRichPresence discordPresence;
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    handlers.ready = handleDiscordReady;
    handlers.errored = handleDiscordError;
    handlers.disconnected = handleDiscordDisconnected;
    handlers.joinGame = handleDiscordJoinGame;
    handlers.spectateGame = handleDiscordSpectateGame;
    handlers.joinRequest = handleDiscordJoinRequest;

    // Discord_Initialize(const char* applicationId, DiscordEventHandlers* handlers, int autoRegister, const char* optionalSteamId)
    Discord_Initialize(parts[6].c_str(), &handlers, 1, "1234");
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.largeImageKey = parts[0].c_str();
    discordPresence.smallImageKey = parts[1].c_str();
    discordPresence.largeImageText = parts[2].c_str();
    discordPresence.smallImageText = parts[3].c_str();
    discordPresence.details = parts[4].c_str();
    discordPresence.state = parts[5].c_str();
    Discord_UpdatePresence(&discordPresence);
}

void UpdateDiscordRPC(const char* data)
{
    DiscordRichPresence discordPresence;

    // Split the data string
    std::string dataStr(data);
    std::stringstream ss(dataStr);
    std::string item;
    std::string parts[6]; // to store the 7 parts

    int i = 0;
    while (std::getline(ss, item, ',')) {
        parts[i] = item;
        i++;
        if (i >= 6) // break the loop if all 7 parts have been obtained
            break;
    }
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.largeImageKey = parts[0].c_str();
    discordPresence.smallImageKey = parts[1].c_str();
    discordPresence.largeImageText = parts[2].c_str();
    discordPresence.smallImageText = parts[3].c_str();
    discordPresence.details = parts[4].c_str();
    discordPresence.state = parts[5].c_str();
    Discord_UpdatePresence(&discordPresence);
}

void UpdateRPCTimer(int time)
{
    DiscordRichPresence discordPresence;
    int64_t trueTimer = static_cast<int64_t>(time);
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.startTimestamp = trueTimer;
    Discord_UpdatePresence(&discordPresence);
}

void UpdateRPCParty(int size, int max)
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.partySize = size;
    discordPresence.partyMax = max;
    Discord_UpdatePresence(&discordPresence);
}