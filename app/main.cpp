#include <iostream>
#include "Chat.h"
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	Chat messenger;
	messenger.Start();
	while (messenger.ChatWorkCheck())
	{
		messenger.ShowLoginMenu();
		while (messenger.GetCurrentUser()) {
			messenger.ShowUserMenu();
		}
	}
	return 0;
}
