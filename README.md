# Educational project: Console Chat Application

Консольный учебный чат — это проект консольного приложения, созданный в учебных целях и которое 
реализует основные функции 
мессенджера, 
используя стандартную библиотеку шаблонов (STL) и современные возможности C++ (C++23).
С помощью этого приложения вы можете зарегистрироваться как пользователь, войти в чат, отправлять сообщения с отметкой времени и просматривать историю переписки.


## 🚀 Функциональные возможности

- **Регистрация пользователей** — возможность создания нового аккаунта с любым логином и именем.
- **Аутентификация** — вход в чат с проверкой логина и пароля.
- **Отправка сообщений** — отправка сообщений как отдельным пользователям, так и всем участникам (рассылка).
- **Отметка времени** — каждое сообщение помечается временной меткой с использованием `std::chrono`.
- **Вывод сообщений и списка пользователей** — удобное форматирование и отображение в консоли.
- **Модульная структура** — проект разделен на несколько модулей (*Chat, User, Message, а также утилитарные модули для работы с вводом/выводом, временем и исключениями*), что облегчает его сопровождение и расширение.


## 🛠 Используемые технологии

- **Язык программирования:** C++ (C++23)
- **Сборка:** CMake (минимальная версия 3.20)
- **Стандартная библиотека STL:**
  - Контейнеры: `std::vector`, `std::unordered_map`
  - Умные указатели: `std::shared_ptr`
  - Строки: `std::string`
  - Хронология: `std::chrono`
  - Алгоритмы: `std::find_if` и другие
- **Операционная система:** Windows (консольное приложение)

## 📂 Структура проекта

```plaintext
ConsoleChat/
├── app/
│   ├── src/
│   │   ├── Chat/
│   │   ├── Message/
│   │   ├── User/
│   │   └── utils/
│   ├── main.cpp
├── build/
├── CMakeLists.txt
├── README.md
└── LICENSE
```

## ⚙️ Сборка и запуск

### 📌 Предварительные требования

- Компилятор с поддержкой C++23 (MSVC, GCC, Clang)
- CMake версии 3.20 или выше
- Windows (консольное приложение)

**Примечание:** На данном этапе не реализована грамотная работа с кириллицей.

### 🔧 Инструкция по сборке

1. **Клонируйте репозиторий:**
   ```bash
   git clone https://github.com/dimaprihodko180/console-chat-by-Cpp.git
   
   ```
2. **Создайте директорию для сборки и перейдите в неё:**
   ```bash
   mkdir build
   cd build
   ```
3. **Сгенерируйте файлы проекта с помощью CMake:**
   ```bash
   cmake ..
   ```
4. **Соберите проект:**
   ```bash
   cmake --build .
   ```
5. **Запустите приложение:**
   ```bash
   ./ConsoleChat.exe
   ```


## 🏗 Применение STL в проекте

В проекте активно используются возможности стандартной библиотеки STL:

- **Контейнеры:**
  - `std::vector` – хранение списка сообщений.
  - `std::unordered_map` – быстрый поиск пользователей по логину и имени.
- **Умные указатели:**
  - `std::shared_ptr` – управление жизненным циклом объектов класса `User`.
- **Строковые операции:**
  - `std::string` – работа с текстовыми данными и сообщениями.
- **Алгоритмы:**
  - Использование `std::find_if` позволяет делать поиск более декларативным и безопасным.
- **Хронология:**
  - `std::chrono` – получение и форматирование времени отправки сообщений (поддержка временных меток).

## 👤 Автор

**Приходько Дмитрий Викторович**  
Студент группы **CPLUS48** oнлайн-школы IT-профессий **Skillfactory**

## 📩 Контакты

📧 **dim4dmi7rij@yandex.ru**

📧 **dimaprihodko180@gmail.com**

📱 **+7 904 926‒57‒29**

