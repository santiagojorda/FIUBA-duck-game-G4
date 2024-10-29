#include "acceptor.h"

Acceptor::Acceptor(const std::string& _servname): Thread(), skt(_servname.c_str()) {}


Acceptor::~Acceptor() { Thread::~Thread(); }
