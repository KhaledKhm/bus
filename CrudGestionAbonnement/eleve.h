#ifndef ELEVE_H
#define ELEVE_H
#include <QString>
#include "abonne.h"
#include <QSqlQueryModel>

class eleve:public abonne
{
    protected:
        QString etablissement;
    public:
        eleve();
        eleve& operator=(abonne&);
        QString get_etablissement()const{return etablissement;}
        void set_etablissement(QString etablissement){this->etablissement=etablissement;}
        bool ajouter_abonne(const eleve&);
        QSqlQueryModel * tri();
        QSqlQueryModel *afficher();
        bool supprimerEl(int);

};


#endif // ELEVE_H
