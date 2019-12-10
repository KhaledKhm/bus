#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
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

QSqlQueryModel *  parking::afficher(QString triCombo, QString rechCombo, QString rechText){
    QSqlQueryModel * model = new QSqlQueryModel();
    if(triCombo == "Identifiant"){
        triCombo = "ID";
    }
    if(rechCombo == "Identifiant"){
        rechCombo = "ID";
    }
    model->setQuery("SELECT * FROM parking WHERE " + rechCombo + " LIKE '%" + rechText + "%' ORDER BY " + triCombo);
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
    if(query.exec()){
        return true;
    }else{
        QMessageBox::critical(nullptr, QObject::tr("ERREUR DE SUPRESSION"),
                    QObject::tr("Erreur - Le parking doit etre vide\n"
                                ""), QMessageBox::Cancel);
        return false;
    }
}

bool parking::modifier(parking pa, int idnew){
    QSqlQuery query;
    QString idnewParkingS = QString::number(idnew);
    QString idParkingS = QString::number(pa.getId());
    QString capaciteParkingS = QString::number(pa.getCapacite());
    QString etatParkingS = QString::number(pa.getEtat());
    query.prepare("UPDATE parking SET capacite = :capaciteParkingS, etat = :etatParkingS, id = :idnewParkingS WHERE id = :idParkingS");
    query.bindValue(":idnewParkingS", idnewParkingS);
    query.bindValue(":idParkingS", idParkingS);
    query.bindValue(":capaciteParkingS", capaciteParkingS);
    query.bindValue(":etatParkingS", etatParkingS);
    if(query.exec()){
        return true;
    }else{
        QSqlQuery qurr;
        qurr.prepare("SELECT COUNT(*) FROM place WHERE idparking = :id");
        qurr.bindValue(":id", idParkingS);
        qurr.exec();
        qurr.next();
        if(qurr.value(0).toInt() != 0){
            QMessageBox::critical(nullptr, QObject::tr("ERREUR D'AJOUT"),
                        QObject::tr("Erreur - Le parking n'est pas vide\n"
                                    "Impossible de modifier son identifiant"), QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("IDENTIFIANT DUPLIQUE"),
                        QObject::tr("Erreur - L'identifiant du parking doit etre unique\n"
                                    ""), QMessageBox::Cancel);
        }
        return false;
    }
}
