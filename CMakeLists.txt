# CMake Build File for Animation-Calibrator
# author: Tag Ashby <tgashby@calpoly.edu>

cmake_minimum_required(VERSION 2.6)

project(Animation-Calibrator)

# Sources
set(
   SOURCES
   src/Animation.cpp
   src/AnimationCalibrator.cpp
   src/AnimationManager.cpp
   src/InputManager.cpp
   src/TextureManager.cpp
)

# Includes
set(
   INCLUDES
   include/Animation.h
   include/AnimationManager.h
   include/InputManager.h
   include/Keys.h
   include/SDLIncludes.h
   include/Texture.h
   include/TextureManager.h   
)

# Non-System Libraries

# SDL
set(
   SDL_FOLDER
   ${CMAKE_CURRENT_SOURCE_DIR}/lib/sdl-1.3
   CACHE STRING "Path to SDL 1.3" FORCE
)

find_library(
   SDL_LIBRARY
   NAMES SDL-1.3.0 SDL
   PATHS ${SDL_FOLDER}
   PATH_SUFFIXES local/lib VisualC/SDL/Win32/Release
   NO_DEFAULT_PATH
)

find_library(
   SDLMAIN_LIBRARY
   NAMES SDLmain
   PATHS ${SDL_FOLDER}
   PATH_SUFFIXES local/lib VisualC/SDLmain/Win32/Release
   NO_DEFAULT_PATH
)

# SDL Image
set(
   SDL_IMG_FOLDER
   ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_image
   CACHE STRING "Path to SDL_image 1.2" FORCE
)

find_library(
   SDL_IMG_LIBRARY
   NAMES SDL_image
   PATHS ${SDL_IMG_FOLDER}
   PATH_SUFFIXES lib
   NO_DEFAULT_PATH
)

# System Libraries

# OpenGL
find_package(
   OpenGL REQUIRED
)

# Deal with silly Mac things
set(
   EXTRA_LIBS
   ""
)

if (APPLE)
   set(
      EXTRA_LIBS 
      ${EXTRA_LIBS} "-framework Cocoa"
   )
endif()

# Include the Includes
include_directories(
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${SDL_FOLDER}/include
   ${SDL_IMG_FOLDER}/include
)

# Get everything together for the executable
add_executable(
   Animation-Calibrator
   WIN32
   MACOSX_BUNDLE
   ${SOURCES}
   ${INCLUDES}
)

# Link all the libraries
target_link_libraries(
   Animation-Calibrator
   ${OPENGL_LIBRARIES}
   ${SDL_LIBRARY}
   ${SDLMAIN_LIBRARY}
   ${SDL_IMG_LIBRARY}
   ${EXTRA_LIBS}
)
