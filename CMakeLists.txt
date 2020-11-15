cmake_minimum_required(VERSION 3.17)
project(JuceAndGainput)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include (CMake/GitFunctions.cmake)
update_from_git(juce "https://github.com/juce-framework/juce" develop)

add_subdirectory(${juce_SOURCE_DIR})
