target_sources(taller_client
    PRIVATE
    # .cpp files
    main.cpp
    client.cpp
    drawer.cpp
    keyboard_controller.cpp
    protocol_client.cpp
    ../common/protocol.cpp
    ../common/coordinate.cpp
    ../common/socket.cpp
    ../common/liberror.cpp
    PUBLIC
    # .h files
    keyboard_controller.h
)
