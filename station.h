#ifndef STATION_H
#define STATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class station{
    public:
        station();
        station(int, QString, QString, int);
        int getId();
        int getEtat();
        QString getLibelle();
        QString getLocalisation();
        bool ajouter();
        bool supprimer(int);
        bool modifier(station);
        QSqlQueryModel * afficher();
        QSqlQueryModel* recherche1 (QString,int);
        QSqlQueryModel* tri (int);

    private:
        int idStation, etatStation;
        QString libelleStation, localisationStation;
};


#endif // STATION_H
