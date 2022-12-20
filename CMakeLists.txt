cmake_minimum_required(VERSION 3.20)
project(CCheck C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rdynamic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(CCheck
        main/main.c
        socket/server/server.c socket/server/server.h
        screen/setup/setup_window.c screen/setup/setup_window.h
        screen/client/client_window.c screen/client/client_window.h
        socket/client/client.c socket/client/client.h
        screen/server/server_window.c screen/server/server_window.h screen/result/result_window.c screen/result/result_window.h database/database.h database/database.c)


target_link_libraries(CCheck ${GTK3_LIBRARIES})

install(TARGETS CCheck
        COMPONENT linapp
        RUNTIME DESTINATION "/home/"
        LIBRARY DESTINATION "/home/"
        DESTINATION "/home/"
        )

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
INCLUDE(CPack)