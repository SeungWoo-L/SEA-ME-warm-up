QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contact.cpp \
    contactdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    phonebook.cpp \
    removedialog.cpp \
    searchdialog.cpp

HEADERS += \
    contact.h \
    contactdialog.h \
    mainwindow.h \
    phonebook.h \
    removedialog.h \
    searchdialog.h

FORMS += \
    contactdialog.ui \
    mainwindow.ui \
    removedialog.ui \
    searchdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
