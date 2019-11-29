#include "gerer_abonnement.h"
#include "ui_gerer_abonnement.h"
#include "abonnement_normal.h"
#include "abonnement_eleve.h"
#include "liste_abonnement.h"
#include <QDebug>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include "QImage"
#include "mailing/SmtpMime"

gerer_abonnement::gerer_abonnement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_abonnement)
{
    ui->setupUi(this);
}

gerer_abonnement::~gerer_abonnement()
{
    delete ui;
}

void gerer_abonnement::on_ajouter_clicked()
{
   /////////////////////////////////////////////////
 // mailing
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("houaidafatma.karoui@esprit.tn");
    smtp.setPassword("fatma23703032");

    MimeMessage message;

    message.setSender(new EmailAddress("houaidafatma.karoui@esprit.tn", "houaida"));
    message.addRecipient(new EmailAddress(ui->adresse->text(), ui->nom->text()));
    message.setSubject("SmtpClient for Qt - Demo");

    MimeText text;

    text.setText("Hi,\n abonnement ajouté ! bienvenue with love .\n");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
    ///////////////////////////////////////////////////
    abonnement_normal a;
    liste_abonnement liste;

   //condition de saisie sur cin
        if( ui->cin->text().toInt()<100000|| ui->cin->text().toInt()>999999 || ui->cin->text().toInt()==0 || ui->cin->text()=="   *champ obligatoire")
        { if(ui->cin->text().toInt()==0)
                ui->cin->setText("   *champ obligatoire");
            else
                ui->cin->setText("   cin non valide");}
         else
            a.set_cin(ui->cin->text().toInt());

   //condition de saisie sur nom
     if(ui->nom->text()=="" || ui->nom->text()=="   *champ obligatoire")
         ui->nom->setText("   *champ obligatoire");
      else
         a.set_nom(ui->nom->text());

   //condition de saisie sur prenom
     if(ui->prenom->text()=="" || ui->prenom->text()=="   *champ obligatoire")
         ui->prenom->setText("   *champ obligatoire");
      else
         a.set_prenom(ui->prenom->text());

   //condition de saisie sur adresse
     if(ui->adresse->text()=="" || ui->adresse->text()=="   *champ obligatoire")
         ui->adresse->setText("   *champ obligatoire");
      else
         a.set_adresse_mail(ui->adresse->text());


     //condition de saisie sur age
       if( ui->age->text().toInt()<21 || ui->age->text().toInt()>70 || ui->age->text().toInt()==0 || ui->age->text()=="   *champ obligatoire")
       { if(ui->age->text().toInt()==0)
               ui->age->setText("   *champ obligatoire");
           else
               ui->age->setText("   age non valide");}
        else
           a.set_age(ui->age->text().toInt());

     if(false==ui->etablissement->isVisible()){

         int cin=ui->cin->text().toInt();
         int age=ui->age->text().toInt();
         QString nom=ui->nom->text();
         QString prenom=ui->prenom->text();
         QString email=ui->adresse->text();
         QString date_debut=ui->date_debut->text();
         QString date_fin=ui->date_fin->text();
         float prix=100;

       bool var=tmpabonne.rechercher(cin);
    if(var==false){
          if(liste.ajouter_abonnement(cin,nom,prenom,age,email,date_debut,date_fin,prix)==1){
              // impression pdf

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
                               //int cin=ui->cin->text().toInt();
                               QString cin_pdf=QString::number(cin);

                               //int age=ui->age->text().toInt();
                               QString age_pdf=QString::number(age);

                              // float prix=ui->prix->text().toFloat();
                               QString prix_pdf=QString::number(prix);

                               QString nom_pdf=ui->nom->text();
                               QString prenom_pdf=ui->prenom->text();
                               QString email_pdf=ui->adresse->text();
                               QString dateDeb_pdf=ui->date_debut->text();
                               QString dateFin_pdf=ui->date_fin->text();

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

                                   ui->message->setText("PDF CREER");


              }
     else {
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonne"),
                     QObject::tr("Erreur d'ajout !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
          }
   }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonné"),
                    QObject::tr("Erreur ! cin existe deja.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

            ui->message->setText("Erreur : abonne  ajoute");
    }
}

     else if(true==ui->etablissement->isVisible())
    {
         //abonnement eleve

         abonnement_eleve el;
        el=a;

       //condition de saisie sur etablissement
                  if(ui->etablissement->text()=="" || ui->etablissement->text()=="   *champ obligatoire")
                      ui->etablissement->setText("   *champ obligatoire");
                   else
                      el.set_etablissement(ui->etablissement->text());

       if(liste.ajouter_abonnement(el))
           { ui->message->setText("eleve ajoute avec succes");
            int cin=ui->cin->text().toInt();
            int age=ui->age->text().toInt();
            QString nom=ui->nom->text();
            QString prenom=ui->prenom->text();
            QString email=ui->adresse->text();
            QString date_debut=ui->date_debut->text();
            QString date_fin=ui->date_fin->text();
            float   prix=ui->prix->text().toFloat();
            QString etablissement=ui->etablissement->text();
          //  float prix=60;

            if(liste.ajouter_abonnement(cin,nom,prenom,age,email,date_debut,date_fin,prix)==1)

                QMessageBox::information(nullptr, QObject::tr("ajouter un eleve"),
                               QObject::tr("eleve ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
        else
                QMessageBox::critical(nullptr, QObject::tr("ajouter un eleve"),
                            QObject::tr("Erreur d'ajout !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else {
            ui->message->setText("Erreur : eleve non ajoute");
           QMessageBox::critical(nullptr, QObject::tr("ajouter un eleve"),
                       QObject::tr("Erreur ! cin existe deja.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

}

void gerer_abonnement::on_resaisir_clicked()
{
    //reset champ
    ui->cin->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->adresse->clear();
    ui->prix->clear();
    ui->age->clear();
    ui->date_fin->clear();
    ui->date_debut->clear();
    ui->etablissement->clear();

}


void gerer_abonnement::on_retour_clicked()
{
    hide();

}

void gerer_abonnement::on_afficherAb_clicked()
{
    abonnement_normal *A=new abonnement_normal();
    ui->tableView_2->setModel(A->afficher());
}

void gerer_abonnement::on_afficherEl_clicked()
{
    abonnement_eleve *E=new abonnement_eleve();
    ui->tableView->setModel(E->afficher());
}

void gerer_abonnement::on_radioButtonabonne_clicked()
{
    ui->etablissement->setVisible(false);
    ui->prix->setText("100");
}

void gerer_abonnement::on_radioButtoneleve_clicked()
{
    ui->etablissement->setVisible(true);
    ui->prix->setText("60");


}

void gerer_abonnement::on_trierAb_age_clicked()
{
    bool test = tmpabonne.triAb_age();
           if (test){
           ui->tableView_2->setModel(tmpabonne.triAb_age());}//refresh
}

void gerer_abonnement::on_trierAb_nom_clicked()
{
    bool test = tmpabonne.triAb_nom();
           if (test){
           ui->tableView_2->setModel(tmpabonne.triAb_nom());}//refresh
}

void gerer_abonnement::on_trirEl_age_clicked()
{
    bool test = tmpeleve.triEl_age();
           if (test){
           ui->tableView->setModel(tmpeleve.triEl_age());}//refresh
}


void gerer_abonnement::on_trirEl_nom_clicked()
{
    bool test = tmpeleve.triEl_nom();
           if (test){
           ui->tableView->setModel(tmpeleve.triEl_nom());}//refresh
}

void gerer_abonnement::on_supprimer_clicked()
{
    int cin=ui->recherchercin->text().toInt();
     bool var=tmpabonne.rechercher(cin);
     bool var2=tmpeleve.rechercher(cin);
    if(var || var2)
     {
         bool test=tmpabonne.supprimerAb(cin);
         bool test2=tmpeleve.supprimerEl(cin);
          if(test || test2)
          {
                     ui->tableView_2->setModel(tmpabonne.afficher());//refresh
                     ui->tableView->setModel(tmpeleve.afficher());//refresh
                     QMessageBox::information(nullptr, QObject::tr("Supprimer un abonné"),
                     QObject::tr("abonne supprimée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

          }
        else{
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonné"),
                     QObject::tr("Erreur de suppression  !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonné"),
                     QObject::tr("Erreur ! cin not found.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void gerer_abonnement::on_rechercher_clicked()
{
    int cin = ui->recherchercin->text().toInt();

bool test=tmpabonne.rechercher(cin);
if(test==(true))
{

ui->tableView_2->setModel(tmpabonne.chercher(cin));
QMessageBox::information(nullptr, QObject::tr("chercher un abonne"),
                  QObject::tr("abonne existe.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
else
{
    QMessageBox::critical(nullptr, QObject::tr("chercher un abonne"),
                      QObject::tr("abonne n'existe pas.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void gerer_abonnement::on_retour_2_clicked()
{
    hide();
}

void gerer_abonnement::on_modifier_clicked()
{
    int cin = ui->cin->text().toInt();
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString email=ui->adresse->text();
    int age = ui->age->text().toInt();
    QString date_debut = ui->date_debut->text();
    QString date_fin= ui->date_fin->text();
    QString etablissement=ui->etablissement->text();
    float prix = ui->prix->text().toFloat();

  abonnement_normal a(cin,nom,prenom,age,email,date_debut,date_fin,prix);
  bool test=a.update();

  if(test)
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

void gerer_abonnement::on_commandLinkButton_2_clicked()
{
    stat= new statistic(this);
    stat->show();
}


