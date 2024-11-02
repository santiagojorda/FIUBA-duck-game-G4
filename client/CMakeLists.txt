file(GLOB_RECURSE SOURCES_CLIENT "*.cpp")
file(GLOB_RECURSE SOURCES_HEDER_CLIENT "*.h")

target_sources(taller_client
    PRIVATE
    # .cpp files
   ${SOURCES_CLIENT}
   
    PUBLIC
    # .h files
    ${SOURCES_HEDER_CLIENT}
    )
