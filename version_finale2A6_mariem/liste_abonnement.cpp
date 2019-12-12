#include "liste_abonnement.h"
#include "abonnement_normal.h"
#include "abonnement_el.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
using namespace std;

liste_Abonnement::liste_Abonnement()
{

}
int liste_Abonnement::ajouter_abonnement(int cin,QString nom,QString prenom,int age,QString email,QString date_debut,QString date_fin,float prix)
{
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(prix);
    QString res2=QString::number(age);
        query.prepare("INSERT INTO abonnement_normal (CIN,NOM,PRENOM,AGE,EMAIL,DATE_DEBUT,DATE_FIN,PRIX) VALUES (:cin,:nom,:prenom,:age ,:email,:date_debut,:date_fin,:prix)");
        query.bindValue(":cin",res);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
         query.bindValue(":age",res2);
          query.bindValue(":email",email);
          query.bindValue(":date_debut",date_debut);
          query.bindValue(":date_fin",date_fin);
        query.bindValue(":prix",res1);
        int i;
        QString alphabet="abcdefghijklmnopqrstuvwxyz";
       /* for(i=0;i!=alphabet.length();i++)
        {
           if(nom[i]!=alphabet[i] || prenom[i]!=alphabet[i])
           {
               QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
                    QObject::tr("Erreur nom et prenom invalident!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               return false;
           }

        }*/
        return query.exec();

/*if(query.exec())
    return 1;
else return 0;*/
}
bool liste_Abonnement::ajouter_abonnement(const Abonnement_EL &el)
{
    QSqlQuery query;
    QString res=QString::number(el.get_cin());
    QString res2=QString::number(el.get_age());
    QString res3=QString::number(el.get_prix());
    query.prepare("INSERT INTO abonnement_eleve (CIN,NOM,PRENOM,AGE,EMAIL,DATE_DEBUT,DATE_FIN,PRIX,ETABLISSEMENT) VALUES (:cin,:nom,:prenom,:age ,:email,:date_debut,:date_fin,:prix,:etablissement)");
    /*query.bindValue(":cin",res);
    query.bindValue(":age",res2);
    query.bindValue(":date_debut",el.get_date_debut());
    query.bindValue(":nom",el.get_nom());
    query.bindValue(":prenom",el.get_prenom());
    query.bindValue(":email",el.get_adresse_mail());
    query.bindValue(":prix",res3);
    query.bindValue(":date_fin",el.get_date_fin());
    query.bindValue(":etablissement",el.get_etablissement());*/
   query.bindValue(":cin",res);
    query.bindValue(":nom",el.get_nom());
    query.bindValue(":prenom",el.get_prenom());
    query.bindValue(":age",res2);
    query.bindValue(":email",el.get_adresse_mail());
    query.bindValue(":date_debut",el.get_date_debut());
    query.bindValue(":date_fin",el.get_date_fin());
    query.bindValue(":prix",res3);
    query.bindValue(":etablissement",el.get_etablissement());
    int i;
    QString alphabet="abcdefghijklmnopqrstuvwxyz";
    for(i=0;i!=alphabet.length();i++)
    {
       if(el.get_nom()[i]!=alphabet[i])
       {
           QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
                QObject::tr("Erreur nom invalide!.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
           return false;
       }
    }
   return( query.exec());



}

