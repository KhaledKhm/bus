#include "abonne.h"
#include <QSqlQuery>

abonne::abonne()
{
     nom="";
     prenom="";
     email="";
     age=0;
     cin=0;
     date_debut="";
     date_fin="";
     prix=0;

}
QSqlQueryModel *abonne::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from abonnement_normal" );
        return (model);
}
QSqlQueryModel * abonne::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_normal order by age ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date debut"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date fin"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));

    return model;
}
bool abonne::supprimerAb(int cin)
{
QSqlQuery query;
query.prepare("delete from abonnement_normal where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
