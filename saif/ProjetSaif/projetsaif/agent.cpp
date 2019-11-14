#include "agent.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

agent::agent()
{
    cinAgent="";
    nomAgent="";
    prenomAgent="";
    dateNaisAgent="";
    salaire=0;
    sexe=0;
    idService=0;

}

agent::agent(QString cinA,QString nA,QString pA,QString dnA,double sA,int sexeA,int idSA)
{
    cinAgent=cinA;
    nomAgent=nA;
    prenomAgent=pA;
    dateNaisAgent=dnA;
    salaire=sA;
    sexe=sexeA;
    idService=idSA;
}

QString agent::get_cinAgent()
{
    return cinAgent;
}

double agent::get_nbSalaire()
{
    return salaire;
}


bool agent::ajouterAgent()
{
    QSqlQuery query;
    QString cinAgentBD=QString(cinAgent);
    QString nomAgentBD=QString(nomAgent);
    QString prenomAgentBD=QString(prenomAgent);
    QString dateNaisAgentBD=QString(dateNaisAgent);
    QString salaireBD=QString::number(salaire);
    QString sexeBD=QString::number(sexe);
    QString idServiceBD=QString::number(idService);
    query.prepare("INSERT INTO agent VALUES (:cin, :nom, :prenom, :dateNaiss, :salaire, :sexe, :idService)");
    query.bindValue(":cin",cinAgentBD);
    query.bindValue(":nom",nomAgentBD);
    query.bindValue(":prenom",prenomAgentBD);
    query.bindValue(":dateNaiss",dateNaisAgentBD);
    query.bindValue(":salaire",salaireBD);
    query.bindValue(":sexe",sexeBD);
    query.bindValue(":idService",idServiceBD);

    return query.exec();
}

QSqlQueryModel * agent::afficherAgent()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from agent");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATENAISS"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("IDSERVICE"));
    return model;
}

bool agent::supprimerAgent(QString cin)
{
    QSqlQuery query;
    QString code2=QString(cin);
    query.prepare("DELETE FROM agent WHERE ID= :cin");
    query.bindValue(":cin",cin);
    return query.exec();
}

bool agent::modifierAgent(QString cin)
{
    QSqlQuery query;
    query.prepare("UPDATE agent SET nomAgent= :nom WHERE cin= :cin AND SET prenomAgent= :prenom WHERE cin= :cin AND SET dateNaisAgent= :dateNaiss WHERE cin= :cin AND SET salaire= :salaire WHERE cin= :cin  AND SET sexe= :sexe WHERE cin= :cin AND SET idService= :idService WHERE cin= :cin");
    query.bindValue(":id",cin);
    query.bindValue(":nbPlace",nomAgent);
    query.bindValue(":prenom",prenomAgent);
    query.bindValue(":dateNaiss",dateNaisAgent);
    query.bindValue(":salaire",salaire);
    query.bindValue(":sexe",sexe);
    query.bindValue(":idService",idService);
    return query.exec();
}


