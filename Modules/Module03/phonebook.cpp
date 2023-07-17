#include "phonebook.h"
#include <QMessageBox>

Phonebook::Phonebook(QObject *parent)
    : QObject(parent)
{
}

void Phonebook::ADD(const Contact& contact)
{
    if (!isDuplicate(contact.getPhoneNumber())) {
        contacts.push_back(contact);
        emit contactAdded(contact);
        QMessageBox::information(nullptr, "Contact Added", "Contact added successfully!");
    }
    else {
        QMessageBox::warning(nullptr, "Duplicate Number", "This Number is already registered. Please enter a different PhoneNumber.");
    }
}

Contact Phonebook::SEARCH(int index) const
{
    if (index < 0 || index >= contacts.size()) {
        // Handle error: index out of range
        return Contact("", "", "", "");
    }
    return contacts[index];
}

void Phonebook::REMOVE(int index)
{
    if (index < 0 || index >= contacts.size()) {
        // Handle error: index out of range
        return;
    }
    contacts.remove(index);
}

QVector<Contact> Phonebook::getAllContacts() const
{
    return contacts;
}

bool Phonebook::isDuplicate(const QString& phoneNumber) const
{
    for (const auto& contact : contacts)
    {
        if (contact.getPhoneNumber() == phoneNumber)
        {
            return true;
        }
    }
    return false;
}
