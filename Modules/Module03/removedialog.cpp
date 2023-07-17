#include "removedialog.h"
#include "ui_removedialog.h"

RemoveDialog::RemoveDialog(Phonebook* pb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveDialog),
    phonebook(pb)
{
    ui->setupUi(this);
}

RemoveDialog::~RemoveDialog()
{
    delete ui;
}

void RemoveDialog::showEvent(QShowEvent* event)
{
    QDialog::showEvent(event);

    ui->RemoveSTORED->clear();

    QListWidget* removeList = findChild<QListWidget*>("RemoveSTORED");
    if (removeList) {
        QVector<Contact> contacts = phonebook->getAllContacts();
        for (const Contact& contact : contacts) {
            QListWidgetItem* item = new QListWidgetItem();
            item->setText(contact.getName());
            removeList->addItem(item);
        }
    }
}

void RemoveDialog::on_RemoveDELETE_clicked()
{
    QListWidgetItem* selectedItem = ui->RemoveSTORED->currentItem();
    if (selectedItem) {
        int index = ui->RemoveSTORED->row(selectedItem);
        phonebook->REMOVE(index);
        delete selectedItem;
    }
}

void RemoveDialog::on_RemoveEXIT_clicked()
{
    hide();
}
