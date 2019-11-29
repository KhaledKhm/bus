#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trajet.h"
#include "station.h"
#include "QMessageBox"
#include <QDebug>
#include "mailing/SmtpMime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabStation->setModel(tmpStation.afficher());
    ui->tabTrajet->setModel(tmpTrajet.afficher());

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ajouterStation_clicked(){
    int idStation = ui->idStation->text().toInt();
    QString libelleStation = ui->libelleStation->text();
    QString localisationStation = ui->localisationStation->text();
    int etatStation = ui->etatStation->text().toInt();
    station st(idStation, libelleStation, localisationStation, etatStation);
    bool test = st.ajouter();
    if(test){
        ui->tabStation->setModel(tmpStation.afficher());
        qDebug() <<"Station ajoute";
    }else{
       qDebug() <<"Erreur d'ajout de station";
    }
}

void MainWindow::on_ajouterTrajet_clicked()
{
    int ID = ui->id->text().toInt();
    QString HEUREDEPART = ui->heured->text();
    QString HEUREARRIVEE = ui->heureda->text();
    int IDSTATIONARRET = ui->idT->text().toInt();
    trajet tr(ID,HEUREDEPART,HEUREARRIVEE,IDSTATIONARRET);
    bool test=tr.ajouter();
        if(test)
         {
            ui->tabTrajet->setModel(tmpTrajet.afficher());
            QMessageBox::information(nullptr, QObject::tr("Ajouter"),
                  QObject::tr(" ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
void MainWindow::on_supprimerStation_clicked()
{
    int idStationSuppr = ui->idStationSuppr->text().toInt();
    bool test = tmpStation.supprimer(idStationSuppr);
        if(test)
         {
            ui->tabStation->setModel(tmpStation.afficher());
            QMessageBox::information(nullptr, QObject::tr("supprimer"),
                  QObject::tr("supprimé.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
void MainWindow::on_supprimerTrajet_clicked()
{
    int ID = ui->idTrajetSuppr->text().toInt();
    bool test = tmpTrajet.supprimer(ID);
    if(test)
     {
        ui->tabTrajet->setModel(tmpTrajet.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter"),
              QObject::tr("supprimé.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);}
else
    QMessageBox::critical(nullptr, QObject::tr("supprimer"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifierStation_clicked()
{
    int idStation = ui->idStationModif->text().toInt();
    QString libelleStation = ui->libelleStationModif->text();
    QString localisationStation = ui->localisationStationModif->text();
    int etatStation = ui->etatStationModif->text().toInt();
    station st(idStation, libelleStation, localisationStation, etatStation);
    bool test = tmpStation.modifier(st);
    if(test){
        ui->tabStation->setModel(tmpStation.afficher());
    }
}

void MainWindow::on_modifierTrajet_clicked()
{
    int ID = ui->idTrajetModif->text().toInt();
    int IDSTATIONARRET = ui->idd->text().toInt();
    QString HEUREDEPART = ui->heuredepartTrajetModif->text();
    QString HEUREARRIVEE = ui->heuredepartTrajetModif_2->text();
    trajet tr(ID,HEUREDEPART,HEUREARRIVEE,IDSTATIONARRET);
    bool test = tmpTrajet.modifier();
    if(test)
     {
        ui->tabTrajet->setModel(tmpTrajet.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier"),
              QObject::tr("modifier.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    int i = ui->comboBox->currentIndex();
    ui->tabTrajet->setModel(tmpTrajet.recherche2(arg1,i));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    int i = ui->comboBox_2->currentIndex();
    ui->tabStation->setModel(tmpStation.recherche1(arg1,i));
}

void MainWindow::on_listertrier_2_currentIndexChanged(int index)
{
    if (index==0)
    {
          ui->tabStation->setModel(tmpStation.afficher());
    }
    else
    {
          ui->tabStation->setModel(tmpStation.tri(index));
    }
}

void MainWindow::on_listertrier_currentIndexChanged(int index)
{
    if (index==0)
    {
          ui->tabTrajet->setModel(tmpTrajet.afficher());
    }
    else
    {
          ui->tabTrajet->setModel(tmpTrajet.tri(index));
    }
}

void MainWindow::on_pushButton_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
            QString ch=ui->Textedit->toPlainText();
            smtp.setUser("aziz.mrabet@esprit.tn");
            smtp.setPassword("181JMT0084");
            MimeMessage message;
            message.setSender(new EmailAddress("rayen.bouhjar@esprit.tn", "administration"));
            message.addRecipient(new EmailAddress(ui->adresse->text(), "client"));
            message.setSubject("ATTENTION!!!!!");
            MimeText text;
            text.setText(ch);
            message.addPart(&text);
            smtp.connectToHost();
            smtp.login();
            if(smtp.sendMail(message)){
                QMessageBox::information(this, "OK", "Mail envoyé");
            }else{
                QMessageBox::critical(this, "Erreur", "Mail non envoye");
            }
            smtp.quit();
}

void MainWindow::on_comboBox_stat_type_currentTextChanged()
{
    delete mainLayout;
        mainLayout=new QVBoxLayout ;
        mainLayout->addWidget(s.Preparechart(ui->comboBox_stat_type->currentText(),ui->comboBox_stat_par->currentText()));
        ui->widget_stat->setLayout(mainLayout);
}

void MainWindow::on_comboBox_stat_par_currentTextChanged()
{
    delete mainLayout;
        mainLayout=new QVBoxLayout ;
        mainLayout->addWidget(s.Preparechart(ui->comboBox_stat_type->currentText(),ui->comboBox_stat_par->currentText()));
        ui->widget_stat->setLayout(mainLayout);
}
