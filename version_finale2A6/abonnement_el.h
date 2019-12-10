#ifndef ABONNEMENT_EL_H
#define ABONNEMENT_EL_H

#include <QString>
#include "abonnement_normal.h"
#include <QSqlQueryModel>

class Abonnement_EL:public Abonnement_Normal
{

protected:
    QString etablissement;
public:
    Abonnement_EL();
    Abonnement_EL(int,QString,QString,int,QString,QString,QString,float,QString);
    Abonnement_EL& operator=(Abonnement_Normal&);
    QString get_etablissement()const{return etablissement;}
    void set_etablissement(QString etablissement){this->etablissement=etablissement;}
    bool ajouter_abonnement(const Abonnement_EL&);
    QSqlQueryModel * triEl_age();
    QSqlQueryModel * triEl_nom();
    QSqlQueryModel * triEl_prenom();
    QSqlQueryModel * triEl_cin();
    QSqlQueryModel *afficher();
    bool supprimerEl(int);
    bool rechercher(int);
    bool modifier();
    //QSqlQueryModel * combox();

};

#endif // ABONNEMENT_EL_H
