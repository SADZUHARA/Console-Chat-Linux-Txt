#pragma once

#include<fstream>
#include"Constants.h"

class Message final {
public:
    Message();
    ~Message();

    void setText(const std::string& text);
    void setSender(const std::string& sender);
    void setReceiver(const std::string& receiver);

    const std::string& getText() const;
    const std::string& getSender() const;
    const std::string& getReceiver() const;

private:
    std::string _text;
    std::string _sender;
    std::string _receiver;

    void readConfig();
    void writeConfig() const;
};