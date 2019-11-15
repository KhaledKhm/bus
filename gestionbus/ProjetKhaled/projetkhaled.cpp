#include "projetkhaled.h"
#include "ui_projetkhaled.h"
#include "bus.h"
#include "fournisseur.h"
#include "materiel.h"
#include <QDebug>
#include <QMessageBox>
ProjetKhaled::ProjetKhaled(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProjetKhaled)
{
    ui->setupUi(this);
    ui->tabBus->setModel(tmpBus.afficher());
    ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
    ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());


}

ProjetKhaled::~ProjetKhaled()
{
    delete ui;
}


void ProjetKhaled::on_ConfirmerAjoutBus_clicked()
{

    int id=ui->LEImmatriculeBus->text().toInt();
    int nbPlace=ui->LENbPlace->text().toInt();
    QString destination=ui->LEDestination->text();
    int idFournisseur=ui->LEIDFournisseur->text().toInt();
    int idTrajet=ui->LEIDTrajet->text().toInt();
    int idPlace=ui->LEIDParking->text().toInt();
    QString cinAgent=ui->LECINAgent->text();
    bus b(id,nbPlace,destination,idFournisseur,idTrajet,idPlace,cinAgent);
    bool test=b.ajouter();
    if (test) {
        ui->tabBus->setModel(tmpBus.afficher());//refresh
        qDebug()<<"bus ajoute";
    QMessageBox::information(nullptr, QObject::tr("Ajouter un bus"),
                      QObject::tr("Bus ajoute.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un bus"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

void ProjetKhaled::on_ConfirmerModifBus2_clicked()
{
    int id=ui->LEImmatriculeModif2->text().toInt();
    int nbPlace=ui->LENbPlaceModif2->text().toInt();
    QString destination=ui->LEDestinationModif2->text();
    int idFournisseur=ui->LEIDFournisseurModif2->text().toInt();
    int idTrajet=ui->LEIDTrajetModif2->text().toInt();
    int idPlace=ui->LEIDParkingModif2->text().toInt();
    QString cinAgent=ui->LECINAgentModif2->text();
    bus b(id,nbPlace,destination,idFournisseur,idTrajet,idPlace,cinAgent);
    bool test=b.modifier(id);
    if (test){ ui->tabBus->setModel(tmpBus.afficher());
    qDebug()<<"bus modifie";
QMessageBox::information(nullptr, QObject::tr("Modifier un bus"),
                  QObject::tr("Bus modifie.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un bus"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void ProjetKhaled::on_pb_supprimer_clicked()
{
    int Immatricule=ui->LEImmatriculeSupprimer->text().toInt();
    bool test=tmpBus.supprimer(Immatricule);
      if (test)
         ui->tabBus->setModel(tmpBus.afficher());

}




void ProjetKhaled::on_pbAjouterFournisseur_clicked()
{
    int idFournisseur=ui->LEIDAjoutFournisseur->text().toInt();
    QString nomFournisseur=ui->LENomFournisseur->text();
    fournisseur f(idFournisseur,nomFournisseur);
    bool test=f.ajouterFournisseur();
    if (test) qDebug()<<"fournisseur ajoute";
}




void ProjetKhaled::on_pbModifierFournisseur_clicked()
{
    int idFournisseur=ui->LEIDAjoutFournisseur->text().toInt();
    QString nomFournisseur=ui->LENomFournisseur->text();
    fournisseur f(idFournisseur,nomFournisseur);
    bool test=f.modifierFournisseur(idFournisseur);
    if (test) ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
}

void ProjetKhaled::on_pbSupprimerFournisseur_clicked()
{
    int idFournisseur=ui->LEIDFournisseurSupprimer->text().toInt();
    bool test=tmpFournisseur.supprimerFournisseur(idFournisseur);
      if (test)
         ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
}



void ProjetKhaled::on_pbMaterielAjout_clicked()
{
    int id=ui->LEIDMaterielAjout->text().toInt();
    QString nom=ui->LENomMaterielAjout->text();
    int quantite=ui->LEQuantiteMaterielAjout->text().toInt();
    int prix=ui->LEPrixMaterielAjout->text().toInt();
    int idFournisseur=ui->LEIDFournisseurMaterielAjout->text().toInt();
    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.ajouterMateriel();
    if (test) qDebug()<<"materiel ajoute";
}



void ProjetKhaled::on_pbMaterielModif2_clicked()
{
    int id=ui->LEIDMaterielModif->text().toInt();
    QString nom=ui->LENomMaterielModif->text();
    int quantite=ui->LEQuantiteMaterielModif->text().toInt();
    int prix=ui->LEPrixMaterielModif->text().toInt();
    int idFournisseur=ui->LEIDFournisseurMaterielModif->text().toInt();
    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.modifierMateriel(id);
    if (test) ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());

}

void ProjetKhaled::on_pbMaterielSupprimer_clicked()
{
    int IDMateriel=ui->LEIDMaterielSupprimer->text().toInt();
    bool test=tmpMateriel.supprimerMateriel(IDMateriel);
      if (test)
         ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
}
