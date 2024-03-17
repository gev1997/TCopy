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
    src/gui/ExtensionFilterEvent.h
    src/gui/ExtensionFilterEvent.cpp
    src/gui/MainFrame.h
    src/gui/MainFrame.cpp
    src/gui/PanelBase.h
    src/gui/PanelBase.cpp
    src/gui/PanelStart.h
    src/gui/PanelStart.cpp
    src/gui/PanelMain.h
    src/gui/PanelMain.cpp
    src/gui/DirPicker.h
    src/gui/DirPicker.cpp
    src/gui/DirTextCtrl.h
    src/gui/DirTextCtrl.cpp
    src/gui/FileStaticBox.h
    src/gui/FileStaticBox.cpp
    src/gui/ExtensionsStaticBox.h
    src/gui/ExtensionsStaticBox.cpp
)

target_precompile_headers(FileSync PRIVATE src/FileSync_precomp.h)
target_link_libraries(FileSync PRIVATE wx::base wx::core)
