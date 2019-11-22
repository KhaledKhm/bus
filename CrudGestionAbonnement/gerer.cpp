#include "gerer.h"
#include "ui_gerer.h"
#include "abonne.h"
#include "liste_abonnee.h"
#include <QDebug>
#include"eleve.h"
#include <QSqlQueryModel>
#include "mainwindow.h"
#include <iostream>
gerer::gerer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer)
{
    ui->setupUi(this);
}

gerer::~gerer()
{
    delete ui;
}
QString gerer::GetRandomString() const{

    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 10; // assuming you want random strings of 12 characters

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}
void gerer::on_ajouter_clicked()
{
         abonne a;
         liste_abonnee liste;

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
          //condition de saisie sur date debut

          if(ui->date_debut->text()=="" || ui->date_debut->text()=="   *champ obligatoire")
              ui->date_debut->setText("   *champ obligatoire");
           else
              a.set_date_debut(ui->date_debut->text());
          //condition de saisie sur date fin

          if(ui->date_fin->text()=="" || ui->date_fin->text()=="   *champ obligatoire")
              ui->date_fin->setText("   *champ obligatoire");
           else
              a.set_date_fin(ui->date_fin->text());

          //condition de saisie sur age
            if( ui->age->text().toInt()<21 || ui->age->text().toInt()>50 || ui->age->text().toInt()==0 || ui->age->text()=="   *champ obligatoire")
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

              if(liste.ajouter_abonne(cin,nom,prenom,age,email,date_debut,date_fin,prix)==1){
                  qDebug()<<"abonne ajoute";
                  ui->message->setText("Erreur : abonne  ajoute");

              }
              else {
                  ui->message->setText("Erreur : abonne non  ajoute");
                  qDebug()<<"abonne  pas ajoute";}


          }
          else if(true==ui->etablissement->isVisible())
         {//eleve
             eleve el;
             el=a;

            //condition de saisie sur etablissement
                       if(ui->etablissement->text()=="" || ui->etablissement->text()=="   *champ obligatoire")
                           ui->etablissement->setText("   *champ obligatoire");
                        else
                           el.set_etablissement(ui->etablissement->text());

             if(liste.ajouter_abonne(el))
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

                 if(liste.ajouter_abonne(cin,nom,prenom,age,email,date_debut,date_fin,prix)==1)
                 qDebug()<<"eleve ajoute";
             else qDebug()<<"eleve  pas ajoute";
             }
             else
                 ui->message->setText("Erreur : eleve non ajoute");
    }



}
void gerer::on_resaisir_clicked()
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

void gerer::on_retour_clicked()
{
    hide();
}


void gerer::on_afficherEl_clicked()
{
    eleve *E=new eleve();
    ui->tableView->setModel(E->afficher());
}


void gerer::on_afficherAb_clicked()
{
    abonne *A=new abonne();
    ui->tableView_2->setModel(A->afficher());
}

void gerer::on_trierEl_clicked()
{
    bool test = tmpeleve.tri();
           if (test){
           ui->tableView->setModel(tmpeleve.tri());}//refresh
}

void gerer::on_trierAb_clicked()
{
    bool test = tmpabonne.tri();
           if (test){
           ui->tableView_2->setModel(tmpabonne.tri());}//refresh
}

void gerer::on_supprimer_clicked()
{

    int cin=ui->cinsuppr->text().toInt();
    bool test=tmpabonne.supprimerAb(cin);
     if(test)
     {
         ui->tableView->setModel(tmpabonne.afficher());//refresh
         bool test1=tmpeleve.supprimerEl(cin);
     if(test1){
         ui->tableView_2->setModel(tmpabonne.afficher());//refresh
        }
     qDebug()<<"supression faite";
     }
      else qDebug()<<"erreur";
}



void gerer::on_radioButtoneleve_clicked()
{
    ui->etablissement->setVisible(true);
    ui->prix->setText("60");


}

void gerer::on_radioButtonabonne_clicked()
{
    ui->etablissement->setVisible(false);
    ui->prix->setText("100");


}
