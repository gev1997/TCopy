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
    src/GUI/ExtensionFilterEvent.h
    src/GUI/ExtensionFilterEvent.cpp
    src/GUI/MainFrame.h
    src/GUI/MainFrame.cpp
    src/GUI/PanelBase.h
    src/GUI/PanelBase.cpp
    src/GUI/PanelStart.h
    src/GUI/PanelStart.cpp
    src/GUI/PanelMain.h
    src/GUI/PanelMain.cpp
    src/GUI/DirPicker.h
    src/GUI/DirPicker.cpp
    src/GUI/DirTextCtrl.h
    src/GUI/DirTextCtrl.cpp
    src/GUI/FileStaticBox.h
    src/GUI/FileStaticBox.cpp
    src/GUI/ExtensionsStaticBox.h
    src/GUI/ExtensionsStaticBox.cpp
)

target_precompile_headers(FileSync PRIVATE src/FileSync_precomp.h)
target_link_libraries(FileSync PRIVATE wx::base wx::core)
