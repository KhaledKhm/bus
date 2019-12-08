#ifndef BUS_H
#define BUS_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class bus
{
public:
    bus();
    bus(int,int,QString,int,int,int,QString);
    int get_id();
    int get_nbPlace();
    int get_idFournisseur();
    int get_idTrajet();
    int get_idPlace();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool rechercher(int);
    bool supprimer(int);
    QSqlQueryModel * rechercheBus(int);
    QSqlQueryModel * triBus();
    QSqlQueryModel * triBus2();
    QSqlQueryModel * triBus3();
    QSqlQueryModel * triBus4();
    QSqlQueryModel * triBus5();
    QSqlQueryModel * triBus6();
    QSqlQueryModel * comboxidbus();

private:
    int id;
    int nbPlace;
    QString destination;
    int idFournisseur;
    int idTrajet;
    int idPlace;
    QString cinAgent;
};

#endif // BUS_H
