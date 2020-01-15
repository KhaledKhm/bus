#include "agent.h"
//#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "gerer_agent.h"
#include "ui_gerer_agent.h"

#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <utility>
agent::agent()
{
    cinAgent="";
    nomAgent="";
    prenomAgent="";
    dateNaisAgent="";
    salaire="";
    sexe="";
    idService="";

}

agent::agent(QString cinA,QString nA,QString pA,QString dnA,QString sA,QString sexeA,QString idSA)
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

QString agent::get_Salaire()
{
    return salaire;
}
QString agent::get_nomagent()
{
    return nomAgent ;
}

QString agent::get_prenomagent(){

    return prenomAgent ;


}
QString agent::get_dateNaisAgent(){

    return dateNaisAgent ;

}
QString agent::get_sexe(){
    return sexe ;
}

QString agent::get_idService(){
return idService;
}

bool agent::ajouterAgent(Ui::gerer_agent *ui){

    bool choix=true;

    QSqlQuery query;
    query.prepare("INSERT INTO agent(CIN,NOM,PRENOM,IDBADGE,SALAIRE,SEXE,IDSERVICE) VALUES ( :cin, :nom, :prenom, :age, :salaire, :sexe, :idService)");
    if ((ui->LECIN->text().isEmpty())

            ){
        choix=false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter CIN"),
                            QObject::tr("CIN invlid!\n"
                                        "Click Ok to close."), QMessageBox::Ok);

    }
    if(choix==true){
    query.bindValue(":cin",ui->LECIN->text());
    query.bindValue(":nom",ui->LEajoutnom->text());
    query.bindValue(":prenom",ui->LEajoutprenom->text());
    query.bindValue(":age",ui->LEdatenaiss->text());
    query.bindValue(":salaire",ui->LEsalaire->text());
    query.bindValue(":sexe",ui->choixsex->currentText());
    //query.bindValue(":idService",ui->LEID->text());

    query.bindValue(":idService",ui->cbIDServiceAjout->currentText());
    if(ui->LEdatenaiss->text().isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    }if(query.exec())

       { QMessageBox msgBox ;
                msgBox.setText("le client a ete ajoute");
                msgBox.exec();
        return true;

   } else

{
        QMessageBox msgBox ;
                msgBox.setText("le client n'est pas ajoute ");
                msgBox.exec();
        return false;
    }
}




bool agent::modifierAgent(Ui::gerer_agent *ui)
{
    QSqlQuery q;
    q.prepare("update agent set NOM=:nom,PRENOM=:prenom,IDBADGE=:age,SALAIRE=:salaire,SEXE=:sexe where CIN=:cin" );

    q.bindValue(":cin",ui->cbModifCINAgent->currentText());
  //  q.bindValue(":cin",ui->LEMODIFCIN->text());
    q.bindValue(":nom",ui->LEmodifnom->text());
    q.bindValue(":prenom",ui->LEmodifprenom->text());
    q.bindValue(":age",ui->LEmodifdatenaiss->text());
    q.bindValue(":salaire",ui->LEmodifsalaire->text());
    q.bindValue(":sexe",ui->choixsex_modif->currentText());



    if(q.exec())
    {

        QMessageBox msgBox ;
                msgBox.setText("l'agent a ete modifie ");
                msgBox.exec();
        return true;
    }
    else
{
        QMessageBox msgBox ;
                msgBox.setText("l'agent n'est pas modifie ");
                msgBox.exec();
        return false;
}
}


void agent::afficherAgent(Ui::gerer_agent *ui)
{
    QSqlQuery q,k;
    q.prepare("select * from agent WHERE cin='"+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString()+"'");

    q.exec();
    q.next();

    ui->LECIN->setText(q.value(1).toString());
    ui->LEajoutnom->setText(q.value(2).toString());
    ui->LEajoutprenom->setText(q.value(3).toString());
    ui->LEsalaire->setText(q.value(4).toString());
    //ui->LEID->setText(q.value(5).toString());
    ui->LEdatenaiss->setText(q.value(6).toString());
    ui->choixsex->setCurrentText(q.value(7).toString());




}
void agent::AfficherTableAgent(Ui::gerer_agent *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from agent");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}

bool agent::supprimerAgent(QString cin)
{
    QSqlQuery query;
    QString code2=QString(cin);
    query.prepare("DELETE FROM agent WHERE CIN= :cin");
    query.bindValue(":cin",cin);
    return query.exec();
}
QSqlQueryModel *agent::trieragent(QString col)
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  CIN,NOM,PRENOM,IDBADGE,SALAIRE,SEXE,IDSERVICE from agent order by "+col);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    //model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATENAISS"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("IDSERVICE"));
   return model ;
}
QSqlQueryModel *agent::rechercheragent(QString Nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select * from agent where nom like '%" + Nom + "%'");
        return model;

}

QSqlQueryModel * agent::comboidAgent(){

    QSqlQueryModel *modal=new QSqlQueryModel();
    modal->setQuery("select cin from agent");
    return modal;
}

QSqlQueryModel * agent::comboidServiceAgent(){

    QSqlQueryModel *modal=new QSqlQueryModel();
    modal->setQuery("select id from service");
    return modal;
}

