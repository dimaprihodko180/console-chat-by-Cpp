cmake_minimum_required(VERSION 3.20)  # Укажи версию, которая точно у тебя установлена
project(ConsoleChat)                # Имя без пробелов

set(CMAKE_CXX_STANDARD 23)

add_executable(
        ConsoleChat                     # Имя цели без пробелов
        app/main.cpp
        app/src/Chat/Chat.cpp
        app/src/Chat/Chat.h
        app/src/Message/Message.cpp
        app/src/Message/Message.h
        app/src/User/User.cpp
        app/src/User/User.h
)
