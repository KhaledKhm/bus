#ifndef Remise_H
#define Remise_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Remise
{public:
    Remise();
    Remise(int, float , int);
    float get_taux();
    int get_id();
    int get_ide();
    bool ajouter();
    QSqlQueryModel * afficher();
    //bool tri();
    QSqlQueryModel * tri();
    QSqlQueryModel * stat();
    bool supprimer(int);
    QSqlQueryModel * recherche();
    bool modifier();
private:
    int id,ide;
    float taux;
};

#endif // Remise_H
