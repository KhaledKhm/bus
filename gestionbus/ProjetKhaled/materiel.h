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
    QSqlQueryModel * recherche();
private:
    int idMateriel;
    QString nomMateriel;
    int quantiteMateriel;
    double prixMateriel;
    int idFournisseurMateriel;

};
#endif // MATERIEL_H
