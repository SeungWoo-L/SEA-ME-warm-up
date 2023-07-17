#include "contact.h"

Contact::Contact(const QString& name, const QString& nickname, const QString& phoneNumber, const QString& address)
    : name(name), nickname(nickname), phoneNumber(phoneNumber), address(address)
{
}

QString Contact::getName() const
{
    return name;
}

QString Contact::getNickname() const
{
    return nickname;
}

QString Contact::getPhoneNumber() const
{
    return phoneNumber;
}

QString Contact::getAddress() const
{
    return address;
}
