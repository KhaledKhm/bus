#ifndef TRAJET_H
#define TRAJET_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class trajet
{
    public:
        trajet();
        trajet(int, QString, QString,int);
        int getId(),getIds();
        QString getHeuredepart(),getHeurearri();
        bool ajouter();
        bool supprimer(int);
        bool modifier();
        QSqlQueryModel * afficher(); 
        QSqlQueryModel* recherche2 (QString,int);
        QSqlQueryModel* tri (int);


    private:
        int ID, IDSTATIONARRET;
        QString HEUREDEPART,HEUREARRIVEE;
};

#endif // TRAJET_H
