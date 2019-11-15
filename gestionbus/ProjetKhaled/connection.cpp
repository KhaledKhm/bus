#include "connection.h"
#include<QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("ProjetBus");//inserer nom de l'utilisateur
db.setPassword("ProjetBus");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

//else throw QString("Erreur Paremetres"+db.lastError().test);





    return  test;
}

void Connection::fermerConnexion()
{db.close();}

