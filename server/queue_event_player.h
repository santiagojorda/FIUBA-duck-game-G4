#ifndef QUEUE_EVENT_PLAYER
#define QUEUE_EVENT_PLAYER

#include "../common/queue.h"

#include "event_player.h"

#define MAX_EVENTS_QUEUE 100

class QueueEventPlayer: public Queue<EventPlayer*> {
public:
    QueueEventPlayer(): Queue<EventPlayer*>(MAX_EVENTS_QUEUE) {}
    ~QueueEventPlayer() {}
};

#endif
