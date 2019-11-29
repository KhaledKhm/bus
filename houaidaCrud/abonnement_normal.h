#ifndef ABONNEMENT_NORMAL_H
#define ABONNEMENT_NORMAL_H

#include <QString>
#include <QSqlQueryModel>
class abonnement_normal
{
public:
    abonnement_normal();
    abonnement_normal(int,QString,QString,int,QString,QString,QString,float);
    void set_cin(int cin){this->cin=cin;}
    void set_nom(QString nom){this->nom=nom;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_adresse_mail(QString email){this->email=email;}
    void set_prix(float prix){this->prix=prix;}
    void set_date_debut(QString date_debut){this->date_debut=date_debut;}
    void set_date_fin(QString date_fin){this->date_fin=date_fin;}
    void set_age(int age){this->age=age;}
    int get_cin()const{return cin;}
    int get_age()const{return age;}
    QString get_date_debut()const{return date_debut;}
    QString get_date_fin()const{return date_fin;}
    QString get_nom()const{return nom;}
    QString get_prenom()const{return prenom;}
    QString get_adresse_mail()const{return email;}
    float get_prix()const{return prix;}
    QSqlQueryModel *afficher();
    QSqlQueryModel * triAb_age();
    QSqlQueryModel * triAb_nom();
    bool supprimerAb(int);
   // bool modifier(QString,QString,int);
    bool update();
    QSqlQueryModel *chercher(int);
    bool rechercher(int);


protected :
     int cin,age;
     QString nom,prenom,email,date_debut,date_fin;
     float prix;
};

#endif // ABONNEMENT_NORMAL_H
