cmake_minimum_required(VERSION 3.20)

include(vcpkg/vcpkg.cmake)

project(FileSync VERSION 1)
set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets CONFIG REQUIRED)

add_executable(FileSync WIN32
    src/FileSyncApp.h
    src/FileSyncApp.cpp
    src/FileSyncRegistery.h
    src/FileSyncRegistery.cpp
    src/DB/Manager.h
    src/DB/Manager.cpp
    src/DB/File.h
    src/DB/File.cpp
    src/gui/FileSyncEvent.h
    src/gui/FileSyncEvent.cpp
    src/gui/wxMainFrame.h
    src/gui/wxMainFrame.cpp
    src/gui/wxPanelBase.h
    src/gui/wxPanelBase.cpp
    src/gui/wxPanelStart.h
    src/gui/wxPanelStart.cpp
    src/gui/wxPanelMain.h
    src/gui/wxPanelMain.cpp
    src/gui/wxDirPicker.h
    src/gui/wxDirPicker.cpp
    src/gui/wxDirTextCtrl.h
    src/gui/wxDirTextCtrl.cpp
    src/gui/wxFileStaticBox.h
    src/gui/wxFileStaticBox.cpp
    src/gui/wxExtensionsStaticBox.h
    src/gui/wxExtensionsStaticBox.cpp
)

target_precompile_headers(FileSync PRIVATE src/FileSync_precomp.h)
target_link_libraries(FileSync PRIVATE wx::base wx::core)
