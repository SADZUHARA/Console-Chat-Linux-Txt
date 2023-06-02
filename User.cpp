#include"User.h"
#include<iostream>

User::User() {
    readConfig();
}

User::~User() {
    writeConfig();
}

void User::setName(const std::string& name) {
    _name = name;
}

void User::setLogin(const std::string& login) {
    _login = login;
}

void User::setPass(const std::string& pass) {
    _pass = pass;
}

const std::string& User::getName() const {
    return _name;
}

const std::string& User::getLogin() const {
    return _login;
}

const std::string& User::getPass() const {
    return _pass;
}

void User::readConfig() {
    std::fstream file_config(PATH_DIRECTORY / CONFIG_FILE, std::ios::in);
    const char DELIMITER{ ':' };
    if (file_config.is_open()) {
        std::string line;
        std::string name;
        std::string value;
        while (std::getline(file_config, line)) {
            size_t delimiterPosition = line.find(DELIMITER);
            if (delimiterPosition > 0) {
                name = line.substr(0, delimiterPosition);
                value = line.substr(delimiterPosition + 1);

                if (name == "name") {
                    _name = value;
                }
                else if (name == "login") {
                    _login = value;
                }
                else if (name == "pass") {
                    _pass = value;
                }
            }
        }
        file_config.close();
    }
    else {
        std::cout << "Не удалось открыть файл конфигурфции для чтения\n";
        return;
    }
}

void User::writeConfig() const {
    std::fstream file_config(PATH_DIRECTORY / CONFIG_FILE, std::ios::app);
    if (file_config.is_open()) {
        file_config.seekp(0, std::ios_base::end);
        if (file_config.tellg()) {
            file_config.seekp(0, std::ios_base::beg);
            file_config << "name:" << _name << '\n';
            file_config << "login:" << _login << '\n';
            file_config << "pass:" << _pass << '\n';
            file_config.close();
        }
    }
    else {
        std::cout << "Не удалось открыть файл конфигурации для записи\n";
        return;
    }
}