#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class materiel
{
public:
    materiel();
    materiel(int,QString,int,double,int);
    int get_idMateriel();
    QString get_nomMateriel();
    bool ajouterMateriel();
    bool modifierMateriel(int);
    QSqlQueryModel * afficherMateriel();
    bool supprimerMateriel(int);
    QSqlQueryModel * stat();
    QSqlQueryModel * statQuantite();
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * tri();
    QSqlQueryModel * tri2();
    QSqlQueryModel * tri3();
    QSqlQueryModel * tri4();
    QSqlQueryModel * tri5();
    QSqlQueryModel * tri6();
    QSqlQueryModel * tri7();
    QSqlQueryModel * tri8();
    QSqlQueryModel * comboxidMat();

private:
    int idMateriel;
    QString nomMateriel;
    int quantiteMateriel;
    double prixMateriel;
    int idFournisseurMateriel;

};

#endif // MATERIEL_H
