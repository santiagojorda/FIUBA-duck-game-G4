#include "acceptor.h"

Acceptor::Acceptor(const std::string& _servname): skt(_servname.c_str()) {}


Acceptor::~Acceptor() { Thread::~Thread(); }
