#include "bookmarkeddialog.h"
#include "ui_bookmarkeddialog.h"

BookMarkedDialog::BookMarkedDialog(Phonebook* pb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookMarkedDialog),
    phonebook(pb)
{
    ui->setupUi(this);
}

BookMarkedDialog::~BookMarkedDialog()
{
    delete ui;
}

void BookMarkedDialog::on_BookmarkedEXIT_clicked()
{
    hide();
}
