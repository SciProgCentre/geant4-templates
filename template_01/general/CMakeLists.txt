CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)

PROJECT(geant4-server)

FIND_PACKAGE(Geant4 REQUIRED ui_all vis_all)


IF (NOT Geant4_FOUND)
    MESSAGE(FATAL_ERROR "Geant4 not found!")
ENDIF (NOT Geant4_FOUND)

INCLUDE(${Geant4_USE_FILE})

set(CMAKE_CONFIGURATION_TYPES Reales)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
FILE(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)


add_library(geant4-dfclient SHARED ${sources})

target_link_libraries(${PROJECT_NAME} ${Geant4_LIBRARIES})
INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION .
        FILES_MATCHING PATTERN "*.hh")

#ADD_EXECUTABLE(test.exe test.cc ${sources} ${headers})
#TARGET_LINK_LIBRARIES(test.exe ${Geant4_LIBRARIES})


