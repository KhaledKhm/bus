#ifndef AGENT_H
#define AGENT_H

#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
//#include "ui_mainwindow.h"
//#include "mainwindow.h"
#include "ui_gerer_agent.h"
#include "gerer_agent.h"

class agent
{
public:
    agent();
    agent(QString,QString,QString,QString,QString,QString,QString);
    QString get_cinAgent();
    QString get_Salaire();
    QString get_nomagent();
    QString get_prenomagent();
    QString get_dateNaisAgent();
    QString get_sexe();
    QString get_idService();
    bool ajouterAgent(Ui::gerer_agent*ui);
    bool modifierAgent(Ui::gerer_agent *ui);
    void afficherAgent(Ui::gerer_agent *ui);
    QSqlQueryModel * afficherAgent();
    bool supprimerAgent(QString);
    void AfficherTableAgent(Ui::gerer_agent *ui);
    QSqlQueryModel *trieragent(QString);
    QSqlQueryModel *rechercheragent(QString Nom);
    QSqlQueryModel * comboidAgent();
    QSqlQueryModel * comboidServiceAgent();

private:
    QString cinAgent;
    QString nomAgent;
    QString prenomAgent;
    QString dateNaisAgent;
    QString salaire;
    QString sexe;
    QString idService;
};
#endif // AGENT_H
