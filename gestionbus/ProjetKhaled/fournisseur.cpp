#include "fournisseur.h"

fournisseur::fournisseur()
{
    idFournisseur=0;
    nomFournisseur="";
}

fournisseur::fournisseur(int idF,QString nomF)
{
    idFournisseur=idF;
    nomFournisseur=nomF;
}

int fournisseur::get_idFournisseur()
{
    return idFournisseur;
}

QString fournisseur::get_nomFournisseur()
{
    return nomFournisseur;
}

bool fournisseur::ajouterFournisseur()
{
    QSqlQuery query;
    QString idFournisseurBD=QString::number(idFournisseur);
    QString nomFournisseurBD=QString(nomFournisseur);
    query.prepare("INSERT INTO fournisseur (idFournisseur,nomFournisseur)""VALUES(':id',':nom'");
    query.bindValue(":id",idFournisseurBD);
    query.bindValue(":nom",nomFournisseurBD);
    return query.exec();
}

QSqlQueryModel * fournisseur::afficherFournisseur()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    return model;
}

bool fournisseur::supprimerFournisseur(int id)
{
    QSqlQuery query;
    QString code2=QString::number(id);
    query.prepare("DELETE FROM fournisseur WHERE ID= :id");
    query.bindValue(":id",id);
    return query.exec();
}

bool fournisseur::modifierFournisseur(int idFournisseur)
{
    QSqlQuery query;
    query.prepare("UPDATE fournisseur SET idFournisseur= :id WHERE id= :id AND SET nom= :nom WHERE idFournisseur= :id");
    query.bindValue(":id",idFournisseur);
    query.bindValue(":nom",nomFournisseur);
    return query.exec();
}




