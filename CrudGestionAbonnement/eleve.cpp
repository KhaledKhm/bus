#include "eleve.h"
#include "abonne.h"
#include <QString>
#include <QSqlQuery>
eleve::eleve():abonne()
{
    etablissement="";
}

eleve& eleve:: operator=(abonne& s)
{
        this->cin=s.get_cin();
        this->nom=s.get_nom();
        this->prenom=s.get_prenom();
        this->email=s.get_adresse_mail();
        this->age=s.get_age();
        this->date_debut=s.get_date_debut();
        this->date_fin=s.get_date_fin();
        this->prix=s.get_prix();

        return *this;

}

QSqlQueryModel *eleve::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from abonnement_eleve" );
      /*  model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date debut"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("date fin"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("etablissement"));*/


        return (model);
}
QSqlQueryModel * eleve::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_eleve order by age ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date debut"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date fin"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("etablissement"));


    return model;
}
bool eleve::supprimerEl(int cin)
{

QSqlQuery query;
query.prepare("delete from abonnement_eleve where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
