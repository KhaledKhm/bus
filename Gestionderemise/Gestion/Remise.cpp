#include "Remise.h"
#include <QDebug>
Remise::Remise()
{
id=0;
ide=0;
taux=0;
}
Remise::Remise(int id,float taux , int ide)
{
  this->id=id;
  this->ide=ide;
  this->taux=taux;
}
int Remise::get_id(){return  id;}
int Remise::get_ide(){return ide;}
float Remise::get_taux(){return taux;}

bool Remise::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString taux_string;
taux_string.setNum(taux);
QString ide_string= QString::number(ide);
query.prepare("INSERT INTO Remise (id, taux, idEvent) VALUES (:id, :taux, :idEvent)");
query.bindValue(":id", res);
query.bindValue(":taux", taux_string);
query.bindValue(":idEvent", ide_string);

return    query.exec();
}

QSqlQueryModel * Remise::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Remise");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ide"));
    return model;
}

bool Remise::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Remise where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Remise::modifier(){
    QSqlQuery query;
    QString res= QString::number(this->id);
    QString taux_string;
    taux_string.setNum(this->taux);
    QString ide_string= QString::number(this ->ide);
    query.prepare("UPDATE Remise SET  taux =:taux , idevent=:idEvent WHERE id = :id");
    query.bindValue(":id",res);
    query.bindValue(":taux",taux_string);
    query.bindValue(":idEvent",ide_string);
    return  query.exec();
}
//bool Remise::tri()
//{
//QSqlQuery query;
//query.prepare("Select * from remise order by id ");
//return    query.exec();
//}
QSqlQueryModel * Remise::tri(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from remise order by id ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ide"));
    return model;
}
//tekhdemch

QSqlQueryModel * Remise::recherche(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Remise where id = :id ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ide"));
    return model;
}
QSqlQueryModel * Remise::stat(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select  Max(taux) , Avg(taux) , Min(taux) from remise  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Max"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Avg"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Min"));
    return model;
}
