#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

struct EventData {
	JavaVM* jvm;
	jobject handler;
};

// activity_events
void on_activity_join(void* event_data, const char* secret);
void on_activity_spectate(void* event_data, const char* secret);
void on_activity_join_request(void* event_data, struct DiscordUser* user);

// user_events
void on_current_user_update(void* event_data);

// overlay_events
void on_overlay_toggle(void* event_data, bool locked);

// relationship_events
void on_relationship_refresh(void* event_data);
void on_relationship_update(void* event_data, struct DiscordRelationship* relationship);

// lobby_events
void on_lobby_update(void* event_data, int64_t lobby_id);
void on_lobby_delete(void* event_data, int64_t lobby_id, uint32_t reason);
void on_member_connect(void* event_data, int64_t lobby_id, int64_t user_id);
void on_member_update(void* event_data, int64_t lobby_id, int64_t user_id);
void on_member_disconnect(void* event_data, int64_t lobby_id, int64_t user_id);
void on_lobby_message(void* event_data, int64_t lobby_id, int64_t user_id, uint8_t* data, uint32_t data_length);
void on_speaking(void* event_data, int64_t lobby_id, int64_t user_id, bool speaking);
void on_network_message(void* event_data, int64_t lobby_id, int64_t user_id, uint8_t channel_id, uint8_t* data, uint32_t data_length);

// network_events
void on_message(void* event_data, DiscordNetworkPeerId peer_id, DiscordNetworkChannelId channel_id, uint8_t* data, uint32_t data_length);
void on_route_update(void* event_data, const char* route_data);

#endif