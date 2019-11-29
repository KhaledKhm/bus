#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "parking.h"

parking::parking(){
    idParking = capaciteParking = etatParking = 0;
}

parking::parking(int idParking, int capaciteParking, int etatParking){
    this->idParking = idParking;
    this->capaciteParking = capaciteParking;
    this->etatParking = etatParking;
}

int parking::getId(){
    return idParking;
}

int parking::getCapacite(){
    return capaciteParking;
}

int parking::getEtat(){
    return etatParking;
}

bool parking::ajouter(){
    QSqlQuery query;
    QString idParkingS = QString::number(idParking);
    QString capaciteParkingS = QString::number(capaciteParking);
    QString etatParkingS = QString::number(etatParking);
    query.prepare("INSERT INTO parking VALUES (:idParkingS, :capaciteParkingS, :etatParkingS)");
    query.bindValue(":idParkingS", idParkingS);
    query.bindValue(":capaciteParkingS", capaciteParkingS);
    query.bindValue(":etatParkingS", etatParkingS);
    return query.exec();
}

QSqlQueryModel *  parking::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM parking");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

bool parking::supprimer(int idParking){
    QSqlQuery query;
    QString idParkingS = QString::number(idParking);
    query.prepare("DELETE FROM parking WHERE id = :idParkingS");
    query.bindValue(":idParkingS", idParkingS);
    return query.exec();
}

bool parking::modifier(parking pa){
    QSqlQuery query;
    QString idParkingS = QString::number(pa.getId());
    QString capaciteParkingS = QString::number(pa.getCapacite());
    QString etatParkingS = QString::number(pa.getEtat());
    query.prepare("UPDATE parking SET capacite = :capaciteParkingS, etat = :etatParkingS WHERE id = :idParkingS");
    query.bindValue(":idParkingS", idParkingS);
    query.bindValue(":capaciteParkingS", capaciteParkingS);
    query.bindValue(":etatParkingS", etatParkingS);
    return query.exec();
}

QSqlQueryModel * parking::afficherTriId(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM parking ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * parking::afficherTriCap(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM parking ORDER BY capacite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * parking::afficherTriEt(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM parking ORDER BY etat");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * parking::afficherRechId(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString ids = QString::number(id);
    model->setQuery("SELECT * FROM parking WHERE id = " + ids);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * parking::afficherRechCap(int capacite){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString capacites = QString::number(capacite);
    model->setQuery("SELECT * FROM parking WHERE capacite = " + capacites);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

QSqlQueryModel * parking::afficherRechEt(int etat){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString etats = QString::number(etat);
    model->setQuery("SELECT * FROM parking WHERE etat = " + etats);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}
