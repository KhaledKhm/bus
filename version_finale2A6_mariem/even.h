#ifndef EVEN_H
#define EVEN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QPaintEvent>

class even
{
public:
    even();
    even(int,QString,QString);
    int get_id();
    QString get_nom();
    QString get_season();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel  * tri_id();
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * tri_season();
    QSqlQueryModel * combox2();
    QSqlQueryModel * supp2();
    //QSqlQueryModel * tri2();
    bool supprimer(int);
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * recherche_season(QString);
    QSqlQueryModel * recherche_nom(QString);
    bool modifier();
private:
    int id;
    QString Nom;
    QString season ;
};

#endif // EVEN_H
