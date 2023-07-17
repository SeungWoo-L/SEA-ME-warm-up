#include <iostream>
#include <vector>
#include "contact.hpp"


Contact::Contact(std::string Name, std::string PhoneNumber, std::string NickName) {
    this->Name = Name;
    this->PhoneNumber = PhoneNumber;
    this->NickName = NickName;
    this->bookmarked = false;
}

bool Contact::IsBookmarked() const {
    return bookmarked;
}

void Contact::SetBookmarked(bool value) {
    this->bookmarked = value;
}

std::string Contact::GetPhoneNum() const{
    return PhoneNumber;
}