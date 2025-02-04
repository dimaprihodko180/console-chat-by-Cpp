#include "Chat.h"
#include <iostream>
#include <limits>

namespace ChatApp
    {
        void Chat::Start()
            {
                _isActive = true;
            }

        std::shared_ptr<User> Chat::findUserByLogin(const std::string &login) const
            {
                for (const auto &user: _users)
                    {
                        if (user.GetUserLogin() == login)
                            return std::make_shared<User>(user);
                    }
                return nullptr;
            }

        std::shared_ptr<User> Chat::findUserByName(const std::string &name) const
            {
                for (const auto &user: _users)
                    {
                        if (user.GetUserName() == name)
                            return std::make_shared<User>(user);
                    }
                return nullptr;
            }

        void Chat::displayLoginMenu()
            {
                _currentUser = nullptr;
                char option = '\0';
                do
                    {
                        std::cout <<
                                "\n(1) Вход в чат\n(2) Регистрация нового пользователя\n(0) Выход из чата\n";
                        std::cout << "Выберите действие: ";
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        switch (option)
                            {
                                case '1':
                                    login();
                                    break;
                                case '2':
                                    try
                                        {
                                            signUp();
                                        } catch (const std::exception &ex)
                                        {
                                            std::cout << ex.what() << std::endl;
                                        }
                                    break;
                                case '0':
                                    _isActive = false;
                                    break;
                                default:
                                    std::cout << "Выберите 1 или 2. Для выхода нажмите 0.\n";
                                    break;
                            }
                    } while (!_currentUser && _isActive);
            }

        void Chat::login()
            {
                std::string loginInput, passwordInput;
                char retryOption = '\0';

                do
                    {
                        std::cout << "Логин: ";
                        std::cin >> loginInput;
                        std::cout << "Пароль: ";
                        std::cin >> passwordInput;

                        _currentUser = findUserByLogin(loginInput);
                        if (!_currentUser || (passwordInput != _currentUser->GetUserPassword()))
                            {
                                _currentUser = nullptr;
                                std::cout <<
                                        "Ошибка входа.\nНажмите любую клавишу для повторной попытки или 0 для выхода: ";
                                std::cin >> retryOption;
                                if (retryOption == '0')
                                    break;
                            }
                    } while (!_currentUser);
            }

        void Chat::displayChat() const
            {
                std::cout << "\n--- Чат ---\n";
                for (const auto &message: _messages)
                    {
                        if (_currentUser->GetUserLogin() == message.GetFrom() ||
                            _currentUser->GetUserLogin() == message.GetTo() ||
                            message.GetTo() == "всем")
                            {
                                std::string fromName = (_currentUser->GetUserLogin() == message.
                                                        GetFrom())
                                                           ? "я"
                                                           : findUserByLogin(message.GetFrom())->
                                                           GetUserName();
                                std::string toName;
                                if (message.GetTo() == "всем")
                                    {
                                        toName = "всем";
                                    } else
                                    {
                                        toName = (_currentUser->GetUserLogin() == message.GetTo())
                                                     ? "я"
                                                     : findUserByLogin(message.GetTo())->
                                                     GetUserName();
                                    }
                                std::cout << "Сообщение от " << fromName << " для " << toName <<
                                        ":\n"
                                        << message.GetText() << "\n\n";
                            }
                    }
                std::cout << "------------\n";
            }

        void Chat::signUp()
            {
                std::string login, password, name;
                std::cout << "Придумайте логин: ";
                std::cin >> login;
                std::cout << "Придумайте пароль: ";
                std::cin >> password;
                std::cout << "Ваше имя: ";
                std::cin >> name;

                if (findUserByLogin(login) || login == "всем")
                    {
                        throw UserLoginException();
                    }
                if (findUserByName(name) || name == "всем")
                    {
                        throw UserNameException();
                    }
                User newUser(login, password, name);
                _users.push_back(newUser);
                _currentUser = std::make_shared<User>(newUser);
            }

        void Chat::displayUserMenu()
            {
                char option = '\0';
                std::cout << "\nПривет, " << _currentUser->GetUserName() << "!\n";
                while (_currentUser)
                    {
                        std::cout <<
                                "\nМеню: Показать чат (1) | Новое сообщение (2) | Пользователи (3) | Выход (0)\n";
                        std::cout << "Выберите действие: ";
                        std::cin >> option;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        switch (option)
                            {
                                case '1':
                                    displayChat();
                                    break;
                                case '2':
                                    addMessage();
                                    break;
                                case '3':
                                    displayAllUserNames();
                                    break;
                                case '0':
                                    _currentUser.reset();
                                    break;
                                default:
                                    std::cout << "Пожалуйста, выберите из списка.\n";
                                    break;
                            }
                    }
            }

        void Chat::addMessage()
            {
                std::string recipient, text;
                std::cout << "Введите имя получателя или 'всем' для рассылки: ";
                std::cin >> recipient;
                std::cout << "Текст сообщения: ";
                std::cin.ignore();
                std::getline(std::cin, text);

                if (recipient != "всем" && !findUserByName(recipient))
                    {
                        std::cout << "Ошибка: не найден пользователь " << recipient << ".\n";
                        return;
                    }
                if (recipient == "всем")
                    {
                        _messages.emplace_back(_currentUser->GetUserLogin(), "всем", text);
                    } else
                    {
                        _messages.emplace_back(_currentUser->GetUserLogin(),
                                               findUserByName(recipient)->GetUserLogin(), text);
                    }
            }

        void Chat::displayAllUserNames() const
            {
                std::cout << "\n--- Пользователи ---\n";
                for (const auto &user: _users)
                    {
                        std::cout << user.GetUserName();
                        if (_currentUser->GetUserLogin() == user.GetUserLogin())
                            std::cout << " (Я)";
                        std::cout << "\n";
                    }
                std::cout << "--------------------\n";
            }
    }
