#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(Phonebook* pb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog),
    phonebook(pb)
{
    ui->setupUi(this);
    connect(ui->SearchSTORED, &QListWidget::currentRowChanged, this, &SearchDialog::displayContactInformation);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::showEvent(QShowEvent* event)
{
    QDialog::showEvent(event);

    ui->SearchSTORED->clear();

    QListWidget* searchStoredList = findChild<QListWidget*>("SearchSTORED");
    if (searchStoredList) {
        QVector<Contact> contacts = phonebook->getAllContacts();
        for (const Contact& contact : contacts) {
            QListWidgetItem* item = new QListWidgetItem();
            item->setText(contact.getName());
            searchStoredList->addItem(item);
        }
    }
}

void SearchDialog::on_SearchSEARCH_clicked()
{
    QListWidgetItem* selectedItem = ui->SearchSTORED->currentItem();
    if (selectedItem) {
        int index = ui->SearchSTORED->row(selectedItem);
        displayContactInformation(index);
    }
}

void SearchDialog::on_SearchEXIT_clicked()
{
    hide();
}

void SearchDialog::displayContactInformation(int index)
{
    Contact contact = phonebook->SEARCH(index);
    ui->SearchNAME->setText(contact.getName());
    ui->SearchNICKNAME->setText(contact.getNickname());
    ui->SearchPHONENUM->setText(contact.getPhoneNumber());
    ui->SearchADDRESS->setText(contact.getAddress());
}

void SearchDialog::addContactToStoredList(const Contact& contact)
{
    QListWidget* searchStoredList = findChild<QListWidget*>("SearchSTORED");
    if (searchStoredList) {
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(contact.getName());
        searchStoredList->addItem(item);
    }
}
