#ifndef REMOVEDIALOG_H
#define REMOVEDIALOG_H

#include <QDialog>
#include "phonebook.h"

namespace Ui {
class RemoveDialog;
}

class RemoveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveDialog(Phonebook* pb, QWidget *parent = nullptr);
    ~RemoveDialog();
    void showEvent(QShowEvent* event) override;

private slots:
    void on_RemoveDELETE_clicked();
    void on_RemoveEXIT_clicked();

private:
    Ui::RemoveDialog *ui;
    Phonebook* phonebook;
};

#endif // REMOVEDIALOG_H
