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
    QString res=QString::number(id);
    query.prepare("INSERT INTO convention(id,nomEntreprise,dateFin) VALUES(:id,:nomEntreprise,:dateFin)");
    query.bindValue(":id",res);
    query.bindValue(":nomEntreprise",nomEntreprise);
    query.bindValue(":dateFin",dateFin);
    if(id=  NULL || nomEntreprise.isEmpty() || dateFin.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    return query.exec();
}
QSqlQueryModel* conv:: afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from convention" );
        return (model);
}
bool conv::rechercher(int id)
{
    QSqlQuery query;
    int count=0;
    bool test=0;
    QString res=QString::number(id);
    if(query.exec("select * from convention where id='"+res+"'"))
    {
        while (query.next()) {
            count++;
        }
        if(count>=1){
            test=1;
        return test;
        }
    }
    return test;

}
bool conv ::supprimer_conv(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from convention where id= :id");
    query.bindValue(":id", res);
    return    query.exec();
}
QSqlQueryModel * conv::chercher(int id)
 {
    bool queryresult ;
     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
      QString res=QString::number(id);
     query.prepare("select * from convention WHERE id=:id");

     query.bindValue(":id",res);

      queryresult = query.exec();
      if ( queryresult ){
    model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom Entreprise"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date fin"));
     return model;

          }
      else {
          model = nullptr;
          return model;

            }
}
QSqlQueryModel *conv:: tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from convention order by id ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom Entreprise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date fin"));

    return model;
}
QSqlQueryModel* conv:: tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM convention  ORDER BY nomEntreprise ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom Entreprise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date fin"));

    return model;
}
bool conv::update()
{

      QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(id);

              QString editer ="Update convention set" ;
            query.bindValue(":nom entreprise",nomEntreprise);
            if(nomEntreprise!="")
            {
                editer+=" NOMENTREPRISE = :nomEntreprise" ;
                first=1 ;
            }

            query.bindValue(":dateFin",dateFin);
            if(dateFin!=""&& first!=0)
                editer+=" ,DATEFIN= :dateFin" ;
            else if (dateFin!=""&&first==0)
              {
                editer+=" DATE FIN= :dateFin" ;
                first=1 ;
              }

                   editer+=" where ID = :id" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();


                query.prepare(final);


                query.bindValue(":id",QVariant(res1).toInt());



                query.bindValue(":nomEntreprise",nomEntreprise);
                query.bindValue(":dateFin",dateFin);


             return query.exec();
}

