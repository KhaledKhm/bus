#include "Remise.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE
Remise::Remise()
{
id=0;
ide=0;
taux=0;
type="vide";
}
Remise::Remise(int id,float taux , int ide , QString type)
{
  this->id=id;
  this->ide=ide;
  this->taux=taux;
  this->type=type;
}
int Remise::get_id(){return  id;}
int Remise::get_ide(){return ide;}
float Remise::get_taux(){return taux;}
QString Remise::get_type(){return type;}
bool Remise::ajouter()
{
    sound=new QMediaPlayer();
    //sound=setMedia(QUrl("qrc:C\Users\moham\Desktop\55\button-1.wav"));
QSqlQuery query;
QString res= QString::number(id);
QString taux_string;
taux_string.setNum(taux);
QString ide_string= QString::number(ide);
query.prepare("INSERT INTO Remise (id, taux, idEvent,type) VALUES (:id, :taux, :idEvent, :type)");
query.bindValue(":id", res);
query.bindValue(":taux", taux_string);
query.bindValue(":idEvent", ide_string);
query.bindValue(":type", type);
return    query.exec();

}


QSqlQueryModel * Remise::afficher(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Remise");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IdEvenement"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
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
/*
QSqlQueryModel * Remise::tri(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from remise order by id ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IdEvenement"));
    return model;
}

QSqlQueryModel * Remise::tri2(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from remise order by id DESC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IdEvenement"));
    return model;
}
*/
QSqlQueryModel * Remise::recherche(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(id);
    model->setQuery("Select * From Remise WHERE id = " + res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taux"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("IdEvenement"));
    return model;
}
QSqlQueryModel * Remise::recherche_taux(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(id);
    model->setQuery("Select * From Remise WHERE taux  = " + res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taux"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("IdEvenement"));
    return model;
}
QSqlQueryModel * Remise::recherche_ide(int ide){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(ide);
    model->setQuery("Select * From Remise WHERE idEvent  = " + res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taux"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("IdEvenement"));
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
QSqlQueryModel * Remise::tri_id(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from remise order by id ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IdEvenement"));
    return model;
}
QSqlQueryModel * Remise::tri_taux(){

QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Remise Order by taux ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IdEvenement"));
    return model;
}
QSqlQueryModel * Remise::tri_ide(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Remise Order by idevent ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IdEvenement"));
    return model;
}
QSqlQueryModel * Remise::combox(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select id from remise");
    return model;
}
QSqlQueryModel * Remise::supp(){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res= QString::number(id);
    model->setQuery("Delete from Remise Where id = :id ");
    return model;
}
QSqlQueryModel * Remise::combox8(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select id from evenement");
    return model;
}
