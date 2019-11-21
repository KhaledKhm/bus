#include "projetkhaled.h"
#include "ui_projetkhaled.h"
#include "bus.h"
#include "fournisseur.h"
#include "materiel.h"
#include <QDebug>
#include <QMessageBox>



//####################################################################################################################
//###################################################USER INTERFACE###################################################
//####################################################################################################################
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




//#########################################################################################################
//###################################################BUS###################################################
//#########################################################################################################

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
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void ProjetKhaled::on_pb_supprimer_clicked()
{
    int Immatricule=ui->LEImmatriculeSupprimer->text().toInt();
    bool test=tmpBus.supprimer(Immatricule);
      if (test){
         ui->tabBus->setModel(tmpBus.afficher());
         qDebug()<<"bus supprimer";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un bus"),
                       QObject::tr("Bus supprime.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un bus"),
                       QObject::tr("Erreur !\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}

void ProjetKhaled::on_pbBusAfficher_clicked()
{
    ui->tabBus->setModel(tmpBus.afficher());
}




//#################################################################################################################
//###################################################Fournisseur###################################################
//#################################################################################################################

void ProjetKhaled::on_pbAjouterFournisseur_clicked()
{
    int idFournisseur=ui->LEIDAjoutFournisseur->text().toInt();
    QString nomFournisseur=ui->LENomFournisseur->text();
    fournisseur f(idFournisseur,nomFournisseur);
    bool test=f.ajouterFournisseur();
    if (test) {qDebug()<<"fournisseur ajoute";
        QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                          QObject::tr("Fournisseur ajoute\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void ProjetKhaled::on_pbModifierFournisseur_clicked()
{
    int idFournisseur=ui->LEIDFournisseurModif2_2->text().toInt();
    QString nomFournisseur=ui->LENomFournisseurModif2->text();
    fournisseur f(idFournisseur,nomFournisseur);
    bool test=f.modifierFournisseur(idFournisseur);
    if (test) { ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
        QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("Fournisseur modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void ProjetKhaled::on_pbSupprimerFournisseur_clicked()
{
    int idFournisseur=ui->LEIDFournisseurSupprimer->text().toInt();
    bool test=tmpFournisseur.supprimerFournisseur(idFournisseur);
      if (test){
         ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
         qDebug()<<"Fournisseur supprime";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                       QObject::tr("Fournisseur supprime.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                       QObject::tr("Erreur !\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void ProjetKhaled::on_pbFournisseurAfficher_clicked()
{
     ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
}




//##############################################################################################################
//###################################################Materiel###################################################
//##############################################################################################################

void ProjetKhaled::on_pbMaterielAjout_clicked()
{
    int id=ui->LEIDMaterielAjout->text().toInt();
    QString nom=ui->LENomMaterielAjout->text();
    int quantite=ui->LEQuantiteMaterielAjout->text().toInt();
    int prix=ui->LEPrixMaterielAjout->text().toInt();
    int idFournisseur=ui->LEIDFournisseurMaterielAjout->text().toInt();
    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.ajouterMateriel();
    if (test){ qDebug()<<"materiel ajoute";
        QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("Materiel ajoute.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
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
    if (test) { ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
        qDebug()<<"materiel modifie";
    QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                      QObject::tr("Materiel modifie.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                      QObject::tr("Erreur !\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

void ProjetKhaled::on_pbMaterielSupprimer_clicked()
{
    int IDMateriel=ui->LEIDMaterielSupprimer->text().toInt();
    bool test=tmpMateriel.supprimerMateriel(IDMateriel);
      if (test){
         ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
         qDebug()<<"Materiel supprime";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                       QObject::tr("Materiel supprime.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                       QObject::tr("Erreur !\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void ProjetKhaled::on_pbMaterielAfficher_clicked()
{
      ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
}


