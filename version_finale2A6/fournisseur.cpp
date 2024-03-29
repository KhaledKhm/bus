#include "fournisseur.h"

fournisseur::fournisseur()
{
    idFournisseur=0;
    nomFournisseur="";
}

fournisseur::fournisseur(int idF,QString nomF)
{
    idFournisseur=idF;
    nomFournisseur=nomF;
}

int fournisseur::get_idFournisseur()
{
    return idFournisseur;
}

QString fournisseur::get_nomFournisseur()
{
    return nomFournisseur;
}

bool fournisseur::ajouterFournisseur()
{
    QSqlQuery query;
    QString idFournisseurBD=QString::number(idFournisseur);
  //  QString nomFournisseurBD=QString(nomFournisseur);
    query.prepare("INSERT INTO fournisseur VALUES(:id,:nom)");
    query.bindValue(":id",idFournisseurBD);
    query.bindValue(":nom",nomFournisseur);
    return query.exec();
}

QSqlQueryModel * fournisseur::afficherFournisseur()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    return model;
}

bool fournisseur::supprimerFournisseur(int id)
{

    QSqlQuery query;
    QString code2=QString::number(id);
    query.prepare("DELETE FROM fournisseur WHERE id= :code2");
    query.bindValue(":code2",code2);
    return query.exec();
}

bool fournisseur::modifierFournisseur(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE fournisseur SET nom= :nom WHERE id= :id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nomFournisseur);
    return query.exec();
}

QSqlQueryModel * fournisseur::recherche(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Remise where id = :id ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ide"));
    return model;
}

QSqlQueryModel * fournisseur::triFournisseur(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from fournisseur order by id ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
return model;
}
QSqlQueryModel * fournisseur::triFournisseur2(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from fournisseur order by id DESC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
return model;
}

QSqlQueryModel * fournisseur::triFournisseur3(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from fournisseur order by nom ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
return model;
}

QSqlQueryModel * fournisseur::triFournisseur4(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from fournisseur order by nom DESC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
return model;
}

QSqlQueryModel * fournisseur::rechercheFournisseur(int id){
QSqlQueryModel * model= new QSqlQueryModel();
QString code=QString::number(id);
model->setQuery("select * FROM fournisseur WHERE id="+code );
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    return model;
}


QSqlQueryModel * fournisseur::comboxidfournis(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select id from fournisseur");
    return model;
}
