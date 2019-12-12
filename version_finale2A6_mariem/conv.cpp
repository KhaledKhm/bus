#include "conv.h"
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
conv::conv()
{
    nomEntreprise="";
    dateFin="";
    id=0;
}
conv::conv(int id,QString nomEntreprise,QString dateFin)
{
    this->id=id;
    this->nomEntreprise=nomEntreprise;
    this->dateFin=dateFin;
}
bool conv:: ajouter_convention()
{
    QSqlQuery query;
    int i;
    QString alphabet="abcdefghijklmnopqrstuvwxyz";
    QString res=QString::number(id);
    query.prepare("INSERT INTO convention(id,nomEntreprise,dateFin) VALUES(:id,:nomEntreprise,:dateFin)");
    query.bindValue(":id",res);
    query.bindValue(":nomEntreprise",nomEntreprise);
    query.bindValue(":dateFin",dateFin);
    if(id=  NULL || nomEntreprise.isEmpty() || dateFin.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    for(i=0;i!=alphabet.length();i++)
    {
       if(nomEntreprise[i]!=alphabet[i])
       {
           QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
                QObject::tr("Erreur nom et prenom invalident!.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
           return false;
       }

    }



    return query.exec();
}
QSqlQueryModel* conv:: afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from convention" );
        return (model);
}
bool conv ::supprimer_conv(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from convention where id= :id");
    query.bindValue(":id", res);
    return    query.exec();
}
QSqlQueryModel * conv::combox(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select id from convention");
    return model;
}
bool conv::modifier()
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("UPDATE convention SET nomEntreprise= :nomEntreprise WHERE id= '"+res+"'");
    query.bindValue(":id",res);
    query.bindValue(":nomEntreprise",nomEntreprise);
    query.bindValue(":dateFin",dateFin);


    return query.exec();
}
void conv::recherche_id_place(QTableView *table, int id)
{
QString res=QString::number(id);
QSqlQueryModel *model=new QSqlQueryModel() ;
QSqlQuery qry ;
qry.prepare("Select * from convention where (regexp_like(id,:id))");
qry.bindValue(":id",res);
qry.exec() ;
model->setQuery(qry) ;
table->setModel(model) ;
table->show() ;
}
QSqlQueryModel * conv::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from convention order by nomEntreprise ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomEntreprise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateFin"));
    return model;
}
QSqlQueryModel * conv::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from convention order by id ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomEntreprise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateFin"));
    return model;
}

