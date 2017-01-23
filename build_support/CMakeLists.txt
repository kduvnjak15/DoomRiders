cmake_minimum_required(VERSION 2.8)
project(DoomRiders)

set(INC_DIR .)
set(INC_DIR ../Include ${INC_DIR})
set(INC_DIR ../Include/ImageMagick-6/ ${INC_DIR}) 

include_directories(${INC_DIR})

set(LIBS libglut.so)
set(LIBS libGL.so ${LIBS})
set(LIBS libGLEW.so ${LIBS})
set(LIBS libopengl.so ${LIBS})
set(LIBS libcommon.a ${LIBS})
set(LIBS libSOIL.a ${LIBS}) 

set(LIBS_DIR /home/duvnjakk/workspace/cmakemanual/Lib)
link_directories( ${LIBS_DIR} )

file(GLOB SOURCES "../Src/*.cpp")
#set(SOURCES "../Src/main.cpp")

add_executable(DoomRiders ${SOURCES})

target_link_libraries(DoomRiders ${LIBS})


