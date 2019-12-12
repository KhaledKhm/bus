#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_seConnecter_clicked()
{
    Menu choix;
    QString id = ui->login->text();
    QString mdp = ui->mdp->text();
    if ((id !="Admin") || (mdp!="Admin")){
           QMessageBox::information(nullptr, QObject::tr("Erreur de connexion"),
                       QObject::tr("Erreur de connexion.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::information(nullptr, QObject::tr("Connexion "),
                    QObject::tr("Jawek behi.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    close();
    choix.exec();
}
}
