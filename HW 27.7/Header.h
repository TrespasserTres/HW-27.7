#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <fstream>
#include <shared_mutex>
using namespace std;

class User                  // Класс пользователей с паролем и именем
{
public:
    User(const string& log, const string& pas, const string& nam) : login_(log), password_(pas), name_(nam) {}
    void displayUser();    // Вывод логина, имени и пароля
    string getLogin();     // Выдача логина
    string getPassword();  // Выдача пароля
    string getName();      // Выдача имени
private:
    string login_;
    string password_;
    string name_;
};

class Mail                  // Класс с архивом сообщений
{
public:
    Mail(const string& nam, const string& mes, const string& auth) : name_(nam), mesage_(mes), author_(auth) {}
    void displaymail(string Authormes);              // Вывод cooбщений
private:
    string name_;
    string mesage_;
    string author_;
};

class Logger                          // Класс логирования сообщений
{
    shared_mutex shared_mutex;
    fstream logfile;
public:
    Logger()
    {
        shared_mutex.lock();
        logfile.open("logfile.txt", fstream::in | fstream::out | fstream::trunc);
        shared_mutex.unlock();
    }
    void writeLog(string data);      // Запись логов
    string readLog();                // Чтение логов

    ~Logger()
    {
        shared_mutex.lock();
        logfile.close();
        shared_mutex.unlock();
    }
};

int backint(string a);   // Перевод текста в int (отсекаем неправильный выбор в меню)