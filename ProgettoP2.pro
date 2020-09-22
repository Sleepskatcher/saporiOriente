QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProgettoP2
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GERARCHIA/gerarchia.cpp \
    GUI/avviso.cpp \
    GUI/controller.cpp \
    GUI/inserisci.cpp \
    GUI/inserisciDolce.cpp \
    GUI/layoutPrinc.cpp \
    GUI/menuCompleto.cpp \
    GUI/menuIniziale.cpp \
    GUI/paginaModifica.cpp \
    GUI/paginaModificaDolce.cpp \
    GUI/piattiLista.cpp \
    GUI/piattoWidget.cpp \
    GUI/ricerca.cpp \
    main.cpp \
    modello.cpp

HEADERS += \
    GERARCHIA/gerarchia.h \
    GUI/avviso.h \
    GUI/controller.h \
    GUI/inserisci.h \
    GUI/inserisciDolce.h \
    GUI/layoutPrinc.h \
    GUI/menuCompleto.h \
    GUI/menuIniziale.h \
    GUI/paginaModifica.h \
    GUI/paginaModificaDolce.h \
    GUI/piattiLista.h \
    GUI/piattoWidget.h \
    GUI/ricerca.h \
    container.h \
    modello.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
