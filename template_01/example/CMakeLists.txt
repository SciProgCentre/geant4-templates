CMAKE_MINIMUM_REQUIRED(VERSION 3.3 FATAL_ERROR)

PROJECT(geant4-example)

# For using protobuf serialzation
#find_package(Protobuf REQUIRED)
#include_directories(${Protobuf_INCLUDE_DIRS})
#PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS filename.proto)


FIND_PACKAGE(Geant4 REQUIRED ui_all vis_all)

IF(NOT Geant4_FOUND)
    MESSAGE(FATAL_ERROR "Geant4 not found!")
ENDIF(NOT Geant4_FOUND)


INCLUDE(${Geant4_USE_FILE})



INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../general/include)
FILE(GLOB general ${PROJECT_SOURCE_DIR}/../general/src/*.cc )

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
FILE(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)




ADD_EXECUTABLE(geant4-example.exe main.cc
        ${sources} ${general}
        #${PROTO_SRCS} ${PROTO_HDRS}
        )

target_include_directories(geant4-example.exe
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        )

TARGET_LINK_LIBRARIES(geant4-example.exe
        ${Geant4_LIBRARIES} 
        #${Protobuf_LIBRARIES}
)

set(PROGRAM_SCRIPTS
        init_vis.mac
        init.mac
        empty.gdml
        )

foreach(_script ${PROGRAM_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
    )
endforeach()