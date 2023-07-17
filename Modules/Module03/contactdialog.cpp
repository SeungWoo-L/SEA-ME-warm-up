#include "contactdialog.h"
#include "ui_contactdialog.h"
#include "searchdialog.h"

ContactDialog::ContactDialog(SearchDialog* searchDialog, Phonebook* pb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactDialog),
    contact(new Contact("", "", "", "")),
    phonebook(pb),
    searchDialog(searchDialog)
{
    ui->setupUi(this);

    connect(this, SIGNAL(addedcontact(const Contact&)), phonebook, SLOT(ADD(const Contact&)));
}

ContactDialog::~ContactDialog()
{
    delete ui;
    delete contact;
}

void ContactDialog::on_ContactADD_clicked()
{
    QString name = ui->ContactNAME->text();
    QString nickName = ui->ContactNICKNAME->text();
    QString phoneNum = ui->ContactPHONENUM->text();
    QString address = ui->ContactADDRESS->text();

    if (name.isEmpty() || phoneNum.isEmpty() || nickName.isEmpty() || address.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input!!", "Please fill in all required fields.");
        return;
    }
    else {
        Contact newContact(name, nickName, phoneNum, address);
        phonebook->ADD(newContact);

        if (searchDialog) {
            searchDialog->addContactToStoredList(newContact);
        }

        emit addedcontact(newContact);
    }

    ui->ContactNAME->clear();
    ui->ContactNICKNAME->clear();
    ui->ContactPHONENUM->clear();
    ui->ContactADDRESS->clear();
}

void ContactDialog::on_ContactEXIT_clicked()
{
    hide();
}
