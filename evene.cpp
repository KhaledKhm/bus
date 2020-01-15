#include "evene.h"
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
evene::evene()
{
    id=0;
       Nom="";
       season="";
}
evene::evene(int id, QString Nom ,QString season)
{
  this->id=id;
  this->season=season;
  this->Nom=Nom;
}

int evene::get_id(){return  id;}
QString evene::get_nom(){return Nom;}
QString evene::get_season(){return season;}

bool evene::ajouter()
{
   // sound=new QMediaPlayer();
    //sound=setMedia(QUrl("qrc:C\Users\moham\Desktop\55\button-1.wav"));
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Evenement (id,nom,season) VALUES (:id,:nom,:season)");
query.bindValue(":id", res);
query.bindValue(":season", season);
query.bindValue(":nom", Nom);
return    query.exec();

}

QSqlQueryModel * evene::afficher(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}

bool evene::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Evenement where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool evene::modifier(){
    QSqlQuery query;
    QString res= QString::number(this->id);
    QString taux_string;
    query.prepare("UPDATE Remise SET  nom = :nom, season = :season WHERE id = :id");
    query.bindValue(":id",res);
    query.bindValue(":nom",Nom);
    query.bindValue(":season",season);
    return  query.exec();
}
QSqlQueryModel * evene::recherche(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(id);
    model->setQuery("Select * From Evenement WHERE id = " + res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Season"));
    return model;
}
QSqlQueryModel * evene::recherche_nom(QString Nom){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From Evenement WHERE nom  = " + Nom);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Season"));
    return model;
}
QSqlQueryModel * evene::recherche_season(QString season){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From Evenement WHERE season  = " + season);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taux"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("IdEvenement"));
    return model;
}
QSqlQueryModel * evene::tri_id(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Evenement order by id ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}
QSqlQueryModel * evene::tri_nom(){

QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Evenement Order by nom ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}
QSqlQueryModel * evene::tri_season(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Evenement Order by season ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Season"));
    return model;
}
QSqlQueryModel * evene::combox2(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select id from Evenement");
    return model;
}
QSqlQueryModel * evene::supp2(){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res= QString::number(id);
    model->setQuery("Delete from Evenement Where id = :id ");
    return model;
}
