#include "projetsaif.h"
#include "ui_projetsaif.h"
#include <QDebug>
#include <QMessageBox>
projetsaif::projetsaif(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::projetsaif)
{
    ui->setupUi(this);
}

projetsaif::~projetsaif()
{
    delete ui;
}


void projetsaif::on_pbServiceAjouter_clicked()
{

    int id=ui->LEIDServiceAjout->text().toInt();
    QString lib=ui->LELibelleServiceAjout->text();
    int cap=ui->LECapaciteServiceAjout->text().toInt();
    service s(id,lib,cap);
    bool test=s.ajouterService();
    if (test) {
        ui->tabService->setModel(tmpService.afficherService());//refresh
        qDebug()<<"bus ajoute";
    QMessageBox::information(nullptr, QObject::tr("Ajouter un service"),
                      QObject::tr("Service ajoute.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un Service"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void projetsaif::on_pbServiceModif2_clicked()
{
    int id=ui->LEIDServiceModif2->text().toInt();
    QString lib=ui->LELibelleServiceModif2->text();
    int cap=ui->LECapaciteServiceModif2->text().toInt();
    service s(id,lib,cap);
    bool test=s.modifierService(id);
    if (test) ui->tabService->setModel(tmpService.afficherService());
}


void projetsaif::on_pbServiceSupprimer_clicked()
{
    int id=ui->LEIDServiceSupprimer->text().toInt();
    bool test=tmpService.supprimerService(id);
      if (test)
         ui->tabService->setModel(tmpService.afficherService());
}




void projetsaif::on_pbAgentAjout_clicked()
{


    QString cin=ui->LECINAgentAjout->text();
    QString nom=ui->LENomAgentAjout->text();
    QString prenom=ui->LEPrenomAgentAjout->text();
    QString dateNaiss=ui->LEDateNaisAgentAjout->text();
    double salaire=ui->LESalaireAgentAjout->text().toDouble();
    int sexe=ui->LESexeAgentAjout->text().toInt();
    int idService=ui->LEIDServiceAjout->text().toInt();
    agent a(cin,nom,prenom,dateNaiss,salaire,sexe,idService);
    bool test=a.ajouterAgent();
    if (test) {
        ui->tabAgent->setModel(tmpAgent.afficherAgent());//refresh
        qDebug()<<"bus ajoute";
    QMessageBox::information(nullptr, QObject::tr("Ajouter un agent"),
                      QObject::tr("Agent ajoute.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un agent"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}

void projetsaif::on_pbAgentModif2_clicked()
{
    QString cin=ui->LECINAgentModif2->text();
    QString nom=ui->LENomAgentModif2->text();
    QString prenom=ui->LEPrenomAgentModif2->text();
    QString dateNaiss=ui->LEDateNaisAgentModif2->text();
    double salaire=ui->LESalaireAgentModif2->text().toDouble();
    int sexe=ui->LESexeAgentModif2->text().toInt();
    int idService=ui->LEIDServiceModif2->text().toInt();
    agent a(cin,nom,prenom,dateNaiss,salaire,sexe,idService);
    bool test=a.modifierAgent(cin);
    if (test) ui->tabAgent->setModel(tmpAgent.afficherAgent());

}

void projetsaif::on_pbAgentSupprimer_clicked()
{
    QString cin=ui->LECINAgentSupprimer->text();
    bool test=tmpAgent.supprimerAgent(cin);
      if (test)
         ui->tabAgent->setModel(tmpAgent.afficherAgent());
}
