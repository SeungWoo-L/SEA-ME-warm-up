#ifndef BOOKMARKEDDIALOG_H
#define BOOKMARKEDDIALOG_H

#include <QDialog>
#include "phonebook.h"

namespace Ui {
class BookMarkedDialog;
}

class BookMarkedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookMarkedDialog(Phonebook* pb, QWidget *parent = nullptr);
    ~BookMarkedDialog();

private slots:
    void on_BookmarkedEXIT_clicked();

private:
    Ui::BookMarkedDialog *ui;
    Phonebook* phonebook;
};

#endif // BOOKMARKEDDIALOG_H
