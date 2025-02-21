cmake_minimum_required(VERSION 3.5)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(game
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Personnage.h
        Player.h
        Monstre.h
        Terrain.h
        Sol.h
        Obstacle.h
        Map.h
        Niveau.h
        Map.h Map.cpp
        Monstre.h Monstre.cpp
        Niveau.h Niveau.cpp
        Obstacle.h Obstacle.cpp
        Personnage.h Personnage.cpp
        Player.h Player.cpp
        Sol.h Sol.cpp
        Terrain.h Terrain.cpp
        Game.h Game.cpp
        res.qrc
        hpbar.h hpbar.cpp
        xpbar.h xpbar.cpp
        hud.h hud.cpp
        damageindicator.h damageindicator.cpp
        upgrade.h upgrade.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET game APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(game SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(game
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(game PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.game)
endif()
set_target_properties(game PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS game
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(game)
endif()
