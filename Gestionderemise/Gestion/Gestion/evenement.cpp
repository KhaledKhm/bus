#include "evenement.h"
#include <QDebug>
Evenement::Evenement()
{
id=0;
lib1 ="";
}
Evenement::Evenement(int id,QString lib1)
{
  this->id=id;
  this->lib1=lib1;
}
int Evenement::get_id(){return  id;}
QString Evenement::get_lib1(){return lib1 ;}

bool Evenement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Evenement (id, Libelle) VALUES (:id,:lib1)");
query.bindValue(":id", res);
query.bindValue(":lib1", lib1);
return    query.exec();
}

QSqlQueryModel * Evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    return model;
}

bool Evenement::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Evenement where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}
