cmake_minimum_required(VERSION 3.20)

include(vcpkg/vcpkg.cmake)

project(TCopy VERSION 1)
set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets CONFIG REQUIRED)

add_executable(TCopy
    src/TCopyApp.h
    src/TCopyApp.cpp
    src/wxMainFrame.h
    src/wxMainFrame.cpp
    src/wxPanelBase.h
    src/wxPanelBase.cpp
    src/wxPanelStart.h
    src/wxPanelStart.cpp
    src/wxPanelMain.h
    src/wxPanelMain.cpp
)

target_link_libraries(TCopy PRIVATE wx::base wx::core)
