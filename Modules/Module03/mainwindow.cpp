#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , phonebook(new Phonebook)
    , contactDialog(new ContactDialog(nullptr, phonebook))
    , searchDialog(new SearchDialog(phonebook))
    , removeDialog(new RemoveDialog(phonebook))
{
    ui->setupUi(this);

    connect(ui->MainADDBUTTON, SIGNAL(clicked()), this, SLOT(on_MainADDBUTTON_clicked()));
    connect(ui->MainSEARCHBUTTON, SIGNAL(clicked()), this, SLOT(on_MainSEARCHBUTTON_clicked()));
    connect(ui->MainREMOVEBUTTON, SIGNAL(clicked()), this, SLOT(on_MainREMOVEBUTTON_clicked()));
    connect(ui->MainEXIT, SIGNAL(clicked()), this, SLOT(on_MainEXIT_clicked()));
    connect(ui->MainSAVEBUTTON, SIGNAL(clicked()), this, SLOT(on_MainSAVEBUTTON_clicked()), Qt::UniqueConnection);
    connect(ui->SaveLOADBUTTON, SIGNAL(clicked()), this, SLOT(on_SaveLOADBUTTON_clicked()), Qt::UniqueConnection);
    connect(phonebook, SIGNAL(contactAdded(const Contact&)), this, SLOT(onContactAdded(const Contact&)));
}


MainWindow::~MainWindow()
{
    delete ui;
    delete contactDialog;
    delete searchDialog;
    delete removeDialog;
    delete phonebook;
}

void MainWindow::on_MainADDBUTTON_clicked()
{
    contactDialog->show();
}

void MainWindow::on_MainSEARCHBUTTON_clicked()
{
    searchDialog->show();
}

void MainWindow::on_MainREMOVEBUTTON_clicked()
{
    removeDialog->show();
}

void MainWindow::on_MainEXIT_clicked()
{
    close();
}

void MainWindow::onContactAdded(const Contact& contact)
{
    searchDialog->addContactToStoredList(contact);
}

void MainWindow::on_MainSAVEBUTTON_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Contacts", ".", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        if (saveContactsToFile(fileName)) {
            QMessageBox::information(this, "Save Contacts", "Contacts saved successfully!");
            currentFileName = fileName;
        } else {
            QMessageBox::warning(this, "Save Contacts", "Failed to save contacts!");
        }
    }
}

void MainWindow::on_SaveLOADBUTTON_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Load Contacts", ".", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        if (loadContactsFromFile(fileName)) {
            QMessageBox::information(this, "Load Contacts", "Contacts loaded successfully!");
            currentFileName = fileName;
        } else {
            QMessageBox::warning(this, "Load Contacts", "Failed to load contacts!");
        }
    }
}


QString MainWindow::generateDefaultFileName() const
{
    QString dateTimeString = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    return QString("Contacts_%1.txt").arg(dateTimeString);
}

bool MainWindow::saveContactsToFile(const QString& fileName) const
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream stream(&file);
    QVector<Contact> contacts = phonebook->getAllContacts();
    for (const Contact& contact : contacts) {
        stream << contact.getName() << ","
               << contact.getNickname() << ","
               << contact.getPhoneNumber() << ","
               << contact.getAddress() << "\n";
    }

    file.close();
    return true;
}

bool MainWindow::loadContactsFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QVector<Contact> loadedContacts;
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            QString name = fields[0];
            QString nickname = fields[1];
            QString phoneNumber = fields[2];
            QString address = fields[3];
            Contact contact(name, nickname, phoneNumber, address);
            loadedContacts.append(contact);
        }
    }

    file.close();
    phonebook->getContacts() = loadedContacts;
    for (const Contact& contact : loadedContacts) {
        emit phonebook->contactAdded(contact); // Emit a signal for each loaded contact
    }
    return true;
}
