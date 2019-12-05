#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QPaintEvent>
#include <QMediaPlayer>
class Evenement
{public:
    Evenement();
    Evenement(int,QString,QString);
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
    QMediaPlayer * sound;
private:
    int id;
    QString Nom;
    QString season ;
};

#endif // Remise_H
