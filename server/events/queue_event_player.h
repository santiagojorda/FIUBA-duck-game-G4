#ifndef QUEUE_EVENT_PLAYER
#define QUEUE_EVENT_PLAYER

#include "../../common/queue.h"

#include "event_player.h"

#include <memory> 

#define MAX_EVENTS_QUEUE 100

class QueueEventPlayer: public Queue<std::shared_ptr<EventPlayer>> {
public:
    QueueEventPlayer(): Queue<std::shared_ptr<EventPlayer>>(MAX_EVENTS_QUEUE) {}
    ~QueueEventPlayer() {}
};

#endif
