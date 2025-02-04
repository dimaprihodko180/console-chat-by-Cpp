#include "Chat.h"
#include<iostream>
#include <string>

void Chat::Start() {
	_chatWorkCheck = true;
}
	shared_ptr<User>Chat::GetUserByLogin(const string& login) const //поиск пользователя по логину
	{
	for (auto& user : _userList)
	{
		if (login == user.GetUserLogin())
			return make_shared<User>(user);
	}
	return nullptr;
}
	shared_ptr<User>Chat::GetUserByName(const string& name)const
{
	for (auto& user : _userList)
	{
		if (name == user.GetUserName())
			return make_shared<User>(user);
	}
	return nullptr;
}
void Chat::ShowLoginMenu()
{
	_currentUser = nullptr;//присваиваем текущему пользователю nullptr 
		char operation;
		do {
			cout << " (1) Вход в чат " << endl;
			cout << " (2) Регистрация нового пользователя " << endl;
			cout << " (0) Выход из чата " << endl;
			cout << "Выберите действие: ";
			cin >> operation;
			switch (operation) {
			case '1':
				Login(); //вход в чат по логину и паролю
				break;
			case '2':
				try
				{
					SignUp();//регистрация нового участника чата
				}
				catch (const exception& e)//отработка исключений; поиск ошибок при регистрации
				{
					cout << e.what() << endl;
				}
				break;
			case '0':
				_chatWorkCheck = false;
				break;
			default:
				cout << "Выберите действия 1 или 2. Для выхода нажмите 0" << endl;
				break;

			}
		} while (!_currentUser && _chatWorkCheck);
}
void Chat::Login() 
{
	string login, password;
	char operation;

	do {
		cout << " Логин: ";
		cin >> login;
		cout << " Пароль: ";
		cin >> password;

		_currentUser = GetUserByLogin(login);//указатель на зарегестрированного пользователя
		if (_currentUser == nullptr || (password != _currentUser ->GetUserPassword()))//при неверных данных nullptr или неверный пароль
		{
			_currentUser = nullptr;
			cout << " Ошибка входа " << endl;
			cout << " Нажмите любую клавишу для повторной попытки или 0 для выхода: ";
			cin >> operation;
			if (operation == '0')
				break;
		}
	} while (!_currentUser);
}

void Chat::ShowChat()const
{
	string from;
	string to;
	cout << " ---ЧАТ--- " << endl;
	for (auto& message : _messageList) 
	{
		if (_currentUser->GetUserLogin() == message.GetFrom() || _currentUser ->GetUserLogin() == message.GetTo() || message.GetTo() == " всем ")
		{
			from = (_currentUser ->GetUserLogin() == message.GetFrom()) ? "я" : GetUserByLogin(message.GetFrom())->GetUserName();
			if (message.GetTo() == " всем ")//отправка всем пользователям чата
			{
				to = "всем";
			}
			else
			{
				to = (_currentUser ->GetUserLogin() == message.GetTo()) ? "я" : GetUserByLogin(message.GetTo())->GetUserName();
			}
			cout << " Вам сообщение от " << from << " для " << to << endl;
			cout << " Текст сообщения:" << message.GetText() << endl;
		}
	}
	cout << "-----------" << endl;

}
void Chat::SignUp() 
{
	string login, password, name;
	double time;
	cout << " Придумайте логин: ";
	cin >> login;
	cout << " Придумайте пароль: ";
	cin >> password;
	cout << " Ваше имя: ";
	cin >> name;
	if (GetUserByLogin(login) || login == "всем")
	{
		throw UserLoginExp();
	}
	if (GetUserByName(name) || name == "всем")
	{
		throw UserNameExp();

	}
	User user = User(login, password, name, time);//создание нового пользователя
	_userList.push_back(user);//добавление пользователя
	_currentUser = make_shared<User>(user);//создание указателя на текущего пользователя
}
void Chat::ShowUserMenu() 
{
	char operation;
	cout << " Привет, " << _currentUser->GetUserName() << endl;
	while (_currentUser) 
	{
		cout << " Меню: Показать чат (1) | Новое сообщение (2) | Пользователи (3) | Выход (0) " << endl;
		cout << endl;
		cin >> operation;
		switch (operation) 
		{
		case '1':
			ShowChat();
			break;
		case '2':
			AddMessage();
			break;
		case '3':
			ShowAllUsersName();
			break;
		case'0':
			_currentUser = nullptr;
			break;
		default:
			cout << " Пожалуйста выберите из списка " << endl;
			break;
		}
	}
}
void Chat::AddMessage()
{
	string to, text;

	cout << " Для кого: (введите имя или отправьте всем сразу (выберите <<всем>>)";
	cin >> to;
	cout << "Текст сообщения: ";
	cin.ignore();
	getline(cin, text);
	if (!(to == "всем" || GetUserByName(to)))
	{
		cout << "Ошибка отправки сообщения: не удается найти пользователя " << to << endl;
		return;
	}
	if (to == "всем")
		_messageList.push_back(Message{ _currentUser->GetUserLogin()," всем ",text });
	else
		_messageList.push_back(Message{ _currentUser->GetUserLogin(),GetUserByName(to)->GetUserLogin(),text });

}

void Chat::ShowAllUsersName()const
{
	cout << "---Пользователи---" << endl;
	for (auto& user : _userList)
	{
		cout << user.GetUserName();
		if (_currentUser->GetUserLogin() == user.GetUserLogin())
			cout << " (Я) ";
		cout << endl;

	}
	cout << "-----------" << endl;
}
