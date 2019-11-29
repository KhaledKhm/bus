#include "abonnement_eleve.h"
#include "abonnement_normal.h"
#include <QString>
#include <QSqlQuery>
abonnement_eleve::abonnement_eleve():abonnement_normal()
{
    etablissement="";
}
abonnement_eleve& abonnement_eleve:: operator=(abonnement_normal& e)
{
        this->cin=e.get_cin();
        this->nom=e.get_nom();
        this->prenom=e.get_prenom();
        this->email=e.get_adresse_mail();
        this->age=e.get_age();
        this->date_debut=e.get_date_debut();
        this->date_fin=e.get_date_fin();
        this->prix=e.get_prix();

        return *this;

}
QSqlQueryModel *abonnement_eleve::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from abonnement_eleve" );
        return (model);
}
QSqlQueryModel * abonnement_eleve::triEl_age()
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
QSqlQueryModel * abonnement_eleve::triEl_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_eleve order by nom ASC ");
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
bool abonnement_eleve::supprimerEl(int cin)
{

QSqlQuery query;
query.prepare("delete from abonnement_eleve where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}

bool abonnement_eleve::rechercher(int cin)
{
    QSqlQuery query;
    int count=0;
    bool test=0;
    QString res=QString::number(cin);
    if(query.exec("select * from abonnement_eleve where CIN='"+res+"'"))
    {
        while (query.next()) {
            count++;
        }
        if(count>=1){
            test=1;
        return test;
        }
    }
    return test;

}
