#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "contact.h"
#include "phonebook.h"

class SearchDialog;

namespace Ui {
class ContactDialog;
}

class ContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContactDialog(SearchDialog* searchDialog, Phonebook* pb, QWidget *parent = nullptr);
    ~ContactDialog();

private slots:
    void on_ContactADD_clicked();
    void on_ContactEXIT_clicked();

signals:
    void addedcontact(const Contact&);

private:
    Ui::ContactDialog *ui;
    Contact *contact;
    Phonebook* phonebook;
    SearchDialog* searchDialog;
};

#endif // CONTACTDIALOG_H
