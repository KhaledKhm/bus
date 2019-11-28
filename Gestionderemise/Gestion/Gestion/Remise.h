#ifndef Remise_H
#define Remise_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QPaintEvent>
class Remise
{public:
    Remise();
    Remise(int, float , int , QString);
    float get_taux();
    int get_id();
    int get_ide();
    QString get_type();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel  * tri_id();
    QSqlQueryModel * tri_taux();
    QSqlQueryModel * tri_ide();
    //QSqlQueryModel * tri2();
    QSqlQueryModel * stat();
    bool verif(int);
    bool supprimer(int);
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * recherche_taux(int);
    QSqlQueryModel * recherche_ide(int);
    bool modifier();

private:
    int id,ide;
    float taux;
    QString type ;
};

#endif // Remise_H
