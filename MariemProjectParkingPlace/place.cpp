#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "place.h"

place::place(){
    idPlace = etatPlace = idParking = 0;
}

place::place(int idPlace, int etatPlace, int idParking){
    this->idPlace = idPlace;
    this->etatPlace = etatPlace;
    this->idParking = idParking;
}

int place::getId(){
    return idPlace;
}

int place::getEtat(){
    return etatPlace;
}

int place::getIdParking(){
    return idParking;
}

bool place::ajouter(){
    QSqlQuery query;
    QString idPlaceS = QString::number(idPlace);
    QString etatPlaceS = QString::number(etatPlace);
    QString idparkingPlaceS = QString::number(idParking);
    query.prepare("INSERT INTO place VALUES (:idPlaceS, :etatPlaceS, :idparkingPlaceS)");
    query.bindValue(":idPlaceS", idPlaceS);
    query.bindValue(":etatPlaceS", etatPlaceS);
    query.bindValue(":idparkingPlaceS", idparkingPlaceS);
    return query.exec();
}

QSqlQueryModel *  place::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM place");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Id Parking"));
    return model;
}

bool place::supprimer(int idPlace){
    QSqlQuery query;
    QString idPlaceS = QString::number(idPlace);
    query.prepare("DELETE FROM place WHERE id = :idPlaceS");
    query.bindValue(":idPlaceS", idPlaceS);
    return query.exec();
}

bool place::modifier(place pl){
    QSqlQuery query;
    QString idPlaceS = QString::number(pl.getId());
    QString etatPlaceS = QString::number(pl.getEtat());
    QString idparkingPlaceS = QString::number(pl.getIdParking());
    query.prepare("UPDATE place SET etat = :etatPlaceS, idparking = :idparkingPlaceS WHERE id = :idPlaceS");
    query.bindValue(":idPlaceS", idPlaceS);
    query.bindValue(":etatPlaceS", etatPlaceS);
    query.bindValue(":idparkingPlaceS", idparkingPlaceS);
    return query.exec();
}

QSqlQueryModel * place::afficherTriId(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM place ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * place ::afficherTriEt(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM place ORDER BY etat");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * place::afficherRechId(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString ids = QString::number(id);
    model->setQuery("SELECT * FROM place WHERE id = " + ids);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * place::afficherRechEt(int etat){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString etats = QString::number(etat);
    model->setQuery("SELECT * FROM place WHERE etat = " + etats);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * place::afficherIdParkingEt(int idParking){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString idParkingS = QString::number(idParking);
    model->setQuery("SELECT * FROM place WHERE idparking = " + idParkingS);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Id Parking"));
    return model;
}

QSqlQueryModel * place::afficherTriIdParking(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM place ORDER BY idparking");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Parking"));
    return model;
}
