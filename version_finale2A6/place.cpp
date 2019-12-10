#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
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
    QSqlQuery q, qp;
    q.prepare("SELECT COUNT(*) FROM place WHERE id = :idplaceS");
    q.bindValue(":idplaceS", idPlaceS);
    q.exec();
    q.next();
    qp.prepare("SELECT capacite FROM parking WHERE id = " + idparkingPlaceS);
    qp.exec();
    qp.next();
    if(q.value(0).toInt() == qp.value(0).toInt()){
         QMessageBox::critical(nullptr, QObject::tr("PARKING SATURE"),
                 QObject::tr("Erreur - La capacité du parking selectionné a atteint\n"
                             "ses limites"), QMessageBox::Cancel);
         return false;
     }
    if(query.exec()){
        q.exec();
        q.next();
        qp.exec();
        qp.next();
        if(q.value(0).toInt() == qp.value(0).toInt()){
             QSqlQuery qu;
             qu.prepare("UPDATE parking SET etat = 0 WHERE id = :id");
             qu.bindValue(":id", idparkingPlaceS);
             qu.exec();
         }
        return true;
    }else{
        if(q.value(0).toInt() != 0){
            QMessageBox::critical(nullptr, QObject::tr("IDENTIFIANT DUPLIQUE"),
                        QObject::tr("Erreur - L'identifiant de la place doit etre unique\n"
                                    ""), QMessageBox::Cancel);
        }
    }
    return false;
}

QSqlQueryModel *  place::afficher(QString triCombo, QString rechCombo, QString rechText){
    QSqlQueryModel * model = new QSqlQueryModel();
    if(triCombo == "Identifiant"){
        triCombo = "ID";
    }
    if(rechCombo == "Identifiant"){
        rechCombo = "ID";
    }
    if(triCombo == "ID Parking"){
        triCombo = "idparking";
    }
    if(rechCombo == "ID Parking"){
        rechCombo = "idparking";
    }
    model->setQuery("SELECT * FROM place WHERE " + rechCombo + " LIKE '%" + rechText + "%' ORDER BY " + triCombo);
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

bool place::modifier(place pl, int idnew){
    QSqlQuery query;
    QString idPlaceS = QString::number(pl.getId());
    QString idnewPlaceS = QString::number(idnew);
    QString etatPlaceS = QString::number(pl.getEtat());
    QString idparkingPlaceS = QString::number(pl.getIdParking());
    query.prepare("UPDATE place SET etat = :etatPlaceS, idparking = :idparkingPlaceS, id = :idnewPlaceS WHERE id = :idPlaceS");
    query.bindValue(":idPlaceS", idPlaceS);
    query.bindValue(":idnewPlaceS", idnewPlaceS);
    query.bindValue(":etatPlaceS", etatPlaceS);
    query.bindValue(":idparkingPlaceS", idparkingPlaceS);
    if(query.exec()){
        return true;
    }else{
        QMessageBox::critical(nullptr, QObject::tr("ERREUR DE MODIFICATION"),
                    QObject::tr("Erreur - L'identifiant de la place doit etre unique\n"
                                ""), QMessageBox::Cancel);
        return false;
    }
}
