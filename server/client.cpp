#include "client.h"


Client::Client(Socket&& _skt): skt(std::move(_skt)) {}
