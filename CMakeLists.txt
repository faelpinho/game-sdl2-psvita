cmake_minimum_required(VERSION 3.6)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

# Name of the project
project(meuhello)

# This line adds Vita helper macros, must go after project definition in order to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)

## Configuration options for this app
# Display name (under bubble in LiveArea)

# requires SDL2
find_package(SDL2 REQUIRED)

# Display name (under bubble in LiveArea)
set(VITA_APP_NAME "Meu Hello")
# unique string of developer and Y = a unique number for this app
set(VITA_TITLEID  "TEST00039")
set(VITA_VERSION  "01.00")

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Add any additional include paths here

include_directories(
    #common # This is for debugScreenPrintf(), you shouldn't need it in your projects
)

# Add any additional library paths here
# ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
#link_directories(
#   ${CMAKE_CURRENT_BINARY_DIR}
#)

## Build and link
# Add all the files needed to compile here
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
    src/engine/sdl_wrap.cpp
    src/engine/engine.cpp
    src/engine/common.cpp
    src/common/debugScreen.c
)

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2
    #SceDisplay_stub   # This used by debugScreenPrintf()
)


## Create Vita files
vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})

# The FILE directive lets you add additional files to the VPK, the syntax is
# FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
    FILE sce_sys/icon0.png sce_sys/icon0.png
    FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
    FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
    FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)
