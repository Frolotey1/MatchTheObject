cmake_minimum_required(VERSION 3.16)

project(Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Game source/main.cpp
    include/Sceen.hpp
    include/Form.hpp
    include/GameActions.hpp source/GameActions.cpp
    include/Frames.hpp
    include/Toys.hpp
    include/Action.hpp
    include/GameUI.hpp
    include/Panel.hpp
    include/Player.hpp
    include/ActionMenu.hpp
    source/Sceen.cpp
    include/SceenBuilder.hpp
    include/ConsoleUI.hpp
    include/GameApplication.hpp
)

include(GNUInstallDirs)
install(TARGETS Game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
