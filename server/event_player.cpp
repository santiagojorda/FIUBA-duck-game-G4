#include "event_player.h"

EventPlayer::EventPlayer() : Event() {}

void EventPlayer::set_id(const uint8_t& _player_id) { player_id = _player_id; }

EventPlayer::~EventPlayer() {Event::~Event();}