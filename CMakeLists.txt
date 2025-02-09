cmake_minimum_required(VERSION 3.20)
project(ConsoleChat)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        ConsoleChat
        app/main.cpp
        app/src/Chat/Chat.cpp
        app/src/Chat/Chat.h
        app/src/Message/Message.cpp
        app/src/Message/Message.h
        app/src/User/User.cpp
        app/src/User/User.h
        "app/src/Chat/utils/Input.h"
        "app/src/Chat/utils/Exceptions.h"
        "app/src/Chat/utils/Time.h"
        "app/src/Chat/utils/Display.h"
        "app/src/Chat/utils/Input.cpp"
        "app/src/Chat/utils/Time.cpp"
        "app/src/Chat/utils/Display.cpp"
)
