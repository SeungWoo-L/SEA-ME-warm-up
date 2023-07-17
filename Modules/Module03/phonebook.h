#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QObject>
#include <QString>
#include <QVector>
#include "contact.h"

class Phonebook : public QObject {
    Q_OBJECT

private:
    QVector<Contact> contacts;

public:
    Phonebook(QObject *parent = nullptr);

    void ADD(const Contact& contact);
    Contact SEARCH(int index) const;
    void REMOVE(int index);
    QVector<Contact> getAllContacts() const;

    bool isDuplicate(const QString& phoneNumber) const;

    QVector<Contact>& getContacts()
    {
        return contacts;
    }

signals:
    void contactAdded(const Contact& contact);
};

#endif // PHONEBOOK_H
