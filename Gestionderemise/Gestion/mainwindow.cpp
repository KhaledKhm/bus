#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Remise.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->rech->setModel(r.recherche());
ui->tabetudiant->setModel(r.tri());
ui->tabetudiant->setModel(r.afficher());
ui->tabevent->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    float taux= ui->lineEdit_taux->text().toFloat();
    int ide= ui->lineEdit_ide->text().toInt();
  Remise r ( id ,taux,ide);
  qDebug()<<"test";
  bool test=r.ajouter();
  if(test)
{ui->tabetudiant->setModel(r.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une Remise"),
                  QObject::tr("Remise ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une remise"),
                  QObject::tr("Erreur  1.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_4->text().toInt();
bool test=r.supprimer(id);
if(test)
{ui->tabetudiant->setModel(r.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une remise"),
                QObject::tr("Remise supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une remise"),
                QObject::tr("Erreur 2 !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_ajouter_clicked()
{
    int id = ui->id_2->text().toInt();
    QString lib1 = ui->Date->text();
  Evenement e ( id , lib1);
  qDebug()<<"test";
  bool test=e.ajouter();
  if(test)
{ui->tabevent->setModel(e.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Evenement"),
                  QObject::tr("Evenement  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                  QObject::tr("Erreur  1.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_Supprimer_clicked()
{
int id = ui->id_3->text().toInt();
bool test=e.supprimer(id);
if(test)
{ui->tabevent->setModel(e.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("Evenement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenment"),
                QObject::tr("Erreur 2 !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_Modifier_clicked(){
    int id = ui->id_l->text().toInt();
    float taux= ui->taux_l->text().toFloat();
    int ide = ui->ide_l->text().toInt();
    Remise r(id, taux , ide);
    bool test = r.modifier();
    if(test){
        ui->tabetudiant->setModel(r.afficher());
    }
}

void MainWindow::on_tri_clicked(){
    bool test = r.tri();
    if (test){
    ui->tabetudiant->setModel(r.tri());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri terminer"),
    QObject::tr("Tri terminer.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche_clicked()
{
//int id = ui->id_6->text().toInt();
bool test=r.recherche();
if(test)
{ui->rech->setModel(r.recherche());//refresh
    QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                QObject::tr("Recherche Terminer.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                QObject::tr("Erreur 2 !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
