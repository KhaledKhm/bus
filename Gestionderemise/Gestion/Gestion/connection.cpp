#include "connection.h"
#include <QSqlError>
Connection::Connection(){
                      }
bool Connection::ouvrirConnection()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("base donnees");
                           db.setUserName("Med");//inserer nom de l'utilisateur
                           db.setPassword("123");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connection::fermerConnection()
{db.close();}
