#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact(const QString& name, const QString& nickname, const QString& phoneNumber, const QString& address);

    QString getName() const;
    QString getNickname() const;
    QString getPhoneNumber() const;
    QString getAddress() const;

private:
    QString name;
    QString nickname;
    QString phoneNumber;
    QString address;
};

#endif // CONTACT_H
