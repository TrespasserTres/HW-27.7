#include<iostream>
#include <string>
#include "Header.h"
using namespace std;
#pragma runtime_checks( "", off )
#pragma warning( push )
#pragma warning( disable : 4700 )

int main()
{
    vector<User> users;
    vector<Mail> mail;
    vector <Logger> logg;
    string logcr;              // Переменная для создания Логина
    string namecr;             // Переменная для создания Имени
    string pascr;              // Переменная для создания Пароля
    string logent;             // Переменная ввод Логина
    string pasent;             // Переменная ввод Пароля
    string Nameadr;            // Переменная адресат
    string Authormes;          // Переменная автор
    string mes;                // Сообщения
    int choice;                // Переменная для меню
    string c;                  // Переменная для меню temp
    bool y = true;             // Переменная выхода из программы
    bool temp;                 // Служебная переменная
    Logger first;
    while (y == true)
    {
        cout << "1 - Create user / 2 - Enter chat / 3 - Exit program / 4 - HELP / 5 - Loggs" << endl;
        cin >> c;
        choice = backint(c);
        switch (choice)
        {
        case 1:                                                            //Регистрация пользователей
            cout << "Enter login: " << endl;                               //Запрос логина для первого пользователя
            cin >> logcr;
            temp = false;
            for (auto& u : users)
            {
                if (u.getLogin() == logcr)
                {
                    cout << "This login is buisy " << endl;
                    temp = true;
                    break;
                }
            }
            if (!temp)
            {
                cout << "Enter Password: " << endl;                        //Запрос пароля для первого пользователя
                cin >> pascr;
                cout << "Enter Name: " << endl;                            //Запрос имени для первого пользователя
                cin >> namecr;
                temp = false;
                for (auto& u : users)
                {
                    if (u.getName() == namecr)
                    {
                        cout << "This name is buisy " << endl;
                        temp = true;
                        break;
                    }
                }
                if (!temp)
                    users.emplace_back(logcr, pascr, namecr);
            }
            break;
        case 2:                                                            //Вход в Чат
            cout << "Enter login: " << endl;                               //Ввод логина
            cin >> logent;
            cout << "Enter password: " << endl;                            //Ввод пароля
            cin >> pasent;
            for (int i = 0; i < users.size(); ++i)
            {
                if (users[i].getLogin() == logent && users[i].getPassword() == pasent)
                {
                    cout << "Welcome to chat" << endl;
                    bool x = true;             // Переменная выхода из чата
                    while (x == true)
                    {
                        cout << "1 - Check messages / 2 - Write a message / 3 Exit chat " << endl;
                        cin >> c;
                        choice = backint(c);
                        switch (choice)
                        {
                        case 1:                                                //Проверка сообщений чата
                            for (auto& u : users)
                            {
                                if (u.getLogin() == logent)
                                    Authormes = u.getName();
                            }
                            for (auto& u : mail)
                            {
                                u.displaymail(Authormes);
                            }
                            break;
                        case 2:
                            if (users.size() == 1)                              //Отправка сообщений 1 пользователь в чате
                            {
                                cout << "No mo Users in chat" << endl;
                            }
                            else                                               //Отправка сообщений пользователям в чате
                            {
                                cout << "Enter user Name" << endl; //выбор пользователя для отправки
                                cin >> Nameadr;
                                temp = false;
                                for (auto& u : users)
                                {
                                    if (u.getName() == Nameadr && u.getLogin() != logent)
                                    {
                                        cout << "send message user name " << Nameadr << endl;  //Отправка 
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        getline(cin, mes);
                                        for (auto& u : users)
                                        {
                                            if (u.getLogin() == logent)
                                                Authormes = u.getName();
                                        }
                                        mail.emplace_back(Nameadr, mes, Authormes);
                                        temp = true;
                                        first.writeLog(mes);
                                    }
                                }
                                if (!temp)
                                    cout << "Can't send message user name " << Nameadr << endl;
                            }
                            break;
                        case 3:                                                //Выход из Чата
                            x = false;
                            break;
                        default:
                            cout << "Bad choise" << endl;
                            break;
                        }
                    }
                    break;
                }
                else if ((i + 1) == users.size())
                {
                    cout << "Wrong Login or Password " << endl;
                }
            }
            break;
        case 3:
            y = false;
            break;
        case 4:                                                            //Подсмотреть логин/пароль
            for (auto& u : users)
            {
                u.displayUser();
                cout << endl;
            }
            break;
        case 5:                                                            //Посмотреть файл логов
            cout << first.readLog() << endl;
            break;
        default:
            cout << "Bad choise" << endl;
            break;
        }
    }
    return 0;
}
