#ifndef REM_H
#define REM_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QPaintEvent>

class rem
{
public:
    rem();
    rem(int, float , int , QString);
    float get_taux();
    int get_id();
    int get_ide();
    QString get_type();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel  * tri_id();
    QSqlQueryModel * tri_taux();
    QSqlQueryModel * tri_ide();
    QSqlQueryModel * combox();
    QSqlQueryModel * combox8();
    QSqlQueryModel * supp();
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

#endif // REM_H
