#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "../Message/Message.h"

class UserLoginExp : public exception
        //наследование от класса exeption для последующей обработки исключений
    {
    public:
        const char *what() const noexcept override
            {
                return " Ошибка: логин пользователя занят ";
            }
    };

class UserNameExp : public exception
    {
    public:
        const char *what() const noexcept override
            {
                return " Ошибка: имя пользователя занято ";
            }
    };

class Chat
    {
        bool _chatWorkCheck = false; //переменная, отвечающая за работу чата
        vector<User> _userList; //создаем вектор, который хранит пользователей чата
        vector<Message> _messageList; //создаем вектор, который хранит сообщения в чате
        shared_ptr<User> _currentUser = nullptr; //указатель на текущего пользователя

        void Login();

        void SignUp();

        void ShowChat() const;

        void ShowAllUsersName() const;

        void AddMessage();

        vector<User> &GetAllUsers()
            {
                return _userList;
            }

        vector<Message> &GetAllMessages()
            {
                return _messageList;
            }

        shared_ptr<User> GetUserByLogin(const string &login) const;

        shared_ptr<User> GetUserByName(const string &name) const;

    public:
        void Start();

        bool ChatWorkCheck() const
            {
                return _chatWorkCheck;
            }

        shared_ptr<User> GetCurrentUser() const
            {
                return _currentUser;
            }

        void ShowLoginMenu();

        void ShowUserMenu();
    };
