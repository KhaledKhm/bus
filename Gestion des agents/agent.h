#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "ui_mainwindow.h"
#include "mainwindow.h"
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
    bool ajouterAgent(Ui::MainWindow*ui);
    bool modifierAgent(Ui::MainWindow *ui);
    void afficherAgent(Ui::MainWindow *ui);
    QSqlQueryModel * afficherAgent();
    bool supprimerAgent(QString);
    void AfficherTableAgent(Ui::MainWindow *ui);
    QSqlQueryModel *trieragent(QString);
    QSqlQueryModel *rechercheragent(QString Nom);
    QSqlQueryModel * comboidAgent();

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
