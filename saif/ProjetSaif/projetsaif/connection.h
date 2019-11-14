#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

class Connection
{
private:
    QSqlDatabase db;

public:
    Connection();
    bool createconnect();
    void fermerConnexion();
};

#endif // CONNECTION_H
