cmake_minimum_required(VERSION 3.19)
project(notes_sharing_app LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(notes_sharing_app
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    signup.h signup.cpp signup.ui
    Helper.h Helper.cpp
    usermanager.h usermanager.cpp
    user.h user.cpp
    home.h home.cpp home.ui
    uploadnotes.h uploadnotes.cpp uploadnotes.ui
    Note.h
    notemanager.h notemanager.cpp
    mynotes.h mynotes.cpp mynotes.ui
    browsenotes.h browsenotes.cpp browsenotes.ui
    profile.h profile.cpp profile.ui


)

target_link_libraries(notes_sharing_app
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS notes_sharing_app
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET notes_sharing_app
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
