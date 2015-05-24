greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport printsupport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = terminal
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    qcustomplot.cpp \
    plotdialog.cpp \
    datapackagehandler.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    qcustomplot.h \
    plotdialog.h \
    datapackagehandler.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    plotdialog.ui

RESOURCES += \
    terminal.qrc
