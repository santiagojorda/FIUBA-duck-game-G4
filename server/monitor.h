#ifndef MONITOR_H
#define MONITOR_H

#include <mutex>

template <typename T>
class Monitor {
private:
    std::list<T> list;
    std::mutex mtx;

public:
    Monitor() {}    
    // virtual void broadcast() = 0;
    // virtual T new_item() = 0;
    virtual void add_item(T& t) = 0;
    virtual void delete_item(T& t) = 0;
    virtual void shutdown() = 0;
    virtual ~Monitor() {}
};

#endif
