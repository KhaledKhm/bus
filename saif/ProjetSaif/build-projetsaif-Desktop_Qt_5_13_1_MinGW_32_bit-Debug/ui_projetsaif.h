/********************************************************************************
** Form generated from reading UI file 'projetsaif.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETSAIF_H
#define UI_PROJETSAIF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_projetsaif
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QPushButton *ajouterBusAnnuler;
    QPushButton *pbAgentAjout;
    QLabel *LabelDestination;
    QLabel *LabelImmatricuteBus;
    QLineEdit *LECINAgentAjout;
    QLineEdit *LEPrenomAgentAjout;
    QLineEdit *LENomAgentAjout;
    QLabel *LabelIDConducteur;
    QLabel *LabelNbPlace;
    QLineEdit *LEIDServiceAgentAjout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *LEDateNaisAgentAjout;
    QLineEdit *LESalaireAgentAjout;
    QLineEdit *LESexeAgentAjout;
    QWidget *tab_4;
    QTabWidget *tabWidget_4;
    QWidget *tab_11;
    QLabel *labelModifierBus;
    QPushButton *ConfirmerModifBus1;
    QPushButton *modifierBusRetourner;
    QLineEdit *LEModifierBus;
    QWidget *tab_12;
    QLineEdit *LEIDServiceAgentModif2;
    QPushButton *ajouterBusAnnuler_2;
    QLabel *LabelImmatricuteBus_2;
    QLineEdit *LESalaireAgentModif2;
    QLabel *LabelIDConducteur_2;
    QLineEdit *LEDateNaisAgentModif2;
    QLineEdit *LENomAgentModif2;
    QLabel *label_5;
    QPushButton *pbAgentModif2;
    QLineEdit *LESexeAgentModif2;
    QLabel *LabelDestination_2;
    QLabel *LabelNbPlace_2;
    QLineEdit *LECINAgentModif2;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *LEPrenomAgentModif2;
    QWidget *tab_5;
    QLabel *label_10;
    QPushButton *pbAgentSupprimer;
    QLineEdit *LECINAgentSupprimer;
    QWidget *tab_6;
    QTableView *tabAgent;
    QWidget *tab_2;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QLabel *LabelImmatricuteBus_8;
    QLineEdit *LEIDServiceAjout;
    QLineEdit *LELibelleServiceAjout;
    QLabel *LabelNbPlace_8;
    QPushButton *pbServiceAjouter;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QLineEdit *LECapaciteServiceAjout;
    QWidget *tab_8;
    QLabel *LabelImmatricuteBus_12;
    QLineEdit *LELibelleServiceModif2;
    QPushButton *pushButton_6;
    QLineEdit *LEIDServiceModif2;
    QLineEdit *LECapaciteServiceModif2;
    QLabel *label_9;
    QLabel *LabelNbPlace_10;
    QPushButton *pbServiceModif2;
    QWidget *tab_9;
    QPushButton *pushButton_7;
    QPushButton *pbServiceSupprimer;
    QLineEdit *LEIDServiceSupprimer;
    QLabel *LabelImmatricuteBus_13;
    QWidget *tab_10;
    QTableView *tabService;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *projetsaif)
    {
        if (projetsaif->objectName().isEmpty())
            projetsaif->setObjectName(QString::fromUtf8("projetsaif"));
        projetsaif->resize(800, 600);
        centralwidget = new QWidget(projetsaif);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 571));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(-10, 0, 801, 541));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        ajouterBusAnnuler = new QPushButton(tab_3);
        ajouterBusAnnuler->setObjectName(QString::fromUtf8("ajouterBusAnnuler"));
        ajouterBusAnnuler->setGeometry(QRect(280, 420, 93, 28));
        ajouterBusAnnuler->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        pbAgentAjout = new QPushButton(tab_3);
        pbAgentAjout->setObjectName(QString::fromUtf8("pbAgentAjout"));
        pbAgentAjout->setGeometry(QRect(80, 420, 93, 28));
        pbAgentAjout->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LabelDestination = new QLabel(tab_3);
        LabelDestination->setObjectName(QString::fromUtf8("LabelDestination"));
        LabelDestination->setGeometry(QRect(10, 110, 181, 41));
        LabelDestination->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LabelImmatricuteBus = new QLabel(tab_3);
        LabelImmatricuteBus->setObjectName(QString::fromUtf8("LabelImmatricuteBus"));
        LabelImmatricuteBus->setGeometry(QRect(10, 0, 181, 41));
        LabelImmatricuteBus->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LECINAgentAjout = new QLineEdit(tab_3);
        LECINAgentAjout->setObjectName(QString::fromUtf8("LECINAgentAjout"));
        LECINAgentAjout->setGeometry(QRect(210, 10, 261, 31));
        LEPrenomAgentAjout = new QLineEdit(tab_3);
        LEPrenomAgentAjout->setObjectName(QString::fromUtf8("LEPrenomAgentAjout"));
        LEPrenomAgentAjout->setGeometry(QRect(210, 120, 261, 31));
        LENomAgentAjout = new QLineEdit(tab_3);
        LENomAgentAjout->setObjectName(QString::fromUtf8("LENomAgentAjout"));
        LENomAgentAjout->setGeometry(QRect(210, 70, 261, 31));
        LabelIDConducteur = new QLabel(tab_3);
        LabelIDConducteur->setObjectName(QString::fromUtf8("LabelIDConducteur"));
        LabelIDConducteur->setGeometry(QRect(10, 340, 181, 41));
        LabelIDConducteur->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LabelNbPlace = new QLabel(tab_3);
        LabelNbPlace->setObjectName(QString::fromUtf8("LabelNbPlace"));
        LabelNbPlace->setGeometry(QRect(10, 60, 181, 41));
        LabelNbPlace->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LEIDServiceAgentAjout = new QLineEdit(tab_3);
        LEIDServiceAgentAjout->setObjectName(QString::fromUtf8("LEIDServiceAgentAjout"));
        LEIDServiceAgentAjout->setGeometry(QRect(210, 350, 261, 31));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 190, 111, 20));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 240, 101, 20));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 300, 151, 16));
        LEDateNaisAgentAjout = new QLineEdit(tab_3);
        LEDateNaisAgentAjout->setObjectName(QString::fromUtf8("LEDateNaisAgentAjout"));
        LEDateNaisAgentAjout->setGeometry(QRect(210, 180, 261, 31));
        LESalaireAgentAjout = new QLineEdit(tab_3);
        LESalaireAgentAjout->setObjectName(QString::fromUtf8("LESalaireAgentAjout"));
        LESalaireAgentAjout->setGeometry(QRect(210, 240, 261, 31));
        LESexeAgentAjout = new QLineEdit(tab_3);
        LESexeAgentAjout->setObjectName(QString::fromUtf8("LESexeAgentAjout"));
        LESexeAgentAjout->setGeometry(QRect(210, 290, 261, 31));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_4 = new QTabWidget(tab_4);
        tabWidget_4->setObjectName(QString::fromUtf8("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(0, 0, 811, 521));
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        labelModifierBus = new QLabel(tab_11);
        labelModifierBus->setObjectName(QString::fromUtf8("labelModifierBus"));
        labelModifierBus->setGeometry(QRect(20, 10, 381, 20));
        labelModifierBus->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        ConfirmerModifBus1 = new QPushButton(tab_11);
        ConfirmerModifBus1->setObjectName(QString::fromUtf8("ConfirmerModifBus1"));
        ConfirmerModifBus1->setGeometry(QRect(70, 150, 93, 28));
        modifierBusRetourner = new QPushButton(tab_11);
        modifierBusRetourner->setObjectName(QString::fromUtf8("modifierBusRetourner"));
        modifierBusRetourner->setGeometry(QRect(230, 150, 93, 28));
        LEModifierBus = new QLineEdit(tab_11);
        LEModifierBus->setObjectName(QString::fromUtf8("LEModifierBus"));
        LEModifierBus->setGeometry(QRect(100, 70, 181, 22));
        tabWidget_4->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        LEIDServiceAgentModif2 = new QLineEdit(tab_12);
        LEIDServiceAgentModif2->setObjectName(QString::fromUtf8("LEIDServiceAgentModif2"));
        LEIDServiceAgentModif2->setGeometry(QRect(210, 350, 261, 31));
        ajouterBusAnnuler_2 = new QPushButton(tab_12);
        ajouterBusAnnuler_2->setObjectName(QString::fromUtf8("ajouterBusAnnuler_2"));
        ajouterBusAnnuler_2->setGeometry(QRect(280, 420, 93, 28));
        ajouterBusAnnuler_2->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LabelImmatricuteBus_2 = new QLabel(tab_12);
        LabelImmatricuteBus_2->setObjectName(QString::fromUtf8("LabelImmatricuteBus_2"));
        LabelImmatricuteBus_2->setGeometry(QRect(10, 0, 181, 41));
        LabelImmatricuteBus_2->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LESalaireAgentModif2 = new QLineEdit(tab_12);
        LESalaireAgentModif2->setObjectName(QString::fromUtf8("LESalaireAgentModif2"));
        LESalaireAgentModif2->setGeometry(QRect(210, 240, 261, 31));
        LabelIDConducteur_2 = new QLabel(tab_12);
        LabelIDConducteur_2->setObjectName(QString::fromUtf8("LabelIDConducteur_2"));
        LabelIDConducteur_2->setGeometry(QRect(10, 340, 181, 41));
        LabelIDConducteur_2->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LEDateNaisAgentModif2 = new QLineEdit(tab_12);
        LEDateNaisAgentModif2->setObjectName(QString::fromUtf8("LEDateNaisAgentModif2"));
        LEDateNaisAgentModif2->setGeometry(QRect(210, 180, 261, 31));
        LENomAgentModif2 = new QLineEdit(tab_12);
        LENomAgentModif2->setObjectName(QString::fromUtf8("LENomAgentModif2"));
        LENomAgentModif2->setGeometry(QRect(210, 70, 261, 31));
        label_5 = new QLabel(tab_12);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 190, 111, 20));
        pbAgentModif2 = new QPushButton(tab_12);
        pbAgentModif2->setObjectName(QString::fromUtf8("pbAgentModif2"));
        pbAgentModif2->setGeometry(QRect(80, 420, 93, 28));
        pbAgentModif2->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LESexeAgentModif2 = new QLineEdit(tab_12);
        LESexeAgentModif2->setObjectName(QString::fromUtf8("LESexeAgentModif2"));
        LESexeAgentModif2->setGeometry(QRect(210, 290, 261, 31));
        LabelDestination_2 = new QLabel(tab_12);
        LabelDestination_2->setObjectName(QString::fromUtf8("LabelDestination_2"));
        LabelDestination_2->setGeometry(QRect(10, 110, 181, 41));
        LabelDestination_2->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LabelNbPlace_2 = new QLabel(tab_12);
        LabelNbPlace_2->setObjectName(QString::fromUtf8("LabelNbPlace_2"));
        LabelNbPlace_2->setGeometry(QRect(10, 60, 181, 41));
        LabelNbPlace_2->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LECINAgentModif2 = new QLineEdit(tab_12);
        LECINAgentModif2->setObjectName(QString::fromUtf8("LECINAgentModif2"));
        LECINAgentModif2->setGeometry(QRect(210, 10, 261, 31));
        label_6 = new QLabel(tab_12);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 300, 151, 16));
        label_4 = new QLabel(tab_12);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 240, 101, 20));
        LEPrenomAgentModif2 = new QLineEdit(tab_12);
        LEPrenomAgentModif2->setObjectName(QString::fromUtf8("LEPrenomAgentModif2"));
        LEPrenomAgentModif2->setGeometry(QRect(210, 120, 261, 31));
        tabWidget_4->addTab(tab_12, QString());
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 40, 81, 20));
        pbAgentSupprimer = new QPushButton(tab_5);
        pbAgentSupprimer->setObjectName(QString::fromUtf8("pbAgentSupprimer"));
        pbAgentSupprimer->setGeometry(QRect(240, 150, 75, 23));
        LECINAgentSupprimer = new QLineEdit(tab_5);
        LECINAgentSupprimer->setObjectName(QString::fromUtf8("LECINAgentSupprimer"));
        LECINAgentSupprimer->setGeometry(QRect(140, 40, 113, 20));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabAgent = new QTableView(tab_6);
        tabAgent->setObjectName(QString::fromUtf8("tabAgent"));
        tabAgent->setGeometry(QRect(10, 0, 641, 421));
        tabWidget_2->addTab(tab_6, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_3 = new QTabWidget(tab_2);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(0, 0, 801, 541));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        LabelImmatricuteBus_8 = new QLabel(tab_7);
        LabelImmatricuteBus_8->setObjectName(QString::fromUtf8("LabelImmatricuteBus_8"));
        LabelImmatricuteBus_8->setGeometry(QRect(10, 10, 181, 41));
        LabelImmatricuteBus_8->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LEIDServiceAjout = new QLineEdit(tab_7);
        LEIDServiceAjout->setObjectName(QString::fromUtf8("LEIDServiceAjout"));
        LEIDServiceAjout->setGeometry(QRect(210, 20, 261, 31));
        LELibelleServiceAjout = new QLineEdit(tab_7);
        LELibelleServiceAjout->setObjectName(QString::fromUtf8("LELibelleServiceAjout"));
        LELibelleServiceAjout->setGeometry(QRect(210, 80, 261, 31));
        LabelNbPlace_8 = new QLabel(tab_7);
        LabelNbPlace_8->setObjectName(QString::fromUtf8("LabelNbPlace_8"));
        LabelNbPlace_8->setGeometry(QRect(10, 70, 181, 41));
        LabelNbPlace_8->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        pbServiceAjouter = new QPushButton(tab_7);
        pbServiceAjouter->setObjectName(QString::fromUtf8("pbServiceAjouter"));
        pbServiceAjouter->setGeometry(QRect(90, 210, 93, 28));
        pushButton_2 = new QPushButton(tab_7);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 210, 93, 28));
        label_7 = new QLabel(tab_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 150, 55, 16));
        LECapaciteServiceAjout = new QLineEdit(tab_7);
        LECapaciteServiceAjout->setObjectName(QString::fromUtf8("LECapaciteServiceAjout"));
        LECapaciteServiceAjout->setGeometry(QRect(210, 140, 261, 31));
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        LabelImmatricuteBus_12 = new QLabel(tab_8);
        LabelImmatricuteBus_12->setObjectName(QString::fromUtf8("LabelImmatricuteBus_12"));
        LabelImmatricuteBus_12->setGeometry(QRect(0, 20, 181, 41));
        LabelImmatricuteBus_12->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        LELibelleServiceModif2 = new QLineEdit(tab_8);
        LELibelleServiceModif2->setObjectName(QString::fromUtf8("LELibelleServiceModif2"));
        LELibelleServiceModif2->setGeometry(QRect(200, 90, 261, 31));
        pushButton_6 = new QPushButton(tab_8);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(270, 220, 93, 28));
        LEIDServiceModif2 = new QLineEdit(tab_8);
        LEIDServiceModif2->setObjectName(QString::fromUtf8("LEIDServiceModif2"));
        LEIDServiceModif2->setGeometry(QRect(200, 30, 261, 31));
        LECapaciteServiceModif2 = new QLineEdit(tab_8);
        LECapaciteServiceModif2->setObjectName(QString::fromUtf8("LECapaciteServiceModif2"));
        LECapaciteServiceModif2->setGeometry(QRect(200, 150, 261, 31));
        label_9 = new QLabel(tab_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 160, 55, 16));
        LabelNbPlace_10 = new QLabel(tab_8);
        LabelNbPlace_10->setObjectName(QString::fromUtf8("LabelNbPlace_10"));
        LabelNbPlace_10->setGeometry(QRect(0, 80, 181, 41));
        LabelNbPlace_10->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        pbServiceModif2 = new QPushButton(tab_8);
        pbServiceModif2->setObjectName(QString::fromUtf8("pbServiceModif2"));
        pbServiceModif2->setGeometry(QRect(80, 220, 93, 28));
        tabWidget_3->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        pushButton_7 = new QPushButton(tab_9);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(270, 140, 93, 28));
        pbServiceSupprimer = new QPushButton(tab_9);
        pbServiceSupprimer->setObjectName(QString::fromUtf8("pbServiceSupprimer"));
        pbServiceSupprimer->setGeometry(QRect(80, 140, 93, 28));
        LEIDServiceSupprimer = new QLineEdit(tab_9);
        LEIDServiceSupprimer->setObjectName(QString::fromUtf8("LEIDServiceSupprimer"));
        LEIDServiceSupprimer->setGeometry(QRect(210, 30, 261, 31));
        LabelImmatricuteBus_13 = new QLabel(tab_9);
        LabelImmatricuteBus_13->setObjectName(QString::fromUtf8("LabelImmatricuteBus_13"));
        LabelImmatricuteBus_13->setGeometry(QRect(10, 20, 181, 41));
        LabelImmatricuteBus_13->setStyleSheet(QString::fromUtf8("font: 75 8pt \"Times New Roman\";"));
        tabWidget_3->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        tabService = new QTableView(tab_10);
        tabService->setObjectName(QString::fromUtf8("tabService"));
        tabService->setGeometry(QRect(0, 0, 641, 421));
        tabWidget_3->addTab(tab_10, QString());
        tabWidget->addTab(tab_2, QString());
        projetsaif->setCentralWidget(centralwidget);
        menubar = new QMenuBar(projetsaif);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        projetsaif->setMenuBar(menubar);
        statusbar = new QStatusBar(projetsaif);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        projetsaif->setStatusBar(statusbar);

        retranslateUi(projetsaif);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);
        tabWidget_4->setCurrentIndex(1);
        tabWidget_3->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(projetsaif);
    } // setupUi

    void retranslateUi(QMainWindow *projetsaif)
    {
        projetsaif->setWindowTitle(QCoreApplication::translate("projetsaif", "projetsaif", nullptr));
        ajouterBusAnnuler->setText(QCoreApplication::translate("projetsaif", "Annuler", nullptr));
        pbAgentAjout->setText(QCoreApplication::translate("projetsaif", "Confirmer", nullptr));
        LabelDestination->setText(QCoreApplication::translate("projetsaif", "Prenom d'Agent", nullptr));
        LabelImmatricuteBus->setText(QCoreApplication::translate("projetsaif", "CIN d'agent", nullptr));
        LECINAgentAjout->setText(QCoreApplication::translate("projetsaif", "1", nullptr));
        LabelIDConducteur->setText(QCoreApplication::translate("projetsaif", "L'id de service", nullptr));
        LabelNbPlace->setText(QCoreApplication::translate("projetsaif", "Nom d'Agent", nullptr));
        label->setText(QCoreApplication::translate("projetsaif", "Date de naissance", nullptr));
        label_2->setText(QCoreApplication::translate("projetsaif", "Salaire", nullptr));
        label_3->setText(QCoreApplication::translate("projetsaif", "Sexe", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("projetsaif", "Ajouter Agent", nullptr));
        labelModifierBus->setText(QCoreApplication::translate("projetsaif", "Veuillez saisir le CIN de d'agent que vous souhaitez le modifier", nullptr));
        ConfirmerModifBus1->setText(QCoreApplication::translate("projetsaif", "Confirmer", nullptr));
        modifierBusRetourner->setText(QCoreApplication::translate("projetsaif", "Retourner", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_11), QCoreApplication::translate("projetsaif", "Agent a modifier", nullptr));
        ajouterBusAnnuler_2->setText(QCoreApplication::translate("projetsaif", "Annuler", nullptr));
        LabelImmatricuteBus_2->setText(QCoreApplication::translate("projetsaif", "CIN d'agent", nullptr));
        LabelIDConducteur_2->setText(QCoreApplication::translate("projetsaif", "L'id de service", nullptr));
        label_5->setText(QCoreApplication::translate("projetsaif", "Date de naissance", nullptr));
        pbAgentModif2->setText(QCoreApplication::translate("projetsaif", "Confirmer", nullptr));
        LabelDestination_2->setText(QCoreApplication::translate("projetsaif", "Prenom d'Agent", nullptr));
        LabelNbPlace_2->setText(QCoreApplication::translate("projetsaif", "Nom d'Agent", nullptr));
        label_6->setText(QCoreApplication::translate("projetsaif", "Sexe", nullptr));
        label_4->setText(QCoreApplication::translate("projetsaif", "Salaire", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_12), QCoreApplication::translate("projetsaif", "Modification du Agent", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("projetsaif", "Modifier Agent", nullptr));
        label_10->setText(QCoreApplication::translate("projetsaif", "CIN", nullptr));
        pbAgentSupprimer->setText(QCoreApplication::translate("projetsaif", "Supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("projetsaif", "Supprimer Agent", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("projetsaif", "Afficher Agent", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("projetsaif", "Gestion des Agents", nullptr));
        LabelImmatricuteBus_8->setText(QCoreApplication::translate("projetsaif", "ID de service", nullptr));
        LabelNbPlace_8->setText(QCoreApplication::translate("projetsaif", "Libelle service", nullptr));
        pbServiceAjouter->setText(QCoreApplication::translate("projetsaif", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("projetsaif", "Annuler", nullptr));
        label_7->setText(QCoreApplication::translate("projetsaif", "Capacite", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QCoreApplication::translate("projetsaif", "Ajouter Service", nullptr));
        LabelImmatricuteBus_12->setText(QCoreApplication::translate("projetsaif", "ID de service", nullptr));
        pushButton_6->setText(QCoreApplication::translate("projetsaif", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("projetsaif", "Capacite", nullptr));
        LabelNbPlace_10->setText(QCoreApplication::translate("projetsaif", "Libelle service", nullptr));
        pbServiceModif2->setText(QCoreApplication::translate("projetsaif", "Modifier", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QCoreApplication::translate("projetsaif", "Modifier Service", nullptr));
        pushButton_7->setText(QCoreApplication::translate("projetsaif", "Annuler", nullptr));
        pbServiceSupprimer->setText(QCoreApplication::translate("projetsaif", "Supprimer", nullptr));
        LabelImmatricuteBus_13->setText(QCoreApplication::translate("projetsaif", "ID de service", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QCoreApplication::translate("projetsaif", "Supprimer Service", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QCoreApplication::translate("projetsaif", "Afficher Service", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("projetsaif", "Gestion des Service", nullptr));
    } // retranslateUi

};

namespace Ui {
    class projetsaif: public Ui_projetsaif {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETSAIF_H
