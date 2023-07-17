#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include "phonebook.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(Phonebook* pb, QWidget *parent = nullptr);
    ~SearchDialog();
    void showEvent(QShowEvent* event) override;

    void addContactToStoredList(const Contact& contact);

private slots:
    void on_SearchSEARCH_clicked();
    void on_SearchEXIT_clicked();
    void displayContactInformation(int index);

private:
    Ui::SearchDialog *ui;
    Phonebook* phonebook;
};

#endif // SEARCHDIALOG_H
