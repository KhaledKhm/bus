#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString);
    int get_idFournisseur();
    QString get_nomFournisseur();
    bool ajouterFournisseur();
    bool modifierFournisseur(int);
    QSqlQueryModel * afficherFournisseur();
    bool supprimerFournisseur(int);
   // QSqlQueryModel * stat();
    QSqlQueryModel * recherche();
private:
    int idFournisseur;
    QString nomFournisseur;
};

#endif // FOURNISSEUR_H
