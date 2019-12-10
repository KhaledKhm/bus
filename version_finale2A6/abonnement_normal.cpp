#include "abonnement_normal.h"
#include <QSqlQuery>

Abonnement_Normal::Abonnement_Normal()
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
Abonnement_Normal::Abonnement_Normal(int cin,QString nom,QString prenom,int age,QString email,QString date_debut,QString date_fin,float prix)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->email=email;
    this->date_debut=date_debut;
    this->date_fin=date_fin;
    this->prix=prix;

}
QSqlQueryModel *Abonnement_Normal::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from abonnement_normal" );
        return (model);
}
QSqlQueryModel * Abonnement_Normal::triAb_age()
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
QSqlQueryModel * Abonnement_Normal::triAb_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_normal order by nom ASC ");
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
QSqlQueryModel * Abonnement_Normal::triAb_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_normal order by prenom ASC ");
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
QSqlQueryModel * Abonnement_Normal::triAb_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_normal order by cin ASC ");
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
bool Abonnement_Normal::supprimerAb(int cin)
{
QSqlQuery query;
query.prepare("delete from abonnement_normal where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
QSqlQueryModel * Abonnement_Normal::combox(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select cin from abonnement_normal");
    return model;
}
bool Abonnement_Normal::modifier()
{
    QSqlQuery query;
    QString res=QString::number(age);
 QString res1=QString::number(prix);
 QString res2=QString::number(cin);
 query.prepare("UPDATE abonnement_normal SET nom= :nom WHERE cin= '"+res2+"'");
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
void Abonnement_Normal::recherche_cin_place(QTableView *table, int cin)
{
QString res=QString::number(cin);
QSqlQueryModel *model=new QSqlQueryModel() ;
QSqlQuery qry ;
qry.prepare("Select * from abonnement_normal where (regexp_like(cin,:cin))");
qry.bindValue(":cin",res);
qry.exec() ;
model->setQuery(qry) ;
table->setModel(model) ;
table->show() ;
}
