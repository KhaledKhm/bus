#ifndef Evenement_H
#define Evenement_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Evenement
{public:
    Evenement();
    Evenement(int, QString);
    int get_id();
    QString get_lib1();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    int id;
    QString lib1;
};

#endif // Remise_H
