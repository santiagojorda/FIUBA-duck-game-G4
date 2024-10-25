#include "protocol_client.h"

ClientProtocol::ClientProtocol(Socket& socket): skt(socket), was_closed(false) {}
