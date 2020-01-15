#include "bus.h"

bus::bus()
{
    id=0;
    nbPlace=0;
    destination="";
    idFournisseur=0;
    idTrajet=0;
    idPlace=0;
    //cinAgent="";
}

bus::bus(int idB,int nb,QString des,int idF,int idT,int idP,QString cinA)
{
    id=idB;
    nbPlace=nb;
    destination=des;
    idFournisseur=idF;
    idTrajet=idT;
    idPlace=idP;
    cinAgent=cinA;
}

int bus::get_id()
{
    return id;
}

int bus::get_nbPlace()
{
    return nbPlace;
}

int bus::get_idFournisseur()
{
    return idFournisseur;
}

int bus::get_idTrajet()
{
    return idTrajet;
}

int bus::get_idPlace()
{
    return idPlace;
}

bool bus::ajouter()
{
    QSqlQuery query;
    QString idBD=QString::number(id);
    QString nbPlaceBD=QString::number(nbPlace);
    //QString destinationBD=QString(destination);
    QString idFournisseurBD=QString::number(idFournisseur);
    QString idTrajetBD=QString::number(idTrajet);
    QString idPlaceBD=QString::number(idPlace);
    //QString cinAgentBD=QString(cinAgent);
    query.prepare("INSERT INTO bus VALUES (:id, :nbPlace, :destination, :idFournisseur, :idTrajet, :idPlace, :cinAgent)");
    query.bindValue(":id",idBD);
    query.bindValue(":nbPlace",nbPlaceBD);
    query.bindValue(":destination",destination);
    query.bindValue(":idFournisseur",idFournisseurBD);
    query.bindValue(":idTrajet",idTrajetBD);
    query.bindValue(":idPlace",idPlaceBD);
    query.bindValue(":cinAgent",cinAgent);

    return query.exec();
}

QSqlQueryModel * bus::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from bus");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
    return model;
}
/*
bool bus::rechercher(int id){
    QSqlQuery query;
    int count=0;
    bool test=0;
    QString res=QString::number(id);
    if(query.exec("select id from bus where bus='" +res +"'"))
    {
        while(query.next())
            count++;
        if(count>=1)
            test=1;
    }return id;
}*/
bool bus::supprimer(int id)
{
    QSqlQuery query;
    QString code2=QString::number(id);
    query.prepare("DELETE FROM bus WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}

bool bus::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE bus SET nbPlace= :nbPlace, destination= :destination,  idTrajet= :idTrajet,  idPlace= :idPlace, cin= :cin WHERE id= :id");
    query.bindValue(":id",id);
    query.bindValue(":nbPlace",nbPlace);
    query.bindValue(":destination",destination);
   // query.bindValue(":idFournisseur",idFournisseur);
    query.bindValue(":idTrajet",idTrajet);
    query.bindValue(":idPlace",idPlace);
    query.bindValue(":cinAgent",cinAgent);
    return query.exec();
}

QSqlQueryModel * bus::triBus(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from bus order by id");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
return model;
}
QSqlQueryModel * bus::triBus2(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from bus order by id DESC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
return model;
}

QSqlQueryModel * bus::triBus3(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from bus order by nbplace");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
return model;
}

QSqlQueryModel * bus::triBus4(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from bus order by nbplace DESC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
return model;
}

QSqlQueryModel * bus::triBus5(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from bus order by destination");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
return model;
}

QSqlQueryModel * bus::triBus6(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from bus order by destination DESC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
return model;
}

QSqlQueryModel * bus::rechercheBus(int id){
QSqlQueryModel * model= new QSqlQueryModel();
QString code=QString::number(id);
model->setQuery("select * FROM bus WHERE id="+code );
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IMMATRICULE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBPLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESTINATION"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDTRAJET"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IDPLACE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("CINAGENT"));
    return model;
}

QSqlQueryModel * bus::comboxidbus(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select id from bus");
    return model;
}

