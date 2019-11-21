#include "materiel.h"


materiel::materiel()
{
    idMateriel=0;
    nomMateriel="";
    quantiteMateriel=0;
    prixMateriel=0;
    idFournisseurMateriel=0;
}

materiel::materiel(int idM,QString nomM,int qtM,double prixM,int idFM)
{
    idMateriel=idM;
    nomMateriel=nomM;
    quantiteMateriel=qtM;
    prixMateriel=prixM;
    idFournisseurMateriel=idFM;
}

int materiel::get_idMateriel()
{
    return idMateriel;
}

QString materiel::get_nomMateriel()
{
    return nomMateriel;
}

bool materiel::ajouterMateriel()
{
    QSqlQuery query;
    QString idMaterielBD=QString::number(idMateriel);
  //  QString nomMaterielBD=QString(nomMateriel);
    QString quantiteMaterielBD=QString::number(quantiteMateriel);
    QString prixMaterielBD=QString::number(prixMateriel);
    QString idFournisseurMaterielBD=QString::number(idFournisseurMateriel);
    query.prepare("INSERT INTO materiel VALUES(:id,:nom,:quantite,:prix,:idFournisseur)");
    query.bindValue(":id",idMaterielBD);
    query.bindValue(":nom",nomMateriel);
    query.bindValue(":quantite",quantiteMaterielBD);
    query.bindValue(":prix",prixMaterielBD);
    query.bindValue(":idFournisseur",idFournisseurMaterielBD);
    return query.exec();
}

QSqlQueryModel * materiel::afficherMateriel()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from materiel");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDFOURNISSEUR"));
    return model;
}

bool materiel::supprimerMateriel(int id)
{
    QSqlQuery query;
    QString code2=QString::number(id);
    query.prepare("DELETE FROM materiel WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}

bool materiel::modifierMateriel(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE materiel SET  nom= :nom, quantite= :quantite, prix= :prix, idFournisseur= :idFournisseur WHERE id= :id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nomMateriel);
    query.bindValue(":quantite",quantiteMateriel);
    query.bindValue(":prix",prixMateriel);
    query.bindValue(":idFournisseur",idFournisseurMateriel);
    return query.exec();
}


QSqlQueryModel * materiel::recherche(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Remise where id = :id ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("taux"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ide"));
    return model;
}
QSqlQueryModel * materiel::stat(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select  Max(quantite) , Avg(quantite) , Min(quantite) from materiel  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Max"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Avg"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Min"));
    return model;
}