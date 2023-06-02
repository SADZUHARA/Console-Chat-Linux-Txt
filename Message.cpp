#include"Message.h"
#include<iostream>

Message::Message() {
    readConfig();
}

Message::~Message() {
    writeConfig();
}

void Message::setText(const std::string& text) {
    _text = text;
}

void Message::setSender(const std::string& sender) {
    _sender = sender;
}

void Message::setReceiver(const std::string& receiver) {
    _receiver = receiver;
}

const std::string& Message::getText() const {
    return _text;
}

const std::string& Message::getSender() const {
    return _sender;
}

const std::string& Message::getReceiver() const {
    return _receiver;
}

void Message::readConfig() {
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

                if (name == "text") {
                    _text = value;
                }
                else if (name == "sender") {
                    _sender = value;
                }
                else if (name == "receiver") {
                    _receiver = value;
                }
            }
        }
        file_config.close();
    }
    else {
        std::cout << "Íå óäàëîñü îòêðûòü ôàéë êîíôèãóðôöèè äëÿ ÷òåíèÿ\n";
        return;
    }
}

void Message::writeConfig() const {
    std::fstream file_config(PATH_DIRECTORY / CONFIG_FILE, std::ios::out);
    if (file_config.is_open()) {
        file_config << "text:" << _text << '\n';
        file_config << "sender:" << _sender << '\n';
        file_config << "receiver:" << _receiver << '\n';
        file_config.close();
    }
    else {
        std::cout << "Íå óäàëîñü îòêðûòü ôàéë êîíôèãóðàöèè äëÿ çàïèñè\n";
        return;
    }
}