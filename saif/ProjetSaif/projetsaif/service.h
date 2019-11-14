#ifndef SERVICE_H
#define SERVICE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class service
{
public:
    service();
    service(int,QString,int);
    int get_idService();
    QString get_nomService();
    bool ajouterService();
    bool modifierService(int);
    QSqlQueryModel * afficherService();
    bool supprimerService(int);
private:
    int idService;
    QString libelleService;
    int capaciteService;
};

#endif // SERVICE_H
