set(COMPONENT_SRCS
    "src/ControlCallbacks.cpp")
set(COMPONENT_ADD_INCLUDEDIRS "include")

idf_component_register( SRCS ${COMPONENT_SRCS}
                        INCLUDE_DIRS ${COMPONENT_ADD_INCLUDEDIRS})