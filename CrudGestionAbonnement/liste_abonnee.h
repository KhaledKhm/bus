#ifndef LISTE_ABONNEE_H
#define LISTE_ABONNEE_H
#include "eleve.h"
#include <QString>
class liste_abonnee
{
public:
    liste_abonnee();
    bool ajouter_abonne(const eleve&);
    int ajouter_abonne(int,QString ,QString,int,QString,QString,QString,float);
};

#endif // LISTE_ABONNEE_H
