#include "abonnement_el.h"
#include "abonnement_normal.h"
#include <QString>
#include <QSqlQuery>
Abonnement_EL::Abonnement_EL():Abonnement_Normal()
{
    etablissement="";

}
Abonnement_EL::Abonnement_EL(int cin,QString nom,QString prenom,int age,QString email,QString date_debut,QString date_fin,float prix,QString etablissement):Abonnement_Normal(cin,nom,prenom,age,email,date_debut,date_fin,prix)
{
    this->etablissement=etablissement;
}
Abonnement_EL& Abonnement_EL:: operator=(Abonnement_Normal& e)
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
QSqlQueryModel *Abonnement_EL::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from abonnement_eleve" );
        return (model);
}
bool Abonnement_EL::supprimerEl(int cin)
{

QSqlQuery query;
query.prepare("delete from abonnement_eleve where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
QSqlQueryModel * Abonnement_EL::triEl_age()
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
QSqlQueryModel * Abonnement_EL::triEl_nom()
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
QSqlQueryModel * Abonnement_EL::triEl_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_eleve order by cin ASC ");
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
QSqlQueryModel * Abonnement_EL::triEl_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_eleve order by prenom ASC ");
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
bool Abonnement_EL::modifier()
{
    QSqlQuery query;
    QString res=QString::number(age);
 QString res1=QString::number(prix);
 QString res2=QString::number(cin);
 query.prepare("UPDATE abonnement_eleve SET nom= :nom WHERE cin= '"+res2+"'");
    query.bindValue(":age",res);
    query.bindValue(":cin",res2);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":date_fin",date_fin);
    query.bindValue(":email",email);
    query.bindValue(":prix",res1);

    return query.exec();
}
