#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contactdialog.h"
#include "searchdialog.h"
#include "removedialog.h"
#include "phonebook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MainADDBUTTON_clicked();
    void on_MainSEARCHBUTTON_clicked();
    void on_MainREMOVEBUTTON_clicked();
    void on_MainEXIT_clicked();
    void onContactAdded(const Contact& contact);
    void on_MainSAVEBUTTON_clicked();
    void on_SaveLOADBUTTON_clicked();

private:
    Ui::MainWindow *ui;
    Phonebook *phonebook;
    ContactDialog *contactDialog;
    SearchDialog *searchDialog;
    RemoveDialog *removeDialog;
    QString currentFileName;

    QString generateDefaultFileName() const;
    bool saveContactsToFile(const QString& fileName) const;
    bool loadContactsFromFile(const QString& fileName);
};

#endif // MAINWINDOW_H
