#ifndef SERVICE_H
#define SERVICE_H
#include "agent.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "ui_mainwindow.h"
#include "mainwindow.h"
class service
{
public:
    service();
    service(QString,QString,QString);
    QString get_idService();
    QString get_nomService();
    QString get_capacite();
    bool ajouterService(Ui::MainWindow*ui);
    bool modifierService(Ui::MainWindow *ui);
    QSqlQueryModel * afficherService();
    bool supprimerService(QString);
    void AfficherTableService(Ui::MainWindow *ui);
    QSqlQueryModel * comboidService();

private:
    QString idService;
    QString libelleService;
    QString capaciteService;
};

#endif // SERVICE_H
