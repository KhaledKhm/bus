#include "service.h"
#include "agent.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlQuery>
service::service()
    {
        idService="";
        libelleService="";
        capaciteService="";
    }

    service::service(QString idS,QString libS,QString cpS)
    {
        idService=idS;
        libelleService=libS;
        capaciteService=cpS;
    }

    QString service::get_idService()
    {
        return idService;
    }

    QString service::get_nomService()
    {
        return libelleService;
    }
    QString service::get_capacite()
    {
        return capaciteService ;
    }

    bool service::ajouterService(Ui::MainWindow *ui)      {

        QSqlQuery query;
        query.prepare("INSERT INTO service (ID,LIBELLE,CAPACITE) VALUES ( :id, :libelle, :capacite)");
        query.bindValue(":id",ui->LEID_2->text());
        query.bindValue(":libelle",ui->LELIBELLE->text());
        query.bindValue(":capacite",ui->LECAPACITE->text());


        if(query.exec())

           { QMessageBox msgBox ;
                    msgBox.setText("le service a ete ajoute");
                    msgBox.exec();
            return true;
        }
        else

    {
            QMessageBox msgBox ;
                    msgBox.setText("le service n'est pas ajoute ");
                    msgBox.exec();
            return false;
        }
    }




    bool service::modifierService(Ui::MainWindow *ui)
    {
        QSqlQuery q;
     //   idService=ui->cbModifServ->currentText();
        q.prepare("UPDATE service set LIBELLE= :libelle,CAPACITE= :capacite WHERE ID= :idService");
        q.bindValue(":id",ui->cbModifServ->currentText());
        q.bindValue(":libelle",ui->LEMODIFLIBELLE->text());
        q.bindValue(":capacite",ui->LEMODIFCAPA->text().toInt());



        if(q.exec())
        {

            QMessageBox msgBox ;
                    msgBox.setText("le service a ete modifie ");
                    msgBox.exec();
            return true;
        }
        else
    {
            QMessageBox msgBox ;
                    msgBox.setText("le le service n'est pas modifie ");
                    msgBox.exec();
            return false;
    }
    }





    void service::AfficherTableService(Ui::MainWindow *ui)
    {
        QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        q.prepare("select ID,LIBELLE,CAPACITE from service");
        q.exec();
        modal->setQuery(q);
        ui->AFFICHESERVICE->setModel(modal);
    }

    bool service::supprimerService(QString idService)
    {
        QSqlQuery query;
        QString code2=QString(idService);
        query.prepare("DELETE FROM service WHERE ID= :id");
        query.bindValue(":id",idService);
        return query.exec();
    }
    /*
    QSqlQueryModel *agent::trieragent(QString col)
    {
        QSqlQueryModel *model= new QSqlQueryModel() ;
        model->setQuery("select  CIN,NOM,PRENOM,DATENAISS,SALAIRE,SEXE,IDSERVICE from agent order by "+col);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
       return model ;
    }

*/

QSqlQueryModel * service::comboidService(){
    QSqlQueryModel *modal=new QSqlQueryModel();
    modal->setQuery("select ID from service");
    return modal;

    }
