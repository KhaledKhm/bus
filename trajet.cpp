#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "trajet.h"

trajet::trajet()
{
    ID=0;
    IDSTATIONARRET = 0;
    HEUREDEPART="";
    HEUREARRIVEE="";
}

trajet::trajet(int id, QString h,QString he,int ids)
{
    ID=id;
    HEUREDEPART=h;
    HEUREARRIVEE=he;
    IDSTATIONARRET = ids;

}

int trajet::getId()
{
    return ID;
}

QString trajet::getHeuredepart()
{
    return HEUREDEPART;
}

QString trajet::getHeurearri()
{
    return     HEUREARRIVEE;
}

int trajet::getIds()
{
    return ID;
}
bool trajet::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID);
    QString res2 = QString::number(IDSTATIONARRET);
    query.prepare("INSERT INTO trajet1(ID,HEUREDEPART,HEUREARRIVEE,IDSTATIONARRET) VALUES(:ID, :HEUREDEPART, :HEUREARRIVEE, :IDSTATIONARRET)");
    query.bindValue(":ID",res);
    query.bindValue(":HEUREDEPART",HEUREDEPART);
    query.bindValue(":HEUREARRIVEE",HEUREARRIVEE);
    query.bindValue(":IDSTATIONARRET",res2);


    return query.exec();
}

QSqlQueryModel *  trajet::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM trajet1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Heure Depart"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Heure Arrivee"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Identifiant Station Arret"));
    return model;
}

bool trajet::supprimer(int ID)
{
    QSqlQuery query;
    QString res = QString::number(ID);
    query.prepare("DELETE FROM trajet1 WHERE ID = :ID");
    query.bindValue(":ID", res);
    return query.exec();
}

bool trajet::modifier()
{
    QSqlQuery query;
    QString res = QString::number(ID);
    QString res2 = QString::number(IDSTATIONARRET);
    query.prepare("UPDATE trajet1 SET HEUREDEPART=:HEUREDEPART, HEUREARRIVEE=:HEUREARRIVEE ,IDSTATIONARRET=:IDSTATIONARRET WHERE ID=:ID");
    query.bindValue(":ID", res);
    query.bindValue(":HEUREDEPART", HEUREDEPART);
    query.bindValue(":HEUREARRIVEE", HEUREARRIVEE);
    query.bindValue(":IDSTATIONARRET", res2);

    return query.exec();
}

QString test_recherche(int c)
{
    if (c==0)
    {
    return "ID" ;
    }
    else if (c==1)
    {
        return "HEUREARRIVEE";
    }
    else if (c==2)
    {
    return "HEUREDEPART" ;
    }
    else if (c==3)
    {
        return "IDSTATIONARRET" ;
    }

    return "NULL";
}

QSqlQueryModel*trajet:: recherche2(QString x,int i)
{
    QString col = test_recherche(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT* FROM trajet1 WHERE "+col+" LIKE '"+x+"%'";
    model->setQuery(header);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Heure Depart"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Heure Arrivee"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Identifiant Station Arret"));

    return model ;
}


QString test_tri2(int c)
{
    if (c==0)
    {
    return "ID" ;
    }
    else if (c==1)
    {
        return "HEUREARRIVEE";
    }
    else if (c==2)
    {
    return "HEUREDEPART" ;
    }
    else if (c==3)
    {
        return "IDSTATIONARRET" ;
    }

    return "NULL";
}

QSqlQueryModel* trajet::tri(int i)
{
    QString col = test_tri2(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT * FROM trajet1 ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Heure Depart"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Heure Arrivee"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Identifiant Station Arret"));
    return model ;
}
