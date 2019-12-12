QT       += core gui sql charts printsupport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    abonnement_el.cpp \
    abonnement_normal.cpp \
    connection.cpp \
    conv.cpp \
    even.cpp \
    gerer_abonne.cpp \
    gerer_evenement.cpp \
    gerer_parking.cpp \
    liste_abonnement.cpp \
    mailing/emailaddress.cpp \
    mailing/mimeattachment.cpp \
    mailing/mimecontentformatter.cpp \
    mailing/mimefile.cpp \
    mailing/mimehtml.cpp \
    mailing/mimeinlinefile.cpp \
    mailing/mimemessage.cpp \
    mailing/mimemultipart.cpp \
    mailing/mimepart.cpp \
    mailing/mimetext.cpp \
    mailing/quotedprintable.cpp \
    mailing/smtpclient.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    parking.cpp \
    place.cpp \
    rem.cpp \
    stat2.cpp \
    stateven.cpp \
    statistique.cpp

HEADERS += \
    abonnement_el.h \
    abonnement_normal.h \
    connection.h \
    conv.h \
    even.h \
    gerer_abonne.h \
    gerer_evenement.h \
    gerer_parking.h \
    liste_abonnement.h \
    mailing/SmtpMime \
    mailing/emailaddress.h \
    mailing/mimeattachment.h \
    mailing/mimecontentformatter.h \
    mailing/mimefile.h \
    mailing/mimehtml.h \
    mailing/mimeinlinefile.h \
    mailing/mimemessage.h \
    mailing/mimemultipart.h \
    mailing/mimepart.h \
    mailing/mimetext.h \
    mailing/quotedprintable.h \
    mailing/smtpclient.h \
    mailing/smtpexports.h \
    mainwindow.h \
    menu.h \
    parking.h \
    place.h \
    rem.h \
    stat2.h \
    stateven.h \
    statistique.h

FORMS += \
    gerer_abonne.ui \
    gerer_evenement.ui \
    gerer_parking.ui \
    mainwindow.ui \
    menu.ui \
    statistique.ui

RC_ICONS = myappico.ico

QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
