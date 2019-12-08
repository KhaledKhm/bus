#include "projetkhaled.h"
#include "ui_projetkhaled.h"
#include "bus.h"
#include "fournisseur.h"
#include "materiel.h"
//#include "stat.h"
//#include "statistic.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QtCharts/QPieSlice>
#include <QtPrintSupport>
#include <QSound>

#include <QMediaPlayer>


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
   // ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
   // ui->cbAjoutMat->setModel(tmpMateriel.comboxidMat());
   // ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
    ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());


 //   mainLayout=new QVBoxLayout;
  //  mainLayout->addWidget(s.Preparechart());
   // ui->tabMaterielStat->setLayout(mainLayout);

}


ProjetKhaled::~ProjetKhaled()
{
    delete ui;
}




//#########################################################################################################
//###################################################BUS###################################################
//#########################################################################################################

void ProjetKhaled::on_ConfirmerAjoutBus_clicked()
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();
    bool control=true;
    int id=ui->LEImmatriculeBus->text().toInt();
    if(id<0 || id>9999){ //control de saisie
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id bus"),
                    QObject::tr("ID invlid!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    int nbPlace=ui->LENbPlace->text().toInt();
    if(nbPlace<0 ||nbPlace>50){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter nombre de place bus"),
                    QObject::tr("Nombre de place max est 50!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString destination=ui->LEDestination->text();
    if(destination==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter destination bus"),
                    QObject::tr("Destination vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    int idFournisseur=ui->LEIDFournisseur->text().toInt();
    if(idFournisseur<0 ||idFournisseur>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id fournisseur bus"),
                    QObject::tr("ID Fourisseur invalid!\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    int idTrajet=ui->LEIDTrajet->text().toInt();
    if(idTrajet<0 ||idTrajet>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id trajet bus"),
                    QObject::tr("ID trajet invalid!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    int idPlace=ui->LEIDParking->text().toInt();
    if(idPlace<0 ||idPlace>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id parking bus"),
                    QObject::tr("ID parking invalid!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString cinAgent=ui->LECINAgent->text();
     if(cinAgent==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter CIN conducteur bus"),
                    QObject::tr("CIN Agent vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    if (control==true){
    bus b(id,nbPlace,destination,idFournisseur,idTrajet,idPlace,cinAgent);
    bool test=b.ajouter();
    if (test) {
        ui->tabBus->setModel(tmpBus.afficher());//refresh
        qDebug()<<"bus ajoute";
    QMessageBox::information(nullptr, QObject::tr("Ajouter un bus"),
                      QObject::tr("Bus ajoute.\n"
                                  "Click Ok to close."), QMessageBox::Ok);

    }
      }else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un bus"),
                      QObject::tr("Erreur !.\n"
                                  "Click Ok to close."), QMessageBox::Ok);

    ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
    ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
     ui->tabBus->setModel(tmpBus.afficher());
     ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
     ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
     ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_ConfirmerModifBus2_clicked()
{   bool control=true;
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int id=ui->cbModifIDBus->currentText().toInt();

    int nbPlace=ui->LENbPlaceModif2->text().toInt();
    if((nbPlace!=30) && (nbPlace!=50)){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif nombre des places bus"),
                    QObject::tr("Nombre de place 30 ou 50!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString destination=ui->LEDestinationModif2->text();
   if(destination=="") {
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modif destination bus"),
                        QObject::tr("Destination vide!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }
   int idFournisseur=ui->cbModifIDFourniBus->currentText().toInt();

    int idTrajet=ui->LEIDTrajetModif2->text().toInt();
    if(idTrajet<0 ||idTrajet>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif id trajet bus"),
                    QObject::tr("ID trajet invalid!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    int idPlace=ui->LEIDParkingModif2->text().toInt();
    if(idPlace<0 ||idPlace>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif id parking bus"),
                    QObject::tr("ID parking invalid!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString cinAgent=ui->LECINAgentModif2->text();
    if(cinAgent==""){
       control = false;
       QMessageBox::critical(nullptr, QObject::tr("Modif CIN conducteur bus"),
                   QObject::tr("CIN Agent vide!\n"
                               "Click Ok to close."), QMessageBox::Ok);
   }if (control){
    bus b(id,nbPlace,destination,idFournisseur,idTrajet,idPlace,cinAgent);
    bool test=b.modifier(id);
    if (test){ ui->tabBus->setModel(tmpBus.afficher());
    qDebug()<<"bus modifie";
QMessageBox::information(nullptr, QObject::tr("Modifier un bus"),
                  QObject::tr("Bus modifie.\n"
                              "Click Ok to close."), QMessageBox::Ok);
    }
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un bus"),
                  QObject::tr("Erreur !\n"
                              "Click Ok to close."), QMessageBox::Ok);
    ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
    ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
     ui->tabBus->setModel(tmpBus.afficher());
     ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
     ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
     ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());

}

void ProjetKhaled::on_pb_supprimer_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int Immatricule=ui->cbSuppIDBus->currentText().toInt();
   // int Immatricule=ui->LEImmatriculeSupprimer->text().toInt();
    bool test=tmpBus.supprimer(Immatricule);
      if (test){
         ui->tabBus->setModel(tmpBus.afficher());
         qDebug()<<"bus supprimer";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un bus"),
                       QObject::tr("Bus supprime.\n"
                                   "Click Ok to close."), QMessageBox::Ok);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un bus"),
                       QObject::tr("Erreur !\n"
                                   "Click Ok to close."), QMessageBox::Ok);
      ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
      ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
       ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
       ui->tabBus->setModel(tmpBus.afficher());
       ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
       ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
       ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbBusAfficher_clicked()
{   QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();
   // QSound::play("qrc:/new/sound/boutton.wav");
    ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
    ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
     ui->tabBus->setModel(tmpBus.afficher());
     ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
     ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
     ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
}


void ProjetKhaled::on_pbBusRechercher_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int IDBus=ui->LEIDBusRechercher->text().toInt();
    bool test=tmpMateriel.recherche(IDBus);
    if(test)
    {ui->tabBus->setModel(tmpBus.rechercheBus(IDBus));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur!\n"
                                "Click Ok to close."), QMessageBox::Ok);
}



void ProjetKhaled::on_cbTriBus_currentTextChanged(const QString &arg1)
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    if(arg1 == "Immatricule par ordre Croissant"){

         ui->tabBus->setModel(tmpBus.triBus());}
            else if(arg1 =="Immatricule par ordre Decroissant"){
       ui->tabBus->setModel(tmpBus.triBus2());
    }
            else if(arg1 =="Nombre de place en ordre Croissant"){
                ui->tabBus->setModel(tmpBus.triBus3());
    }
            else if(arg1 =="Nombre de place en ordre Decroissant"){
                 ui->tabBus->setModel(tmpBus.triBus4());
}
            else if(arg1 =="Destination par ordre Croissant"){
                ui->tabBus->setModel(tmpBus.triBus5());}
            else if(arg1 =="Destination par ordre Decroissant"){
                ui->tabBus->setModel(tmpBus.triBus6());
        }
    }

/*#################################################################################################################
###################################################Fournisseur###################################################
#################################################################################################################*/

void ProjetKhaled::on_pbAjouterFournisseur_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
       bool control=true;
    int idFournisseur=ui->LEIDAjoutFournisseur->text().toInt();
    if(idFournisseur<1 ||idFournisseur>9999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id fournisseur"),
                    QObject::tr("ID Invalid\n"
                                "Click Ok to close."), QMessageBox::Ok);}
    QString nomFournisseur=ui->LENomFournisseur->text();

    if(nomFournisseur==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter nom fournisseur"),
                    QObject::tr("Nom vide ou invalide\n"
                                "Click Ok to close."), QMessageBox::Ok);}
    if (control){
    fournisseur f(idFournisseur,nomFournisseur);
    bool test=f.ajouterFournisseur();
    if (test) {qDebug()<<"fournisseur ajoute";
        QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                          QObject::tr("Fournisseur ajoute\n"
                                      "Click Ok to close."), QMessageBox::Ok);

    }
   }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                          QObject::tr("Erreur !\n"
                                      "Click Ok to close."), QMessageBox::Ok);
    ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
    ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
    ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
    ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
   ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
   ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
   ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
    ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());

}

void ProjetKhaled::on_pbModifierFournisseur_clicked()
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();
    bool control=true;


    int idFournisseur=ui->cbModifFourni->currentText().toInt();
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
                                      "Click Ok to close."), QMessageBox::Ok);

        }
}          else
              QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("ID is used as in somewhere\n"
                                      "Click Ok to close."), QMessageBox::Ok);
    ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
    ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
    ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
    ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
   ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
   ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
   ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
    ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());

}


void ProjetKhaled::on_pbSupprimerFournisseur_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
   int idFournisseur=ui->cbSuppFourni->currentText().toInt();
    // int idFournisseur=ui->LEIDFournisseurSupprimer->text().toInt();
    bool test=tmpFournisseur.supprimerFournisseur(idFournisseur);
      if (test){
         ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
         qDebug()<<"Fournisseur supprime";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                       QObject::tr("Fournisseur supprime.\n"
                                   "Click Ok to close."), QMessageBox::Ok);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                       QObject::tr("Erreur !\n"
                                   "Click Ok to close."), QMessageBox::Ok);
      ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
      ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
      ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
     ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
     ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
      ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbFournisseurAfficher_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
     ui->tabFournisseur->setModel(tmpFournisseur.afficherFournisseur());
     ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
     ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
     ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
    ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
    ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
    ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbFournisseurRechercher_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int IDFournisseur=ui->LEIDFournisseurRechercher->text().toInt();
    bool test=tmpFournisseur.rechercheFournisseur(IDFournisseur);
    if(test)
    {ui->tabFournisseur->setModel(tmpFournisseur.rechercheFournisseur(IDFournisseur));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur! ID doesn't exist!\n"
                                "Click Ok to close."), QMessageBox::Ok);
}


void ProjetKhaled::on_comboBox_currentTextChanged(const QString &arg1)
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    if(arg1 == "ID par ordre Croissant"){

         ui->tabFournisseur->setModel(tmpFournisseur.triFournisseur());}
         else if(arg1 =="ID par ordre Decroissant"){
        ui->tabFournisseur->setModel(tmpFournisseur.triFournisseur2());
    }
        else if(arg1 =="Nom par ordre Croissant"){
    ui->tabFournisseur->setModel(tmpFournisseur.triFournisseur3());
    }
        else if(arg1 =="Nom par ordre Decroissant"){
    ui->tabFournisseur->setModel(tmpFournisseur.triFournisseur4());
    }
}

//##############################################################################################################
//###################################################Materiel###################################################
//##############################################################################################################

void ProjetKhaled::on_pbMaterielAjout_clicked()
{  QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();
    bool control=true;
    int id=ui->LEIDMaterielAjout->text().toInt();
    if(id<1 || id>9999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajout ID materiel"),
                    QObject::tr("ID Invalide\n"
                                "Click Ok to close."), QMessageBox::Ok);}


    QString nom=ui->LENomMaterielAjout->text();
    if(nom==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter nom materiel"),
                    QObject::tr("Nom vide ou invalide\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int quantite=ui->LEQuantiteMaterielAjout->text().toInt();
    if(quantite<1){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter quantite materiel"),
                    QObject::tr("quantite doit etre superieur a 0\n"
                                "Click Ok to close."), QMessageBox::Ok);}


    int prix=ui->LEPrixMaterielAjout->text().toInt();
    if(prix<1 || prix>999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter prix materiel"),
                    QObject::tr("Prix Invalide\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int idFournisseur=ui->cbAjoutMat->currentText().toInt();

    if(control){
    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.ajouterMateriel();
    if (test){ qDebug()<<"materiel ajoute";
        QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("Materiel ajoute.\n"
                                      "Click Ok to close."), QMessageBox::Ok);

        }
          }else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("Erreur!\n"
                                      "Click Ok to close."), QMessageBox::Ok);
      ui->cbModifIDMat->setModel(tmpMateriel.comboxidMat());
      ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
      ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
      ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
      ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
     ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
     ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
      ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbMaterielModif2_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
       bool control=true;
    ui->cbModifIDMat->setModel(tmpMateriel.comboxidMat());
    int id=ui->cbModifIDMat->currentText().toInt();
    QString nom=ui->LENomMaterielModif->text();
    if(nom==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modification nom materiel"),
                    QObject::tr("Nom vide ou invalide, verifier l'affichage\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int quantite=ui->LEQuantiteMaterielModif->text().toInt();
    if(quantite<1){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif quantite materiel"),
                    QObject::tr("quantite doit etre superieur a 0\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int prix=ui->LEPrixMaterielModif->text().toInt();
    if(prix<1 || prix>999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif prix materiel"),
                    QObject::tr("Prix Invalide\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int idFournisseur=ui->cbModifMat->currentText().toInt();

    if(control){

    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.modifierMateriel(id);
    if (test) { ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
        qDebug()<<"materiel modifie";
    QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                      QObject::tr("Materiel modifie.\n"
                                  "Click Ok to close."), QMessageBox::Ok);

    }
     } else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                      QObject::tr("Erreur !\n"
                                  "Click Ok to close."), QMessageBox::Ok);
    ui->cbModifIDMat->setModel(tmpMateriel.comboxidMat());
    ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
    ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
    ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
    ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
   ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
   ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
   ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
    ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
      ui->cbSuppIDMat->setModel(tmpMateriel.comboxidMat());

}

void ProjetKhaled::on_pbMaterielSupprimer_clicked()
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();

    int IDMateriel=ui->cbSuppIDMat->currentText().toInt();
    bool test=tmpMateriel.supprimerMateriel(IDMateriel);
      if (test){
         ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
         qDebug()<<"Materiel supprime";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                       QObject::tr("Materiel supprime.\n"
                                   "Click Ok to close."), QMessageBox::Ok);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                       QObject::tr("Erreur !\n"
                                   "Click Ok to close."), QMessageBox::Ok);
      ui->cbModifIDMat->setModel(tmpMateriel.comboxidMat());
      ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
      ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
      ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
      ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
     ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
     ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
      ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
        ui->cbSuppIDMat->setModel(tmpMateriel.comboxidMat());
}

void ProjetKhaled::on_pbMaterielAfficher_clicked()
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();

      ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
        ui->cbSuppIDMat->setModel(tmpMateriel.comboxidMat());

        ui->cbModifIDMat->setModel(tmpMateriel.comboxidMat());
        ui->tabMateriel->setModel(tmpMateriel.afficherMateriel());
        ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
        ui->cbSuppIDBus->setModel(tmpBus.comboxidbus());
        ui->cbModifIDFourniBus->setModel(tmpFournisseur.comboxidfournis());
       ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
       ui->cbSuppFourni->setModel(tmpFournisseur.comboxidfournis());
       ui->cbAjoutMat->setModel(tmpFournisseur.comboxidfournis());
        ui->cbModifMat->setModel(tmpFournisseur.comboxidfournis());
}



void ProjetKhaled::on_pbMaterielRechercher_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int IDMateriel=ui->LEIDMaterielRechercher->text().toInt();
    bool test=tmpMateriel.recherche(IDMateriel);
    if(test)
    {ui->tabMateriel->setModel(tmpMateriel.recherche(IDMateriel));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur!\n"
                                "Click Ok to close."), QMessageBox::Ok);

}






void ProjetKhaled::on_pbMaterielTri1Alpha_3_clicked()
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();

    bool test = tmpMateriel.tri2();
    if (test){
    ui->tabMateriel->setModel(tmpMateriel.tri2());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Stat quantite terminer"),
    QObject::tr("Tri quantite terminer.\n"
    "Click ok to exit."), QMessageBox::Ok);
}

void ProjetKhaled::on_pbStat_clicked()
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();
    statistic s;
    s.exec();
}







void ProjetKhaled::on_cbTriBus_2_currentTextChanged(const QString &arg1)
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();

    if(arg1 == "ID materiel par ordre Croissant"){

         ui->tabMateriel->setModel(tmpMateriel.tri());}
            else if(arg1 =="ID materiel par ordre Decroissant"){
      ui->tabMateriel->setModel(tmpMateriel.tri2());
    }
            else if(arg1 =="Nom materiel par ordre Croissant"){
                ui->tabMateriel->setModel(tmpMateriel.tri3());
    }
            else if(arg1 =="Nom materiel par ordre Decroissant"){
                 ui->tabMateriel->setModel(tmpMateriel.tri4());
         }
            else if(arg1 =="Quantite par ordre Croissant"){
                ui->tabMateriel->setModel(tmpMateriel.tri5());}
            else if(arg1 =="Quantite par ordre Decroissant"){
                ui->tabMateriel->setModel(tmpMateriel.tri6());
           }
             else if(arg1 =="Prix par ordre Croissant"){
                ui->tabMateriel->setModel(tmpMateriel.tri7());
        }
             else if(arg1 =="Prix par ordre Decroissant"){
               ui->tabMateriel->setModel(tmpMateriel.tri8());
        }
}

void ProjetKhaled::on_pbMaterielImprimer_clicked()
{ QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
    music->play();

    QPrinter printer;
        QPainter painter;
        printer.setPrinterName("desired printer name");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)return;
        ui->tabMateriel->render(&printer);
}
