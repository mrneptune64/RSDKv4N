#ifndef DISCORDRPC_H
#define DISCORDRPC_H

void handleDiscordReady(const struct DiscordUser* request);
void handleDiscordDisconnected(int errorCode, const char* message);
void handleDiscordError(int errorCode, const char* message);
void handleDiscordJoinGame(const char* joinSecret);
void handleDiscordSpectateGame(const char* spectateSecret);
void handleDiscordJoinRequest(const struct DiscordUser* request);
void InitializeDiscordRPC(const char* data);
void UpdateDiscordRPC(const char* data);
void UpdateRPCTimer(int time);
void UpdateRPCParty(int size, int max);

#endif // !DISCORDRPC_H