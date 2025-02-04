#pragma once

#include <vector>
#include <memory>
#include <exception>
#include <string>
#include "../Message/Message.h"
#include "../User/User.h"

namespace ChatApp {

    // Кастомные исключения
    class UserLoginException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Ошибка: логин пользователя занят.";
        }
    };

    class UserNameException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Ошибка: имя пользователя занято.";
        }
    };

    class Chat {
    private:
        bool _isActive = false;
        std::vector<User> _users;
        std::vector<Message> _messages;
        std::shared_ptr<User> _currentUser = nullptr;

        // Вспомогательные методы
        void login();
        void signUp();
        void displayChat() const;
        void displayAllUserNames() const;
        void addMessage();
        std::shared_ptr<User> findUserByLogin(const std::string &login) const;
        std::shared_ptr<User> findUserByName(const std::string &name) const;

    public:
        Chat() = default;
        ~Chat() = default;

        // Интерфейс для работы с чатом
        void Start();
        bool ChatIsActive() const { return _isActive; }
        std::shared_ptr<User> GetCurrentUser() const { return _currentUser; }
        void displayLoginMenu();
        void displayUserMenu();
    };

} // namespace ChatApp
