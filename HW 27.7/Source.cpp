#include "Header.h"
#include <string>


string User::getLogin()                       // ������ �����
{
    return login_;
}

string User::getPassword()                     // ������ ������
{
    return password_;
}

string User::getName()                        // ������ �����
{
    return name_;
}

void User::displayUser()                        // ����� ������, ����� � ������
{
    cout << "Login - " << login_ << endl;
    cout << "Password - " << password_ << endl;
    cout << "Name - " << name_ << endl;
}

void Mail::displaymail(string Authormes)                        // ����� coo������
{
    if (name_ == Authormes)
        cout << author_ << " : " << mesage_ << endl;
}

void Logger::writeLog(string data)
{
    if (!logfile)
        // ��� �������� ����� ���������� �������� ios::trunc
        logfile = fstream("logfile.txt", fstream::in | fstream::out | fstream::trunc);
    if (!logfile)
    {
        shared_mutex.lock();
        this->logfile << data << std::endl;
        shared_mutex.unlock();
    }
    else
    {
        cout << "Could not open file logfile.txt !" << '\n';
    }
}

string Logger::readLog()
{
    if (!logfile)
    {
        shared_mutex.lock_shared();
        string read;
        getline(this->logfile, read);
        shared_mutex.unlock_shared();
        return read;
    }
    else
    {
        cout << "Could not open file logfile.txt !" << '\n';
    }
}


int backint(string a)                        // ������� ������ � int (�������� ������������ ����� � ����)
{
    int b;
    if (a == "1")
    {
        b = 1;
    }
    else if (a == "2")
    {
        b = 2;
    }
    else if (a == "3")
    {
        b = 3;
    }
    else if (a == "4")
    {
        b = 4;
    }
    else if (a == "5")
    {
        b = 5;
    }
    else b = 11;
    return b;
}