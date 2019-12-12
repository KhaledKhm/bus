#include "gerer_abonne.h"
#include "ui_gerer_abonne.h"
#include "liste_abonnement.h"
#include "abonnement_el.h"
#include "abonnement_normal.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <iostream>
#include <QMessageBox>
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include "QImage"
#include "statistique.h"
#include "mailing/SmtpMime"

gerer_abonne::gerer_abonne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_abonne)
{
    ui->setupUi(this);
    ui->comboModif->setModel(tmpabonne.combox());
    ui->comboSupp->setModel(tmpabonne.combox());
    ui->conboConv_modif->setModel(tmpconvention.combox());
    ui->conboConv_supp->setModel(tmpconvention.combox());
}

gerer_abonne::~gerer_abonne()
{
    delete ui;
}
//////////////////////////////////////////////////////////////////////////////////////////////

// gestion des abonnés

void gerer_abonne::on_ajouterAbonne_clicked()
{

    ////////////////////////////////////////////////////////////////////////////////
      // mailing
         SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

         smtp.setUser("houaidafatma.karoui@esprit.tn");
         smtp.setPassword("fatma23703032");

         MimeMessage message;

         message.setSender(new EmailAddress("houaidafatma.karoui@esprit.tn", "houaida"));
         message.addRecipient(new EmailAddress(ui->ADRESSE->text(), "yassine"
                                                                    ""));
         message.setSubject("SmtpClient for Qt - Demo");

         MimeText text;

         text.setText("Hi,\n abonnement ajouté ! bienvenue with love .\n");

         message.addPart(&text);

         smtp.connectToHost();
         smtp.login();
         smtp.sendMail(message);
         smtp.quit();
      /////////////////////////////////////////////////////////////////////////


         Abonnement_Normal a;
         liste_Abonnement liste;
    //condition de saisie sur cin
         if( ui->CIN->text().toInt()<100000|| ui->CIN->text().toInt()>999999 || ui->CIN->text().toInt()==0 || ui->CIN->text()=="   *champ obligatoire")
         { if(ui->CIN->text().toInt()==0)
                 ui->CIN->setText("   *champ obligatoire");
             else
                 ui->CIN->setText("   cin non valide");}
          else
             a.set_cin(ui->CIN->text().toInt());

    //condition de saisie sur nom
      if(ui->NOM->text()=="" || ui->NOM->text()=="   *champ obligatoire")
          ui->NOM->setText("   *champ obligatoire");
       else
          a.set_nom(ui->NOM->text());

    //condition de saisie sur prenom
      if(ui->PRENOM->text()=="" || ui->PRENOM->text()=="   *champ obligatoire")
          ui->PRENOM->setText("   *champ obligatoire");
       else
          a.set_prenom(ui->PRENOM->text());

    //condition de saisie sur adresse
      if(ui->ADRESSE->text()=="" || ui->ADRESSE->text()=="   *champ obligatoire")
          ui->ADRESSE->setText("   *champ obligatoire");
       else
          a.set_adresse_mail(ui->ADRESSE->text());


      //condition de saisie sur age
        if( ui->age_ab->text().toInt()<21 || ui->age_ab->text().toInt()>70 || ui->age_ab->text().toInt()==0 || ui->age_ab->text()=="   *champ obligatoire")
        { if(ui->age_ab->text().toInt()==0)
                ui->age_ab->setText("   *champ obligatoire");
            else
                ui->age_ab->setText("   age non valide");}
         else
            a.set_age(ui->age_ab->text().toInt());
        if(false==ui->ETABLISSEMENT->isVisible()){

            int cin=ui->CIN->text().toInt();
            int age=ui->age_ab->text().toInt();
            QString nom=ui->NOM->text();
            QString prenom=ui->PRENOM->text();
            QString email=ui->ADRESSE->text();
            QString date_debut=ui->Date_Debut->text();
            QString date_fin=ui->Date_Fin->text();
            float prix=100;


         if(liste.ajouter_abonnement(cin,nom,prenom,age,email,date_debut,date_fin,prix)==1)
         {

             QMessageBox::information(nullptr, QObject::tr("Ajouter un abonne"),
                                        QObject::tr("abonne ajouté.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
              ui->comboModif->setModel(tmpabonne.combox());
               ui->comboSupp->setModel(tmpabonne.combox());
             }
             else
             {
                 QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonne"),
                             QObject::tr("Erreur d'ajout !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             }
       }
        else if(true==ui->ETABLISSEMENT->isVisible())
       {
            //abonnement eleve

            Abonnement_EL el;
           el=a;

          //condition de saisie sur etablissement
                     if(ui->ETABLISSEMENT->text()=="" || ui->ETABLISSEMENT->text()=="   *champ obligatoire")
                         ui->ETABLISSEMENT->setText("   *champ obligatoire");
                      else
                         el.set_etablissement(ui->ETABLISSEMENT->text());

          if(liste.ajouter_abonnement(el))
              {// ui->message->setText("eleve ajoute avec succes");
               int cin=ui->CIN->text().toInt();
               int age=ui->age_ab->text().toInt();
               QString nom=ui->NOM->text();
               QString prenom=ui->PRENOM->text();
               QString email=ui->ADRESSE->text();
               QString date_debut=ui->Date_Debut->text();
               QString date_fin=ui->Date_Fin->text();
              // QString date_debut=ui->date_debut->text();
            //  QString date_fin=ui->date_fin->text();
               float   prix=ui->PRIX->text().toFloat();
               QString etablissement=ui->ETABLISSEMENT->text();
             //  float prix=60;

               if(liste.ajouter_abonnement(cin,nom,prenom,age,email,date_debut,date_fin,prix)==1)
          {
                   QMessageBox::information(nullptr, QObject::tr("ajouter un eleve"),
                                  QObject::tr("eleve ajouté.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->comboModif->setModel(tmpabonne.combox());
                    ui->comboSupp->setModel(tmpabonne.combox());

          } else {
                   QMessageBox::critical(nullptr, QObject::tr("ajouter un eleve"),
                               QObject::tr("Erreur d'ajout !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}
           }
           /*else {
              // ui->message->setText("Erreur : eleve non ajoute");
              QMessageBox::critical(nullptr, QObject::tr("ajouter un eleve"),
                          QObject::tr("Erreur ! cin existe deja.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
               }*/
        }
}

void gerer_abonne::on_radioButton_Ab_clicked()
{
    ui->ETABLISSEMENT->setVisible(false);
    ui->PRIX->setText("100");
}

void gerer_abonne::on_radioButton_el_clicked()
{
    ui->ETABLISSEMENT->setVisible(true);
    ui->PRIX->setText("60");
}

void gerer_abonne::on_afficher_Ab_clicked()
{
    Abonnement_Normal *A=new Abonnement_Normal();
    ui->tableView_ab->setModel(A->afficher());
}

void gerer_abonne::on_afficher_EL_clicked()
{
    Abonnement_EL *E=new Abonnement_EL();
    ui->tableView_el->setModel(E->afficher());
}

void gerer_abonne::on_Retour_ab_clicked()
{
    hide();
}

void gerer_abonne::on_modifierAbonne_clicked()
{
    int cin = ui->comboModif->currentText().toInt();
    QString nom= ui->nomModif->text();
    QString prenom= ui->PRENOM->text();
    QString email=ui->ADRESSE->text();
    int age = ui->age_ab->text().toInt();
    QString date_debut = ui->Date_Debut->text();
    QString date_fin= ui->Date_Fin->text();
    QString etablissement=ui->ETABLISSEMENT->text();
    float prix = ui->PRIX->text().toFloat();

  Abonnement_Normal a(cin,nom,prenom,age,email,date_debut,date_fin,prix);
  Abonnement_EL el(cin,nom,prenom,age,email,date_debut,date_fin,prix,etablissement);
  bool test=a.modifier();
  bool test2=el.modifier();
  if(test && test2)
{


QMessageBox::information(nullptr, QObject::tr("modifier un abonné"),
                  QObject::tr("abonné modifie.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un abonné "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gerer_abonne::on_supprimerAbonne_clicked()
{
    int cin=ui->comboSupp->currentText().toInt();
     //bool var=tmpabonne.rechercher(cin);
    // bool var2=tmpeleve.rechercher(cin);
 //   if(var || var2)
     //{
         bool test=tmpabonne.supprimerAb(cin);
         bool test2=tmpeleve.supprimerEl(cin);
          if(test || test2)
          {
                     ui->tableView_ab->setModel(tmpabonne.afficher());//refresh
                     ui->tableView_el->setModel(tmpeleve.afficher());//refresh
                     QMessageBox::information(nullptr, QObject::tr("Supprimer un abonné"),
                     QObject::tr("abonne supprimée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->comboSupp->setModel(tmpabonne.combox());
                     ui->comboModif->setModel(tmpabonne.combox());



          }
        else{
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonné"),
                     QObject::tr("Erreur de suppression  !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }
}

void gerer_abonne::on_comboTri_Ab_currentTextChanged(const QString &arg1)
{
    if(arg1 == "age")
           ui->tableView_ab->setModel(tmpabonne.triAb_age());
      else if(arg1 == "nom")
           ui->tableView_ab->setModel(tmpabonne.triAb_nom());
    else if(arg1 == "prenom")
         ui->tableView_ab->setModel(tmpabonne.triAb_prenom());
    else if(arg1 == "cin")
         ui->tableView_ab->setModel(tmpabonne.triAb_cin());
}

void gerer_abonne::on_comboTri_EL_currentTextChanged(const QString &arg1)
{
    if(arg1 == "age")
           ui->tableView_el->setModel(tmpeleve.triEl_age());
      else if(arg1 == "nom")
           ui->tableView_el->setModel(tmpeleve.triEl_nom());
    else if(arg1 == "prenom")
         ui->tableView_el->setModel(tmpeleve.triEl_prenom());
    else if(arg1 == "cin")
         ui->tableView_el->setModel(tmpeleve.triEl_cin());
}

void gerer_abonne::on_Recherche_Cin_textChanged(const QString &arg1)
{
    Abonnement_Normal A ;
    int id=ui->Recherche_Cin->text().toInt();
     A.recherche_cin_place(ui->tableView_ab,id) ;
}

void gerer_abonne::on_Resaisir_clicked()
{
    //reset champ
    ui->CIN->clear();
    ui->NOM->clear();
    ui->PRENOM->clear();
    ui->ADRESSE->clear();
    ui->PRIX->clear();
    ui->age_ab->clear();
    ui->Date_Fin->clear();
    ui->Date_Debut->clear();
    ui->ETABLISSEMENT->clear();
}
void gerer_abonne::on_statistique_ab_clicked()
{
    stat= new statistique(this);
    stat->show();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// gestion des conventions


void gerer_abonne::on_ajouter_Conv_clicked()
{
    int id=ui->IdConv->text().toInt();
    QString nomEntreprise=ui->nomEntreprise->text();
     QString dateFin=ui->dateEdit_Conv->text();
   //condition de saisie sur id nom et date
      if( id<100000||id>999999 || id==0 ){

             { if(id==0 )
                     ui->IdConv->setText("   *champ obligatoire");
                 else{
                     ui->IdConv->setText("   cin non valide");


                     QMessageBox::critical(nullptr, QObject::tr("Ajouter une convention"),
                                 QObject::tr("Erreur condition non verifier!.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                 }
             }
      }
             else
             {    conv co (id,nomEntreprise,dateFin);

                  bool test=co.ajouter_convention();
                  if(test)
                  {
                      //ui->message->setText(" convention  ajoutée");
                      QMessageBox::information(nullptr, QObject::tr("Ajouter une convention"),
                                        QObject::tr("convention ajoutée.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                      ui->conboConv_modif->setModel(tmpconvention.combox());
                      ui->conboConv_supp->setModel(tmpconvention.combox());
                  }
                  else
                  {
                      //ui->message->setText("Erreur : convention non  ajoutée");
                             QMessageBox::critical(nullptr, QObject::tr("Ajouter une convention"),
                                         QObject::tr("Erreur d'ajout !.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                  }

             }
}

void gerer_abonne::on_afficherConv_clicked()
{
    conv *con=new conv();
    ui->tableView_conv->setModel(con->afficher());
}

void gerer_abonne::on_retour_conv_clicked()
{
    hide();
}

void gerer_abonne::on_resaisir_Conv_clicked()
{
    ui->IdConv->clear();
    ui->nomEntreprise->clear();
    ui->dateEdit_Conv->clear();
}

void gerer_abonne::on_supprimer_conv_clicked()
{
    int id=ui->conboConv_supp->currentText().toInt();
         bool test=tmpconvention.supprimer_conv(id);
          if(test)
          {
              ui->tableView_conv->setModel(tmpconvention.afficher());//refresh
               QMessageBox::information(nullptr, QObject::tr("Supprimer une convention"),
                     QObject::tr("convention supprimée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
               ui->conboConv_supp->setModel(tmpconvention.combox());


          }
        else{
         QMessageBox::critical(nullptr, QObject::tr("Supprimer une convention"),
                     QObject::tr("Erreur de suppression  !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }
}

void gerer_abonne::on_modifier_conv_clicked()
{
    int id = ui->conboConv_modif->currentText().toInt();
    QString nomEntreprise= ui->nom_Modif->text();
    QString dateFin= ui->dateEdit_Conv->text();
  conv co (id,nomEntreprise,dateFin);
  bool test=co.modifier();
  if(test )
{


QMessageBox::information(nullptr, QObject::tr("modifier une convention"),
                  QObject::tr("convention modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier une convention "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gerer_abonne::on_recherche_id_2_textChanged(const QString &arg1)
{
    conv C ;
    int id=ui->recherche_id_2->text().toInt();
     C.recherche_id_place(ui->tableView_conv,id) ;
}

void gerer_abonne::on_comboTri_conv_currentTextChanged(const QString &arg1)
{
    if(arg1 == "ID")
           ui->tableView_conv->setModel(tmpconvention.tri_id());
      else if(arg1 == "NomEntreprise")
           ui->tableView_conv->setModel(tmpconvention.tri_nom());
}

void gerer_abonne::on_Imprimer_2_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/lenovo/Desktop/version_finale2A6/pdf2");
    //printer.setOutputFileName("C:/Users/OneEffect007/Desktop/pdf1");
    QPainter painter;
    painter.begin(&printer);

    QFont font;
    font.setPixelSize(35);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(20,300,"id: ");
    painter.drawText(20,500,"Date:");
    painter.drawText(20,650,"nom:");
    int id=ui->IdConv->text().toInt();
    QString id_pdf=QString::number(id);
    QString date_pdf=ui->dateEdit_Conv->text();
    QString nom_pdf=ui->nomEntreprise->text();
    font.setPixelSize(15);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(20,350,id_pdf);
    painter.drawText(20,550,date_pdf);
    painter.drawText(20,700,nom_pdf);


    QImage image("C:/Users/lenovo/Desktop/hversion_finale2A6");
    painter.drawImage(100,50,image);

    painter.end();

    qDebug()<<"le pdf a ete cree";
    QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}



void gerer_abonne::on_langue_currentTextChanged(const QString &arg1)
{
    currentLanguage = ui->langue->currentIndex();
    tmpabonne.currentLanguage = currentLanguage;
    tmpeleve.currentLanguage = currentLanguage;
    if(!currentLanguage){
        qDebug() << "Changing to French";
        ui->trier->setText("Trier par");
        ui->afficher_Ab->setText("Abonne");
        ui->afficher_EL->setText("Eleve");
        ui->trier_el->setText("Trier par");
        ui->comboTri_Ab->clear();

        ui->comboTri_Ab->addItem("Cin");
        ui->comboTri_Ab->addItem("Prenom");
        ui->comboTri_Ab->addItem("Nom");
        ui->comboTri_Ab->addItem("Age");

        ui->comboTri_EL->clear();
        ui->comboTri_EL->addItem("Cin");
        ui->comboTri_EL->addItem("Prenom");
        ui->comboTri_EL->addItem("Nom");
        ui->comboTri_EL->addItem("Age");


       ui->label_cin->setText("cin");
       ui->label_nom->setText("Nom");
       ui->label_prenom->setText("prenom");
       ui->label_DF->setText("Date");
       ui->label_DD->setText("Date");
       ui->label_age->setText("AGE");
       ui->label_prix->setText("Prix");
       ui->label_etablissement->setText("Etablissement");
      ui->label_email->setText("Email");

      ui->afficherConv->setText("Lste des conventions");
       ui->trier_conv->setText("Trier par");

       ui->comboTri_conv->addItem("ID");
       ui->comboTri_conv->addItem("NomEntreprise");


      ui->label_id->setText("ID");
      ui->label_nomEntre->setText("Nom Entreprise");
      ui->label_date->setText("Date Fin");

      ui->Rechercher->setText("Rechercher");
      ui->rechercher_conv->setText("Recherher");

        ui->ajouterAbonne->setText("Ajouter");
        ui->ajouter_Conv->setText("Ajouter");

        ui->modifier_conv->setText("Modifier");
        ui->modifierAbonne->setText("Modifier");

        ui->supprimerAbonne->setText("Supprimer");
        ui->supprimer_conv->setText("Supprimer");

        ui->Imprimer_2->setText("Imprimer");
        ui->Imprimer->setText("Imprimer");

        ui->Resaisir->setText("Resaire");
        ui->resaisir_Conv->setText("Resaire");


        ui->tabWidget->setTabText(0, "Gestion des abonnés");
        ui->tabWidget->setTabText(1, "Gestion des Conventions");
        ui->tabWidget->setTabText(2, "Statistiques");

        ui->langue->setItemText(0, "Français");
        ui->langue->setItemText(1, "Anglais");
    }else{
        qDebug() << "Changing to English";
        ui->trier->setText("Order by");
        ui->afficher_Ab->setText("Abonne");
        ui->afficher_EL->setText("Student");
        ui->trier_el->setText("Order by");
        ui->comboTri_Ab->clear();

        ui->comboTri_Ab->addItem("IC");
        ui->comboTri_Ab->addItem("FamilyName");
        ui->comboTri_Ab->addItem("Name");
        ui->comboTri_Ab->addItem("Age");

        ui->comboTri_EL->clear();
        ui->comboTri_EL->addItem("IC");
        ui->comboTri_EL->addItem("FamilyName");
        ui->comboTri_EL->addItem("Name");
        ui->comboTri_EL->addItem("Age");

        ui->label_cin->setText("IC");
        ui->label_nom->setText("Name");
        ui->label_prenom->setText("F.Name");
        ui->label_DF->setText("Date");
        ui->label_DD->setText("Date");
        ui->label_age->setText("AGE");
        ui->label_prix->setText("Price");
        ui->label_etablissement->setText("Establishment");
       ui->label_email->setText("E-mail");

        ui->trier_conv->setText("Order by");
        ui->comboTri_conv->addItem("ID");
        ui->comboTri_conv->addItem("EstablishmentName");

         ui->afficherConv->setText("Lst of conventions");


        ui->Rechercher->setText("Search");
        ui->rechercher_conv->setText("Search");

        ui->ajouterAbonne->setText("Add");
        ui->ajouter_Conv->setText("Add");

        ui->modifier_conv->setText("Modify");
        ui->modifierAbonne->setText("Modify");

        ui->supprimerAbonne->setText("Delete");
        ui->supprimer_conv->setText("Delete");


        ui->tabWidget->setTabText(0, "Subscriber Management");
        ui->tabWidget->setTabText(1, "Convention Management");
        ui->tabWidget->setTabText(2, "Statistics");


        ui->langue->setItemText(0, "French");
        ui->langue->setItemText(1, "English");
    }
}


void gerer_abonne::on_Imprimer_clicked()
{
    QPrinter printer;
                      printer.setOutputFormat(QPrinter::PdfFormat);
                      printer.setOutputFileName("C:/Users/lenovo/Desktop/houaidaCrud/pdf1");
                      QPainter painter;
                      painter.begin(&printer);

                      QFont font;
                      font.setPixelSize(35);
                      painter.setFont(font);
                      painter.setPen(Qt::blue);
                      painter.drawText(20,300,"cin: ");
                      painter.drawText(20,400,"nom:");
                      painter.drawText(20,550,"prenom:");
                      painter.drawText(20,650,"email:");
                      painter.drawText(20,800,"age:");
                      painter.drawText(20,950,"date debut:");
                      painter.drawText(20,1200,"date fin:");
                      painter.drawText(20,1350,"prix:");
                      int cin=ui->CIN->text().toInt();
                      QString cin_pdf=QString::number(cin);

                      int age=ui->age_ab->text().toInt();
                      QString age_pdf=QString::number(age);

                      float prix=ui->PRIX->text().toFloat();
                      QString prix_pdf=QString::number(prix);

                      QString nom_pdf=ui->NOM->text();
                      QString prenom_pdf=ui->PRENOM->text();
                      QString email_pdf=ui->ADRESSE->text();
                      QString dateDeb_pdf=ui->Date_Debut->text();
                      QString dateFin_pdf=ui->Date_Fin->text();



                      font.setPixelSize(15);
                      painter.setFont(font);
                      painter.setPen(Qt::black);
                      painter.drawText(20,350,cin_pdf);
                      painter.drawText(20,550,nom_pdf);
                      painter.drawText(20,700,prenom_pdf);
                      painter.drawText(20,850,email_pdf);
                      painter.drawText(20,1050,age_pdf);
                      painter.drawText(20,1200,dateDeb_pdf);
                      painter.drawText(20,1400,dateFin_pdf);
                      painter.drawText(20,1550,prix_pdf);

                      QImage image("C:/Users/lenovo/Desktop/houaidaCrud");
                      painter.drawImage(100,50,image);

                      painter.end();
      QMessageBox::information(nullptr, QObject::tr("Ajouter un abonne"),
                                 QObject::tr("abonne ajouté.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

                      qDebug()<<"le pdf a ete cree";

          QMessageBox::information(this,"pdf cree","ce pdf a ete cree");

}
