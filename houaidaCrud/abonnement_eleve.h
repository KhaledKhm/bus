#ifndef ABONNEMENT_ELEVE_H
#define ABONNEMENT_ELEVE_H

#include <QString>
#include "abonnement_normal.h"
#include <QSqlQueryModel>

class abonnement_eleve :public abonnement_normal
{

protected:
    QString etablissement;
public:
    abonnement_eleve();
    abonnement_eleve& operator=(abonnement_normal&);
    QString get_etablissement()const{return etablissement;}
    void set_etablissement(QString etablissement){this->etablissement=etablissement;}
    bool ajouter_abonnement(const abonnement_eleve&);
    QSqlQueryModel * triEl_age();
    QSqlQueryModel * triEl_nom();
    QSqlQueryModel *afficher();
    bool supprimerEl(int);
    bool rechercher(int);


};

#endif // ABONNEMENT_ELEVE_H
