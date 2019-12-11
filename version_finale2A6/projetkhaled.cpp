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
#include <QWidget>
#include <QMediaPlayer>


//####################################################################################################################
//###################################################USER INTERFACE###################################################
//####################################################################################################################
ProjetKhaled::ProjetKhaled(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProjetKhaled)
{
    ui->setupUi(this);
    ui->tabBus_3->setModel(tmpBus.afficher());
    ui->tabFournisseur_3->setModel(tmpFournisseur.afficherFournisseur());
   // ui->cbModifFourni->setModel(tmpFournisseur.comboxidfournis());
   // ui->cbAjoutMat->setModel(tmpMateriel.comboxidMat());
   // ui->cbModifIDBus->setModel(tmpBus.comboxidbus());
    ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());


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


void ProjetKhaled::on_ConfirmerAjoutBus_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
       bool control=true;
       int id=ui->LEImmatriculeBus_3->text().toInt();
       if(id<0 || id>9999){ //control de saisie
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Ajouter id bus"),
                       QObject::tr("ID invlid!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }
       int nbPlace=ui->LENbPlace_3->text().toInt();
       if(nbPlace<0 ||nbPlace>50){
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Ajouter nombre de place bus"),
                       QObject::tr("Nombre de place max est 50!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }
       QString destination=ui->LEDestination_3->text();
       if(destination==""){
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Ajouter destination bus"),
                       QObject::tr("Destination vide!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }
       int idFournisseur=ui->LEIDFournisseur_3->text().toInt();
       if(idFournisseur<0 ||idFournisseur>9999){
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Ajouter id fournisseur bus"),
                       QObject::tr("ID Fourisseur invalid!\n"
                                   "Click Ok to close."), QMessageBox::Ok);

       }
       int idTrajet=ui->LEIDTrajet_3->text().toInt();
       if(idTrajet<0 ||idTrajet>9999){
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Ajouter id trajet bus"),
                       QObject::tr("ID trajet invalid!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }
       int idPlace=ui->LEIDParking_3->text().toInt();
       if(idPlace<0 ||idPlace>9999){
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Ajouter id parking bus"),
                       QObject::tr("ID parking invalid!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }
       QString cinAgent=ui->LECINAgent_3->text();
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
           ui->tabBus_3->setModel(tmpBus.afficher());//refresh
           qDebug()<<"bus ajoute";
       QMessageBox::information(nullptr, QObject::tr("Ajouter un bus"),
                         QObject::tr("Bus ajoute.\n"
                                     "Click Ok to close."), QMessageBox::Ok);

       }
         }else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un bus"),
                         QObject::tr("Erreur !.\n"
                                     "Click Ok to close."), QMessageBox::Ok);

       ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
       ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
        ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
        ui->tabBus_3->setModel(tmpBus.afficher());
        ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
        ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
        ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_ConfirmerModifBus2_3_clicked()
{
    bool control=true;
        QMediaPlayer * music = new QMediaPlayer();
           music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
           music->play();
        int id=ui->cbModifIDBus_3->currentText().toInt();

        int nbPlace=ui->LENbPlaceModif2_3->text().toInt();
        if((nbPlace!=30) && (nbPlace!=50)){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modif nombre des places bus"),
                        QObject::tr("Nombre de place 30 ou 50!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }
        QString destination=ui->LEDestinationModif2_3->text();
       if(destination=="") {
                control = false;
                QMessageBox::critical(nullptr, QObject::tr("Modif destination bus"),
                            QObject::tr("Destination vide!\n"
                                        "Click Ok to close."), QMessageBox::Ok);
            }
       int idFournisseur=ui->cbModifIDFourniBus_3->currentText().toInt();

        int idTrajet=ui->LEIDTrajetModif2_3->text().toInt();
        if(idTrajet<0 ||idTrajet>9999){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modif id trajet bus"),
                        QObject::tr("ID trajet invalid!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }
        int idPlace=ui->LEIDParkingModif2_3->text().toInt();
        if(idPlace<0 ||idPlace>9999){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modif id parking bus"),
                        QObject::tr("ID parking invalid!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }
        QString cinAgent=ui->LECINAgentModif2_3->text();
        if(cinAgent==""){
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Modif CIN conducteur bus"),
                       QObject::tr("CIN Agent vide!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }if (control){
        bus b(id,nbPlace,destination,idFournisseur,idTrajet,idPlace,cinAgent);
        bool test=b.modifier(id);
        if (test){ ui->tabBus_3->setModel(tmpBus.afficher());
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
        ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
        ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
         ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
         ui->tabBus_3->setModel(tmpBus.afficher());
         ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
         ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
         ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());

}

void ProjetKhaled::on_pb_supprimer_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int Immatricule=ui->cbSuppIDBus_3->currentText().toInt();
   // int Immatricule=ui->LEImmatriculeSupprimer->text().toInt();
    bool test=tmpBus.supprimer(Immatricule);
      if (test){
         ui->tabBus_3->setModel(tmpBus.afficher());
         qDebug()<<"bus supprimer";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un bus"),
                       QObject::tr("Bus supprime.\n"
                                   "Click Ok to close."), QMessageBox::Ok);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un bus"),
                       QObject::tr("Erreur !\n"
                                   "Click Ok to close."), QMessageBox::Ok);
      ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
      ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
       ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
       ui->tabBus_3->setModel(tmpBus.afficher());
       ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
       ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
       ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbBusAfficher_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
       ui->tabBus_3->setModel(tmpBus.afficher());
      // QSound::play("qrc:/new/sound/boutton.wav");
       ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
       ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
        ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());

        ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
        ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
        ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbBusRechercher_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int IDBus=ui->LEIDBusRechercher_3->text().toInt();
    bool test=tmpMateriel.recherche(IDBus);
    if(test)
    {ui->tabBus_3->setModel(tmpBus.rechercheBus(IDBus));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur!\n"
                                "Click Ok to close."), QMessageBox::Ok);
}


void ProjetKhaled::on_cbTriBus_6_currentTextChanged(const QString &arg1)
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    if(arg1 == "Immatricule par ordre Croissant"){

         ui->tabBus_3->setModel(tmpBus.triBus());}
            else if(arg1 =="Immatricule par ordre Decroissant"){
       ui->tabBus_3->setModel(tmpBus.triBus2());
    }
            else if(arg1 =="Nombre de place en ordre Croissant"){
                ui->tabBus_3->setModel(tmpBus.triBus3());
    }
            else if(arg1 =="Nombre de place en ordre Decroissant"){
                 ui->tabBus_3->setModel(tmpBus.triBus4());
}
            else if(arg1 =="Destination par ordre Croissant"){
                ui->tabBus_3->setModel(tmpBus.triBus5());}
            else if(arg1 =="Destination par ordre Decroissant"){
                ui->tabBus_3->setModel(tmpBus.triBus6());
        }
}


/*#################################################################################################################
###################################################Fournisseur###################################################
#################################################################################################################*/

void ProjetKhaled::on_pbAjouterFournisseur_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
       bool control=true;
    int idFournisseur=ui->LEIDAjoutFournisseur_3->text().toInt();
    if(idFournisseur<1 ||idFournisseur>9999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id fournisseur"),
                    QObject::tr("ID Invalid\n"
                                "Click Ok to close."), QMessageBox::Ok);}
    QString nomFournisseur=ui->LENomFournisseur_3->text();

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
    ui->tabFournisseur_3->setModel(tmpFournisseur.afficherFournisseur());
    ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
    ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
    ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
   ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
   ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
   ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
    ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbModifierFournisseur_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
        music->play();
        bool control=true;


        int idFournisseur=ui->cbModifFourni_3->currentText().toInt();
        QString nomFournisseur=ui->LENomFournisseurModif2_3->text();
        if(nomFournisseur==""){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modif nom fournisseur"),
                        QObject::tr("Nom vide ou invalide\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
        if (control){


        fournisseur f(idFournisseur,nomFournisseur);
        bool test=f.modifierFournisseur(idFournisseur);
        if (test) { ui->tabFournisseur_3->setModel(tmpFournisseur.afficherFournisseur());
            QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                              QObject::tr("Fournisseur modifie.\n"
                                          "Click Ok to close."), QMessageBox::Ok);

            }
    }          else
                  QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                              QObject::tr("ID is used as in somewhere\n"
                                          "Click Ok to close."), QMessageBox::Ok);
        ui->tabFournisseur_3->setModel(tmpFournisseur.afficherFournisseur());
        ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
        ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
        ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
       ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
       ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
       ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
        ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());

}

void ProjetKhaled::on_pbSupprimerFournisseur_3_clicked()
{

    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
   int idFournisseur=ui->cbSuppFourni_3->currentText().toInt();
    // int idFournisseur=ui->LEIDFournisseurSupprimer->text().toInt();
    bool test=tmpFournisseur.supprimerFournisseur(idFournisseur);
      if (test){
         ui->tabFournisseur_3->setModel(tmpFournisseur.afficherFournisseur());
         qDebug()<<"Fournisseur supprime";
     QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                       QObject::tr("Fournisseur supprime.\n"
                                   "Click Ok to close."), QMessageBox::Ok);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                       QObject::tr("Erreur !\n"
                                   "Click Ok to close."), QMessageBox::Ok);
      ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
      ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
      ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
     ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
     ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
      ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbFournisseurAfficher_3_clicked()
{

    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
     ui->tabFournisseur_3->setModel(tmpFournisseur.afficherFournisseur());
     ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
     ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
     ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
    ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
    ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
    ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
     ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbFournisseurRechercher_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int IDFournisseur=ui->LEIDFournisseurRechercher_3->text().toInt();
    bool test=tmpFournisseur.rechercheFournisseur(IDFournisseur);
    if(test)
    {ui->tabFournisseur_3->setModel(tmpFournisseur.rechercheFournisseur(IDFournisseur));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur! ID doesn't exist!\n"
                                "Click Ok to close."), QMessageBox::Ok);
}

void ProjetKhaled::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    if(arg1 == "ID par ordre Croissant"){

         ui->tabFournisseur_3->setModel(tmpFournisseur.triFournisseur());}
         else if(arg1 =="ID par ordre Decroissant"){
        ui->tabFournisseur_3->setModel(tmpFournisseur.triFournisseur2());
    }
        else if(arg1 =="Nom par ordre Croissant"){
    ui->tabFournisseur_3->setModel(tmpFournisseur.triFournisseur3());
    }
        else if(arg1 =="Nom par ordre Decroissant"){
    ui->tabFournisseur_3->setModel(tmpFournisseur.triFournisseur4());
    }
}

//##############################################################################################################
//###################################################Materiel###################################################
//##############################################################################################################

void ProjetKhaled::on_pbMaterielAjout_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
        music->play();
        bool control=true;
        int id=ui->LEIDMaterielAjout_3->text().toInt();
        if(id<1 || id>9999){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout ID materiel"),
                        QObject::tr("ID Invalide\n"
                                    "Click Ok to close."), QMessageBox::Ok);}


        QString nom=ui->LENomMaterielAjout_3->text();
        if(nom==""){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter nom materiel"),
                        QObject::tr("Nom vide ou invalide\n"
                                    "Click Ok to close."), QMessageBox::Ok);}

        int quantite=ui->LEQuantiteMaterielAjout_3->text().toInt();
        if(quantite<1){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter quantite materiel"),
                        QObject::tr("quantite doit etre superieur a 0\n"
                                    "Click Ok to close."), QMessageBox::Ok);}


        int prix=ui->LEPrixMaterielAjout_3->text().toInt();
        if(prix<1 || prix>999999){
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter prix materiel"),
                        QObject::tr("Prix Invalide\n"
                                    "Click Ok to close."), QMessageBox::Ok);}

        int idFournisseur=ui->cbAjoutMat_3->currentText().toInt();

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
          ui->cbModifIDMat_3->setModel(tmpMateriel.comboxidMat());
          ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());
          ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
          ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
          ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
         ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
         ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
         ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
          ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbMaterielModif2_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
       bool control=true;
    ui->cbModifIDMat_3->setModel(tmpMateriel.comboxidMat());
    int id=ui->cbModifIDMat_3->currentText().toInt();
    QString nom=ui->LENomMaterielModif_3->text();
    if(nom==""){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modification nom materiel"),
                    QObject::tr("Nom vide ou invalide, verifier l'affichage\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int quantite=ui->LEQuantiteMaterielModif_3->text().toInt();
    if(quantite<1){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif quantite materiel"),
                    QObject::tr("quantite doit etre superieur a 0\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int prix=ui->LEPrixMaterielModif_3->text().toInt();
    if(prix<1 || prix>999999){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modif prix materiel"),
                    QObject::tr("Prix Invalide\n"
                                "Click Ok to close."), QMessageBox::Ok);}

    int idFournisseur=ui->cbModifMat_3->currentText().toInt();

    if(control){

    materiel mat(id,nom,quantite,prix,idFournisseur);
    bool test=mat.modifierMateriel(id);
    if (test) { ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());
        qDebug()<<"materiel modifie";
    QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                      QObject::tr("Materiel modifie.\n"
                                  "Click Ok to close."), QMessageBox::Ok);

    }
     } else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                      QObject::tr("Erreur !\n"
                                  "Click Ok to close."), QMessageBox::Ok);
    ui->cbModifIDMat_3->setModel(tmpMateriel.comboxidMat());
    ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());
    ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
    ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
    ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
   ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
   ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
   ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
    ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
      ui->cbSuppIDMat_3->setModel(tmpMateriel.comboxidMat());
}

void ProjetKhaled::on_pbMaterielSupprimer_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
        music->play();

        int IDMateriel=ui->cbSuppIDMat_3->currentText().toInt();
        bool test=tmpMateriel.supprimerMateriel(IDMateriel);
          if (test){
             ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());
             qDebug()<<"Materiel supprime";
         QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                           QObject::tr("Materiel supprime.\n"
                                       "Click Ok to close."), QMessageBox::Ok);

         }
           else
               QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                           QObject::tr("Erreur !\n"
                                       "Click Ok to close."), QMessageBox::Ok);
          ui->cbModifIDMat_3->setModel(tmpMateriel.comboxidMat());
          ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());
          ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
          ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
          ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
         ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
         ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
         ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
          ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
            ui->cbSuppIDMat_3->setModel(tmpMateriel.comboxidMat());
}

void ProjetKhaled::on_pbMaterielAfficher_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
        music->play();

          ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());
            ui->cbSuppIDMat_3->setModel(tmpMateriel.comboxidMat());

            ui->cbModifIDMat_3->setModel(tmpMateriel.comboxidMat());
            ui->tabMateriel_3->setModel(tmpMateriel.afficherMateriel());
            ui->cbModifIDBus_3->setModel(tmpBus.comboxidbus());
            ui->cbSuppIDBus_3->setModel(tmpBus.comboxidbus());
            ui->cbModifIDFourniBus_3->setModel(tmpFournisseur.comboxidfournis());
           ui->cbModifFourni_3->setModel(tmpFournisseur.comboxidfournis());
           ui->cbSuppFourni_3->setModel(tmpFournisseur.comboxidfournis());
           ui->cbAjoutMat_3->setModel(tmpFournisseur.comboxidfournis());
            ui->cbModifMat_3->setModel(tmpFournisseur.comboxidfournis());
}

void ProjetKhaled::on_pbMaterielRechercher_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();
    int IDMateriel=ui->LEIDMaterielRechercher_3->text().toInt();
    bool test=tmpMateriel.recherche(IDMateriel);
    if(test)
    {ui->tabMateriel_3->setModel(tmpMateriel.recherche(IDMateriel));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Erreur!\n"
                                "Click Ok to close."), QMessageBox::Ok);

}

void ProjetKhaled::on_pbStat_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
        music->play();
        statisticBus s;
        s.exec();
}

void ProjetKhaled::on_cbTriBus_5_currentTextChanged(const QString &arg1)
{
    QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
       music->play();

       if(arg1 == "ID materiel par ordre Croissant"){

            ui->tabMateriel_3->setModel(tmpMateriel.tri());}
               else if(arg1 =="ID materiel par ordre Decroissant"){
         ui->tabMateriel_3->setModel(tmpMateriel.tri2());
       }
               else if(arg1 =="Nom materiel par ordre Croissant"){
                   ui->tabMateriel_3->setModel(tmpMateriel.tri3());
       }
               else if(arg1 =="Nom materiel par ordre Decroissant"){
                    ui->tabMateriel_3->setModel(tmpMateriel.tri4());
            }
               else if(arg1 =="Quantite par ordre Croissant"){
                   ui->tabMateriel_3->setModel(tmpMateriel.tri5());}
               else if(arg1 =="Quantite par ordre Decroissant"){
                   ui->tabMateriel_3->setModel(tmpMateriel.tri6());
              }
                else if(arg1 =="Prix par ordre Croissant"){
                   ui->tabMateriel_3->setModel(tmpMateriel.tri7());
           }
                else if(arg1 =="Prix par ordre Decroissant"){
                  ui->tabMateriel_3->setModel(tmpMateriel.tri8());
           }
}

void ProjetKhaled::on_pbMaterielImprimer_3_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
        music->play();

        QPrinter printer;
            QPainter painter;
            printer.setPrinterName("desired printer name");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->tabMateriel_3->render(&printer);
}
