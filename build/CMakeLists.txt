cmake_minimum_required(VERSION 3.5.1)
project(klondike)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_BUILD_TYPE Debug) # it can be Debug or Release

set (INCLUDE_PATHS
  ../src/
  ../src/controller
  ../src/controller/movement
  ../src/model
  ../src/model/card
  ../src/utils
  ../src/view
  ../src/view/game
  )

include_directories(${INCLUDE_PATHS})

# Print the included directories. Just for debugin
#get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
# foreach(dir ${dirs})
#  message(STATUS "included_directory='${dir}'")
# endforeach()

file(GLOB_RECURSE SOURCES "../src/*.cpp")

#message(STATUS "source='${SOURCES}'")

add_executable(klondike ${SOURCES})
