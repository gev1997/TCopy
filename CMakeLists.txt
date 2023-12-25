cmake_minimum_required(VERSION 3.20)

include(vcpkg/vcpkg.cmake)

project(FileSync VERSION 1)
set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets CONFIG REQUIRED)

add_executable(FileSync WIN32
    src/DB/Manager.h
    src/DB/Manager.cpp
    src/DB/File.h
    src/DB/File.cpp
    src/FileSyncApp.h
    src/FileSyncApp.cpp
    src/wxMainFrame.h
    src/wxMainFrame.cpp
    src/wxPanelBase.h
    src/wxPanelBase.cpp
    src/wxPanelStart.h
    src/wxPanelStart.cpp
    src/wxPanelMain.h
    src/wxPanelMain.cpp
    src/wxDirPicker.h
    src/wxDirPicker.cpp
    src/wxDirTextCtrl.h
    src/wxDirTextCtrl.cpp
    src/wxFileStaticBox.h
    src/wxFileStaticBox.cpp
    src/wxExtensionsStaticBox.h
    src/wxExtensionsStaticBox.cpp
)

target_precompile_headers(FileSync PRIVATE src/FileSync_precomp.h)
target_link_libraries(FileSync PRIVATE wx::base wx::core)
