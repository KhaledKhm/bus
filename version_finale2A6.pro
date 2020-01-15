QT       += core gui sql charts printsupport network multimedia serialport

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
    agent.cpp \
    arduino_temp.cpp \
    bus.cpp \
    captemperature.cpp \
    connection.cpp \
    conv.cpp \
    donutbreakdownchart.cpp \
    even.cpp \
    fournisseur.cpp \
    gerer_abonne.cpp \
    gerer_agent.cpp \
    gerer_evenement.cpp \
    gerer_parking.cpp \
    gerer_trajet.cpp \
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
    mainslice.cpp \
    mainwindow.cpp \
    materiel.cpp \
    menu.cpp \
    parking.cpp \
    place.cpp \
    projetkhaled.cpp \
    rem.cpp \
    service.cpp \
    stat2.cpp \
    stat_ray.cpp \
    stateven.cpp \
    station_ray.cpp \
    statistic.cpp \
    statisticbus.cpp \
    statistique.cpp \
    statservice.cpp \
    trajet_ray.cpp

HEADERS += \
    abonnement_el.h \
    abonnement_normal.h \
    agent.h \
    arduino_temp.h \
    bus.h \
    captemperature.h \
    connection.h \
    conv.h \
    donutbreakdownchart.h \
    even.h \
    fournisseur.h \
    gerer_abonne.h \
    gerer_agent.h \
    gerer_evenement.h \
    gerer_parking.h \
    gerer_trajet.h \
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
    mainslice.h \
    mainwindow.h \
    materiel.h \
    menu.h \
    parking.h \
    place.h \
    projetkhaled.h \
    rem.h \
    service.h \
    stat2.h \
    stat_ray.h \
    stateven.h \
    station_ray.h \
    statistic.h \
    statisticbus.h \
    statistique.h \
    statservice.h \
    trajet_ray.h

FORMS += \
    arduino_temp.ui \
    gerer_abonne.ui \
    gerer_agent.ui \
    gerer_evenement.ui \
    gerer_parking.ui \
    gerer_trajet.ui \
    mainwindow.ui \
    menu.ui \
    projetkhaled.ui \
    statistic.ui \
    statisticbus.ui \
    statistique.ui \
    statservice.ui

RC_ICONS = myappico.ico

QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    houaida.qrc \
    res.qrc \
    res.qrc \
    sound.qrc

DISTFILES +=
