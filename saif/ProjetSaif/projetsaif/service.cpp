#include "service.h"

service::service()
{
    idService=0;
    libelleService="";
    capaciteService=0;
}

service::service(int idS,QString libelleS,int capaS)
{
    idService=idS;
    libelleService=libelleS;
    capaciteService=capaS;
}

int service::get_idService()
{
    return idService;
}

QString service::get_nomService()
{
    return libelleService;
}

bool service::ajouterService()
{
    QSqlQuery query;
    QString idServiceBD=QString::number(idService);
    QString capaciteServiceBD=QString::number(capaciteService);
    query.prepare("INSERT INTO service VALUES(:id, :libelle, :capacite)");
    query.bindValue(":id",idServiceBD);
    query.bindValue(":libelle",libelleService);
    query.bindValue(":capacite",capaciteServiceBD);
    return query.exec();
}

QSqlQueryModel * service::afficherService()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from service");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("LIBELLE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CAPACITE"));
    return model;
}

bool service::supprimerService(int id)
{
    QSqlQuery query;
    QString code2=QString::number(id);
    query.prepare("DELETE FROM service WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}

bool service::modifierService(int idService)
{
    QSqlQuery query;
    query.prepare("UPDATE service SET idService= :id WHERE id= :id AND SET libelle= :libelle WHERE idService= :id AND SET capacite= :capacite WHERE idService= :id");
    query.bindValue(":id",idService);
    query.bindValue(":libelle",libelleService);
    query.bindValue(":capacite",capaciteService);
    return query.exec();
}




