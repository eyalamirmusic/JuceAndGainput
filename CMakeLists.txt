cmake_minimum_required(VERSION 3.17)
project(JuceAndGainput)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include (CMake/GitFunctions.cmake)
update_from_git(juce "https://github.com/juce-framework/juce" develop)
update_from_git(gainput "https://github.com/jkuhlmann/gainput.git" master)

add_subdirectory(${juce_SOURCE_DIR})

option(GAINPUT_SAMPLES "Build Samples for Gainput" OFF)
option(GAINPUT_TESTS "Build Tests for Gainput" OFF)

add_subdirectory(${gainput_SOURCE_DIR})

add_subdirectory(Apps)
