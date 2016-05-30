cmake_minimum_required(VERSION 2.8.9)
project(RPkgTestSharedLibrary)
set(CMAKE_BUILD_TYPE Release)

set(GIT_REPO_LOC $ENV{GIT_REPO_LOC})

add_definitions(-std=c++11)

include_directories (${GIT_REPO_LOC}/RPackageCppExamples/include)

set(CC_SOURCES shared_function.cpp)
add_library(RPkgTestSharedLibrary SHARED ${CC_SOURCES})

# Run `sudo make install` to install.
install(TARGETS RPkgTestSharedLibrary DESTINATION /usr/lib)