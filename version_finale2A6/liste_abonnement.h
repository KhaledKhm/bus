#ifndef LISTE_ABONNEMENT_H
#define LISTE_ABONNEMENT_H

#include "abonnement_el.h"
#include <QString>
class liste_Abonnement
{
public:
    liste_Abonnement();
    bool ajouter_abonnement(const Abonnement_EL&);
    int ajouter_abonnement(int,QString ,QString,int,QString,QString,QString,float);
};

#endif // LISTE_ABONNEMENT_H
