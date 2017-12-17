cmake_minimum_required(VERSION 3.5.1)
project(klondike)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_BUILD_TYPE Debug) # it can be Debug or Release

set (INCLUDE_PATHS
  ../src/
  ../src/controller
  ../src/controller/movement
  ../src/controller/usecases
  ../src/model
  ../src/model/marshall
  ../src/model/card
  ../src/model/movement
  ../src/utils
  ../src/utils/menu
  ../src/view
  ../src/view/game
  ../src/view/menu
  ../src/view/savings
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
