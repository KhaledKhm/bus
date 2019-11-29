#include "abonnement_normal.h"
#include <QSqlQuery>

abonnement_normal::abonnement_normal()
{
    nom="";
    prenom="";
    email="";
    age=0;
    cin=0;
    date_debut="";
    date_fin="";
    prix=0;

}
abonnement_normal::abonnement_normal(int cin,QString nom,QString prenom,int age,QString email,QString date_debut,QString date_fin,float prix)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->email=email;
    this->date_debut=date_debut;
    this->date_fin=date_fin;
    this->prix=prix;


}
QSqlQueryModel *abonnement_normal::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from abonnement_normal" );
        return (model);
}
QSqlQueryModel * abonnement_normal::triAb_age()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_normal order by age ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date debut"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date fin"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));

    return model;
}
QSqlQueryModel * abonnement_normal::triAb_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from abonnement_normal order by nom ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date debut"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date fin"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));

    return model;
}
bool abonnement_normal::supprimerAb(int cin)
{
QSqlQuery query;
query.prepare("delete from abonnement_normal where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}

QSqlQueryModel * abonnement_normal::chercher(int cin)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from abonnement_normal WHERE cin=:cin"));

     query.bindValue(":cin",cin);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("date debut"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("date fin"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("prix"));
return model;
 }
bool abonnement_normal::update()
{

      QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(cin);
            QString res=QString::number(age);
           // QString res2=QString::number(tel);
              QString editer ="Update abonnement_normal set" ;
            query.bindValue(":nom",nom);
            if(nom!="")
            {
                editer+=" NOM = :nom" ;
                first=1 ;
            }

            query.bindValue(":prenom",prenom);
            if(prenom!=""&& first!=0)
                editer+=" ,PRENOM= :prenom" ;
            else if (prenom!=""&&first==0)
              {
                editer+=" PRENOM= :prenom" ;
                first=1 ;
              }
                 query.bindValue(":email",email);
                 if(email!=""&& first!=0)
                     editer+=" ,EMAIL= :email" ;
                 else if (email!="" && first==0)
                 {
                    editer+=" EMAIL = :email" ;
                    first=1 ;
                 }

                 query.bindValue(":age",age);
                                  if(res!=""&& first!=0)
                                      editer+=" ,AGE= :age" ;
                                  else if (res!="" && first==0)
                                  {
                                     editer+=" AGE = :age" ;
                                     first=1 ;
                                  }

                 query.bindValue(":date_debut",date_debut);
                                 if(date_debut!=""&& first!=0)
                                    editer+=" ,DATE_DEBUT= :date_debut" ;
                                    else if (date_debut!="" && first==0)
                                    {
                                        editer+=" DATE_DEBUT = :date_debut" ;
                                        first=1 ;
                                     }
                query.bindValue(":date_fin",date_fin);
                                   if(date_fin!=""&& first!=0)
                                       editer+=" ,DATE_FIN= :date_fin" ;
                                       else if (date_fin!="" && first==0)
                                           {
                                               editer+=" DATE_FIN = :date_fin" ;
                                               first=1 ;
                                            }
                   editer+=" where CIN = :cin" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();


                query.prepare(final);


                query.bindValue(":cin",QVariant(res1).toInt());



                query.bindValue(":nom",nom);
                query.bindValue(":prenom",prenom);
                query.bindValue(":email",email);
                query.bindValue(":age",res);
                query.bindValue(":date_debut",date_debut);
                query.bindValue(":date_fin",date_fin);


             return query.exec();
}
bool abonnement_normal::rechercher(int cin)
{
    QSqlQuery query;
    int count=0;
    bool test=0;
    QString res=QString::number(cin);
    if(query.exec("select * from abonnement_normal where CIN='"+res+"'"))
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
