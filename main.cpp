#include"User.h"
#include"Message.h"
#include"Constants.h"
#include<iostream>


int main() 
{
    setlocale(LC_ALL, "rus");

    if (!std::filesystem::exists(PATH_DIRECTORY / CONFIG_FILE)) 
    {
        std::filesystem::create_directories(PATH_DIRECTORY);
        std::fstream file_config(PATH_DIRECTORY / CONFIG_FILE, std::ios::out);
        std::filesystem::permissions(PATH_DIRECTORY / CONFIG_FILE,
            std::filesystem::perms::group_all | std::filesystem::perms::others_all,
            std::filesystem::perm_options::remove);
        if (file_config.is_open()) {
            file_config << "name:no_name\n";
            file_config << "login:no_login\n";
            file_config << "pass:no_pass\n";
            file_config << "text:no_text\n";
            file_config << "sender:no_sender\n";
            file_config << "receiver:no_receiver\n";
            file_config.close();
        }
        else {
            std::cout << "Íå óäàëîñü ñîçäàòü ôàéë êîíôèãóðàöèè\n";
        }
    }

    User user;
    std::cout << "name:" << user.getName() << '\n';
    std::cout << "login:" << user.getLogin() << '\n';
    std::cout << "pass:" << user.getPass() << '\n';

    user.setName(std::string("NameTest"));
    user.setLogin(std::string("LoginTest"));
    user.setPass(std::string("PassTest"));

    Message message;
    std::cout << "text:" << message.getText() << '\n';
    std::cout << "sender:" << message.getSender() << '\n';
    std::cout << "receiver:" << message.getReceiver() << '\n';

    message.setText(std::string("TextTest"));
    message.setSender(std::string("SenderTest"));
    message.setReceiver(std::string("ReceiverTest"));

    return 0;
}