#include "client.h"


Client::Client(Socket&& _skt): skt(std::move(_skt)) {
    /*
    // rec -> te da la cantidad de ids , despues game te los comparte
    /
    */
}
