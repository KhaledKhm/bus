#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class agent
{
public:
    agent();
    agent(QString,QString,QString,QString,double,int,int);
    QString get_cinAgent();
    double get_nbSalaire();
    bool ajouterAgent();
    bool modifierAgent(QString);
    QSqlQueryModel * afficherAgent();
    bool supprimerAgent(QString);
private:
    QString cinAgent;
    QString nomAgent;
    QString prenomAgent;
    QString dateNaisAgent;
    double salaire;
    int sexe;
    int idService;
};

#endif // AGENT_H
