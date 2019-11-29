#ifndef LISTE_ABONNEMENT_H
#define LISTE_ABONNEMENT_H

#include "abonnement_eleve.h"
#include <QString>

class liste_abonnement
{
public:
    liste_abonnement();
    bool ajouter_abonnement(const abonnement_eleve&);
    int ajouter_abonnement(int,QString ,QString,int,QString,QString,QString,float);
};

#endif // LISTE_ABONNEMENT_H
