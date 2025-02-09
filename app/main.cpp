#include <iostream>
#include <Windows.h>
#include "src/Chat/Chat.h"

int main()
    {
        try
            {
                SetConsoleOutputCP(65001);

                ChatApp::Chat messenger;
                messenger.Start();

                while (messenger.ChatIsActive())
                    {
                        messenger.displayLoginMenu();
                        while (messenger.GetCurrentUser())
                            {
                                messenger.displayUserMenu();
                            }
                    }
            } catch (const std::exception &ex)
            {
                std::cerr << "Ошибка: " << ex.what() << std::endl;
            }
        return 0;
    }
