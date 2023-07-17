#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <iostream>
#include <string>

class Phonebook;

class Contact{
private:
    std::string Name;
    std::string PhoneNumber;
    std::string NickName;
    bool        bookmarked;
    
public:
    Contact(std::string Name, std::string PhoneNumber, std::string NickName);

    bool IsBookmarked() const;
    void SetBookmarked(bool value);
    std::string GetPhoneNum() const;
    
    friend class Phonebook;
};

#endif

