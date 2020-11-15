project(GainputGuiApp VERSION 0.0.1)

set (TargetName ${PROJECT_NAME})

juce_add_gui_app(${TargetName} PRODUCT_NAME "Gainput Gui APP")

target_sources(${TargetName} PRIVATE
        Source/Main.cpp
        Source/MainWindow.cpp)

target_compile_definitions(${TargetName} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_PROJECT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_VERSION>")

target_include_directories(${TargetName} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Source
        ${gainput_SOURCE_DIR}/lib/include)

#TODO: Fixed warnings that gainput throws so we can use juce_recommended_warning_flags
target_link_libraries(${TargetName} PRIVATE
        juce_recommended_config_flags
        juce_recommended_lto_flags
        juce_gui_extra
        gainputstatic)
