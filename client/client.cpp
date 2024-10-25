#include "client.h"

#include <iostream>
#include <sstream>

/*
Client::Client(const std::string& hostname, const std::string& servname):
        hostname(hostname), servicename(servname),
        skt(hostname.c_str(), servname.c_str()),
        protocol(skt),
        drawer() {}
*/
Client::Client(): hostname("localhost"), servicename("8080"), drawer() {}

void Client::run() { drawer.run(); }
