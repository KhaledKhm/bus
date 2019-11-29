#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "station.h"

station::station(){
    idStation = etatStation = 0;
    libelleStation = localisationStation = "";
}

station::station(int idStation, QString libelleStation, QString localisationStation, int etatStation){
    this->idStation = idStation;
    this->libelleStation = libelleStation;
    this->etatStation = etatStation;
    this->localisationStation = localisationStation;
}

int station::getId(){
    return idStation;
}

int station::getEtat(){
    return etatStation;
}

QString station::getLibelle(){
    return libelleStation;
}

QString station::getLocalisation(){
    return localisationStation;
}

bool station::ajouter(){
    QSqlQuery query;
    QString idStationS = QString::number(idStation);
    QString etatStationS = QString::number(etatStation);
    query.prepare("INSERT INTO station VALUES (:idStationS, :libelleStation, :localisationStation, :etatStationS)");
    query.bindValue(":idStationS", idStationS);
    query.bindValue(":libelleStation", libelleStation);
    query.bindValue(":localisationStation", localisationStation);
    query.bindValue(":etatStationS", etatStationS);
    return query.exec();
}

QSqlQueryModel *  station::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM station");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Libelle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Localisation"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

bool station::supprimer(int idStation)
{
    QSqlQuery query;
    QString idStationS = QString::number(idStation);
    query.prepare("delete FROM station WHERE ID =:idStation");
    query.bindValue(":idStation", idStationS);
    return query.exec();
}

bool station::modifier(station st){
    QSqlQuery query;
    QString idStationS = QString::number(st.getId());
    QString etatStationS = QString::number(st.getEtat());
    query.prepare("UPDATE station SET etat = :etatStationS, localisation = :localisationStation, libelle = :libelleStation WHERE id = :idStationS");
    query.bindValue(":idStationS", idStationS);
    query.bindValue(":localisationStation", st.getLocalisation());
    query.bindValue(":etatStationS", st.getEtat());
    query.bindValue(":libelleStation", st.getLibelle());
    return query.exec();
}

QString test_recherche2(int c)
{
    if (c==0)
    {
    return "ID " ;
    }
    else if (c==1)
    {
      return "LIBELLE" ;
    }
    else if (c==2)
    {
     return "LOCALISATION " ;
    }
    else if (c==3)
    {
     return "ETAT";
    }

    return "NULL";
}


QSqlQueryModel*station:: recherche1(QString x,int i)
{
    QString col = test_recherche2(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT* FROM station WHERE "+col+" LIKE '"+x+"%'";
    model->setQuery(header);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Libelle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Localisation"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etat"));

    return model ;
}


QString test_tri(int c)
{
    if (c==0)
    {
    return "ID " ;
    }
    else if (c==1)
    {
      return "LIBELLE" ;
    }
    else if (c==2)
    {
     return "LOCALISATION " ;
    }
    else if (c==3)
    {
     return "ETAT";
    }

    return "NULL";
}


QSqlQueryModel* station:: tri(int i)
{
    QString col = test_tri(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT * FROM station ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Libelle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Localisation"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etat"));


    return model ;
}
