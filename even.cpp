#include "even.h"
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
even::even()
{
id=0;
Nom="";
season="";
}
even::even(int id, QString Nom ,QString season)
{
  this->id=id;
  this->season=season;
  this->Nom=Nom;
}
int even::get_id(){return  id;}
QString even::get_nom(){return Nom;}
QString even::get_season(){return season;}
bool even::ajouter()
{
    //sound=setMedia(QUrl("qrc:C\Users\moham\Desktop\55\button-1.wav"));
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Evenement (id,nom,season) VALUES (:id,:nom,:season)");
query.bindValue(":id", res);
query.bindValue(":season", season);
query.bindValue(":nom", Nom);
return    query.exec();

}


QSqlQueryModel * even::afficher(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}

bool even::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Evenement where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool even::modifier(){
    QSqlQuery query;
    QString res= QString::number(this->id);
    QString taux_string;
    query.prepare("UPDATE Remise SET  nom = :nom, season = :season WHERE id = :id");
    query.bindValue(":id",res);
    query.bindValue(":nom",Nom);
    query.bindValue(":season",season);
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
QSqlQueryModel * even::recherche(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(id);
    model->setQuery("Select * From Evenement WHERE id = " + res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Season"));
    return model;
}
QSqlQueryModel * even::recherche_nom(QString Nom){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From Evenement WHERE nom  = " + Nom);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Season"));
    return model;
}
QSqlQueryModel * even::recherche_season(QString season){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From Evenement WHERE season  = " + season);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taux"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("IdEvenement"));
    return model;
}
QSqlQueryModel * even::tri_id(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Evenement order by id ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}
QSqlQueryModel * even::tri_nom(){

QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Evenement Order by nom ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}
QSqlQueryModel * even::tri_season(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Evenement Order by season ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}
QSqlQueryModel * even::combox2(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select id from Evenement");
    return model;
}
QSqlQueryModel * even::supp2(){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res= QString::number(id);
    model->setQuery("Delete from Evenement Where id = :id ");
    return model;
}
