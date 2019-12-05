#include "projetkhaled.h"
#include "ui_projetkhaled.h"
#include "bus.h"
#include "fournisseur.h"
#include "materiel.h"
#include "stat.h"
//#include "statistic.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtCharts/QPieSlice>
//#include <QMediaPlayer>


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

    mainLayout=new QVBoxLayout;
    mainLayout->addWidget(s.Preparechart());
    ui->tabMaterielStat->setLayout(mainLayout);

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
    bool control=true;
    int id=ui->LEImmatriculeBus->text().toInt();
    if(id<0 || id>9999){ //control de saisie
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id bus"),
                    QObject::tr("ID invlid!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    int nbPlace=ui->LENbPlace->text().toInt();
    if(nbPlace<0 ||nbPlace>50){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter nombre de place bus"),
                    QObject::tr("Nombre de place max est 50!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    QString destination=ui->LEDestination->text();
    if(destination==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter destination bus"),
                    QObject::tr("Destination vide!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    int idFournisseur=ui->LEIDFournisseur->text().toInt();
    if(idFournisseur<0 ||idFournisseur>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id fournisseur bus"),
                    QObject::tr("ID Fourisseur invalid!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    int idTrajet=ui->LEIDTrajet->text().toInt();
    if(idTrajet<0 ||idTrajet>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id trajet bus"),
                    QObject::tr("ID trajet invalid!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    int idPlace=ui->LEIDParking->text().toInt();
    if(idPlace<0 ||idPlace>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id parking bus"),
                    QObject::tr("ID parking invalid!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    QString cinAgent=ui->LECINAgent->text();
     if(cinAgent==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter CIN conducteur bus"),
                    QObject::tr("CIN Agent vide!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if (control==true){
    bus b(id,nbPlace,destination,idFournisseur,idTrajet,idPlace,cinAgent);
    bool test=b.ajouter();
    if (test) {
        ui->tabBus->setModel(tmpBus.afficher());//refresh
        qDebug()<<"bus ajoute";
    QMessageBox::information(nullptr, QObject::tr("Ajouter un bus"),
                      QObject::tr("Bus ajoute.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      }else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un bus"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

void ProjetKhaled::on_ConfirmerModifBus2_clicked()
{   bool control=true;

    int id=ui->LEImmatriculeModif2->text().toInt();
    if(id<0 || id>9999){ //control de saisie
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif immatricule bus"),
                    QObject::tr("ID invlid ou n'existe pas, verifier l'affichage!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    int nbPlace=ui->LENbPlaceModif2->text().toInt();
    if(nbPlace<1 ||nbPlace>50){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif nombre des places bus"),
                    QObject::tr("Nombre de place max est 50!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    QString destination=ui->LEDestinationModif2->text();
    {
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modif destination bus"),
                        QObject::tr("Destination vide!\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    int idFournisseur=ui->LEIDFournisseurModif2->text().toInt();
    if(idFournisseur<0 ||idFournisseur>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif id fournisseur bus"),
                    QObject::tr("ID Fourisseur invalid!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    int idTrajet=ui->LEIDTrajetModif2->text().toInt();
    if(idTrajet<0 ||idTrajet>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif id trajet bus"),
                    QObject::tr("ID trajet invalid!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    int idPlace=ui->LEIDParkingModif2->text().toInt();
    if(idPlace<0 ||idPlace>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif id parking bus"),
                    QObject::tr("ID parking invalid!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    QString cinAgent=ui->LECINAgentModif2->text();
    if(cinAgent==""){
       control = false;
       QMessageBox::critical(nullptr, QObject::tr("Modif CIN conducteur bus"),
                   QObject::tr("CIN Agent vide!\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }if (control){
    bus b(id,nbPlace,destination,idFournisseur,idTrajet,idPlace,cinAgent);
    bool test=b.modifier(id);
    if (test){ ui->tabBus->setModel(tmpBus.afficher());
    qDebug()<<"bus modifie";
QMessageBox::information(nullptr, QObject::tr("Modifier un bus"),
                  QObject::tr("Bus modifie.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
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


void ProjetKhaled::on_pbBusRechercher_clicked()
{
    int IDBus=ui->LEIDBusRechercher->text().toInt();
    bool test=tmpMateriel.recherche(IDBus);
    if(test)
    {ui->tabBus->setModel(tmpBus.rechercheBus(IDBus));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void ProjetKhaled::on_pbBusTri1Alpha_clicked()
{
    bool test = tmpBus.triBus();
    if (test){
    ui->tabBus->setModel(tmpBus.triBus());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri termine"),
    QObject::tr("Tri terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);
}

void ProjetKhaled::on_pbBusTri1Alpha_2_clicked()
{
    bool test = tmpBus.triBus2();
    if (test){
    ui->tabBus->setModel(tmpBus.triBus2());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri termine"),
    QObject::tr("Tri terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);
}


/*#################################################################################################################
###################################################Fournisseur###################################################
#################################################################################################################*/

void ProjetKhaled::on_pbAjouterFournisseur_clicked()
{   bool control=true;
    int idFournisseur=ui->LEIDAjoutFournisseur->text().toInt();
    if(idFournisseur<1 ||idFournisseur>9999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id fournisseur"),
                    QObject::tr("ID Invalid\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    QString nomFournisseur=ui->LENomFournisseur->text();

    if(nomFournisseur==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter nom fournisseur"),
                    QObject::tr("Nom vide ou invalide\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    if (control){
    fournisseur f(idFournisseur,nomFournisseur);
    bool test=f.ajouterFournisseur();
    if (test) {qDebug()<<"fournisseur ajoute";
        QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                          QObject::tr("Fournisseur ajoute\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
   }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void ProjetKhaled::on_pbModifierFournisseur_clicked()
{   bool control=true;
    int idFournisseur=ui->LEIDFournisseurModif2_2->text().toInt();
    if(idFournisseur<1 ||idFournisseur>9999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif id fournisseur"),
                    QObject::tr("ID invalid ou n'existe pas, verifier l'affichage!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    QString nomFournisseur=ui->LENomFournisseurModif2->text();
    if(nomFournisseur==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif nom fournisseur"),
                    QObject::tr("Nom vide ou invalide\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    if (control){

    fournisseur f(idFournisseur,nomFournisseur);
    bool test=f.modifierFournisseur(idFournisseur);
    if (test) { ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
        QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("Fournisseur modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
}          else
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

void ProjetKhaled::on_pbFournisseurRechercher_clicked()
{
    int IDFournisseur=ui->LEIDFournisseurRechercher->text().toInt();
    bool test=tmpFournisseur.rechercheFournisseur(IDFournisseur);
    if(test)
    {ui->tabFournisseur->setModel(tmpFournisseur.rechercheFournisseur(IDFournisseur));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void ProjetKhaled::on_pbFournisseurTri1Alpha_clicked()
{
    bool test = tmpFournisseur.triFournisseur();
    if (test){
    ui->tabFournisseur->setModel(tmpFournisseur.triFournisseur());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri termine"),
    QObject::tr("Tri terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);
}



//##############################################################################################################
//###################################################Materiel###################################################
//##############################################################################################################

void ProjetKhaled::on_pbMaterielAjout_clicked()
{   bool control=true;
    int id=ui->LEIDMaterielAjout->text().toInt();
    if(id<1 || id>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajout ID materiel"),
                    QObject::tr("ID Invalide\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}


    QString nom=ui->LENomMaterielAjout->text();
    if(nom==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter nom materiel"),
                    QObject::tr("Nom vide ou invalide\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    int quantite=ui->LEQuantiteMaterielAjout->text().toInt();
    if(quantite<1){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter quantite materiel"),
                    QObject::tr("quantite doit etre superieur a 0\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}


    int prix=ui->LEPrixMaterielAjout->text().toInt();
    if(prix<1 || prix>999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter prix materiel"),
                    QObject::tr("Prix Invalide\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}


    int idFournisseur=ui->LEIDFournisseurMaterielAjout->text().toInt();
    if(idFournisseur<1 || idFournisseur>99999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter fournisseur materiel"),
                    QObject::tr("ID de fournisseur invalide ou n'existe pas, verifier l'affichage des fournisseurs\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    if(control){
    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.ajouterMateriel();
    if (test){ qDebug()<<"materiel ajoute";
        QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("Materiel ajoute.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          }else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void ProjetKhaled::on_pbMaterielModif2_clicked()
{   bool control=true;
    int id=ui->LEIDMaterielModif->text().toInt();
    if(id<1 || id>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modification materiel"),
                    QObject::tr("ID Invalide ou n'existe pas, verifier laffichage des materiels\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    QString nom=ui->LENomMaterielModif->text();
    if(nom==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modification nom materiel"),
                    QObject::tr("Nom vide ou invalide, verifier l'affichage\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    int quantite=ui->LEQuantiteMaterielModif->text().toInt();
    if(quantite<1){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif quantite materiel"),
                    QObject::tr("quantite doit etre superieur a 0\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    int prix=ui->LEPrixMaterielModif->text().toInt();
    if(prix<1 || prix>999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif prix materiel"),
                    QObject::tr("Prix Invalide\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    int idFournisseur=ui->LEIDFournisseurMaterielModif->text().toInt();
    if(idFournisseur<1 || idFournisseur>99999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif fournisseur materiel"),
                    QObject::tr("ID de fournisseur invalide ou n'existe pas, verifier l'affichage des fournisseurs\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

    if(control){

    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.modifierMateriel(id);
    if (test) { ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
        qDebug()<<"materiel modifie";
    QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                      QObject::tr("Materiel modifie.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
     } else
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


/*
void ProjetKhaled::on_pbStatMaterielPrix_clicked()
{
    bool test = tmpMateriel.stat();
    if (test){
    ui->tabMaterielStat->setModel(tmpMateriel.stat());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Stat prix terminer"),
    QObject::tr("Stat prix terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);


}

void ProjetKhaled::on_pbStatMaterielQuantite_clicked()
{
    bool test = tmpMateriel.statQuantite();
    if (test){
    ui->tabMaterielStat->setModel(tmpMateriel.statQuantite());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Stat quantite terminer"),
    QObject::tr("Stat quantite terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);

}
*/


void ProjetKhaled::on_pbMaterielRechercher_clicked()
{
    int IDMateriel=ui->LEIDMaterielRechercher->text().toInt();
    bool test=tmpMateriel.recherche(IDMateriel);
    if(test)
    {ui->tabMateriel->setModel(tmpMateriel.recherche(IDMateriel));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

/*
void ProjetKhaled::on_pbTriMaterielQuantite_clicked()
{
    bool test = tmpMateriel.triQuantite();
    if (test){
    ui->tabMaterielTri->setModel(tmpMateriel.tri());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Stat quantite terminer"),
    QObject::tr("Tri quantite terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);

}
*/

void ProjetKhaled::on_pbMaterielTri1Alpha_clicked()
{
    bool test = tmpMateriel.tri();
    if (test){
    ui->tabMateriel->setModel(tmpMateriel.tri());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri terminer"),
    QObject::tr("Tri quantite terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);
}







void ProjetKhaled::on_pbMaterielTri1Alpha_3_clicked()
{
    bool test = tmpMateriel.tri2();
    if (test){
    ui->tabMateriel->setModel(tmpMateriel.tri2());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Stat quantite terminer"),
    QObject::tr("Tri quantite terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);
}
