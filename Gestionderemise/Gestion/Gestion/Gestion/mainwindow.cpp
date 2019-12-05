#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Remise.h"
#include "evenement.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QMediaPlayer>
#include <QtPrintSupport>
#include <QPainter>
#include <QPixmap>
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
QPixmap pix2("C:/Users/moham/Desktop/SHREK3");
ui->tabetudiant->setModel(r.afficher());
ui->tabetudiant->setModel(r.afficher());
ui->tabevent->setModel(e.afficher());
ui->rech->setModel(r.afficher());
ui->imp->setModel(r.afficher());
ui->comboBox_2->setModel(r.combox());
ui->comboBox_3->setModel(r.combox());
ui->comboBox_5->setModel(e.combox2());
ui->comboide->setModel(r.combox8());
ui->Comboxid->setModel(e.combox2());
ui->tabsupp->setModel(r.afficher());
ui->tabmodd->setModel(r.afficher());
ui->tabmodd_2->setModel(e.afficher());
mainLayout=new QVBoxLayout ;
mainLayout->addWidget(s.Preparechart());
ui->stat2->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    bool verif_id , verif_taux , verif_ide;
            verif_id   = true; verif_ide = true; verif_taux = true ;
    int id = ui->lineEdit_id->text().toInt();
    if (id < 0 || id > 20){
           verif_id = false;
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Erreur id.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
    float taux= ui->lineEdit_taux->text().toFloat();
    if (taux >10){
            verif_taux = false;
            QMessageBox::information(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Erreur taux.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    int ide= ui->comboide->currentText().toInt();
    QString type = ui->type->currentText();
    if (ide <0 || ide > 20){
           verif_ide = false;
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Erreur ide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
    if((verif_id == true) && (verif_ide == true) && (verif_taux == true)){
  Remise r ( id ,taux,ide,type);
  qDebug()<<"test";
  bool test=r.ajouter();
  if(test)
{
      ui->tabetudiant->setModel(r.afficher());//refresh
      qDebug() <<"Remise ajoute";
          }
  else{
             qDebug() <<"Erreur d'ajout de remise";
          }
      }else{
          qDebug() << "Erreur de controle de saisie";
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Control de saisie\n"
                                  ""), QMessageBox::Cancel);
      }
}

void MainWindow::on_pb_supprimer_clicked()
{
     bool verif_id = true ;
int id = ui->comboBox_3->currentText().toInt();
bool test=r.supprimer(id);
if(test)
{ui->tabetudiant->setModel(r.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une remise"),
                QObject::tr("Remise supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

else {
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une remise"),
                QObject::tr("Erreur 2 !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
ui->comboBox_3->setModel(r.combox());
ui->tabsupp->setModel(r.afficher());
}
void MainWindow::on_ajouter_clicked()
{
  int id = ui->id_2->text().toInt();
  QString Nom = ui->Nom->text();
  QString season = ui->comboBox_4->currentText();
  Evenement e(id,Nom,season);
  qDebug()<<"test";
  bool test=e.ajouter();
  if(test)
{ui->tabevent->setModel(e.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Evenement"),
                  QObject::tr("Evenement  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->comboide->setModel(r.combox8());


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                  QObject::tr("Erreur  1.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_Supprimer_clicked()
{
int id = ui->comboBox_5->currentText().toInt();
bool test=e.supprimer(id);
if(test)
{ui->tabevent->setModel(e.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                QObject::tr("Evenement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->comboBox_5->setModel(e.combox2());

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenment"),
                QObject::tr("Erreur 2 !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_Modifier_clicked(){
    bool verif_taux = true ; bool verif_ide = true;
    int id = ui->comboBox_2->currentText().toInt();
    float taux= ui->taux_l->text().toFloat();
    if (taux > 12){
           verif_taux = false;
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Erreur taux.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
    int ide = ui->ide_l->text().toInt();
    QString type = ui->type->currentText();
    if (ide <0 || ide > 20){
           verif_ide = false;
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Erreur ide.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
    Remise r(id, taux , ide , type);
    bool test = r.modifier();
    if(test){
        ui->tabetudiant->setModel(r.afficher());
        ui->tabmodd->setModel(r.afficher());

    }
}

/*void MainWindow::on_tri_clicked(){
    bool test = r.tri();
    if (test){
    ui->tabetudiant->setModel(r.tri());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri terminer"),
    QObject::tr("Tri terminer.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}*/
/*void MainWindow::on_tri2_clicked(){
    bool test = r.tri2();
    if (test){
    ui->tabetudiant->setModel(r.tri2());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri terminer"),
    QObject::tr("Tri terminer.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}*/
void MainWindow::on_recherche_clicked(){
    int id = ui->id_6->text().toInt();
    ui->rech->setModel(r.recherche(id));
}
void MainWindow::on_stat_clicked(){
    bool test = r.stat();
    if (test){
    ui->tabetudiant->setModel(r.stat());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Tri terminer"),
    QObject::tr("Tri terminer.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_rechtaux_clicked(){
    int id = ui->id_6->text().toInt();
    ui->rech->setModel(r.recherche(id));
}

void MainWindow::on_rechide_clicked(){
    int ide = ui->id_6->text().toInt();
    ui->rech->setModel(r.recherche(ide));
}

void MainWindow::on_Oof_textChanged(const QString &arg1)
{
    int id = arg1.toInt();
    ui->tabetudiant->setModel(r.recherche(id));

}

void MainWindow::on_Stat_currentChanged(int index)
{
    if(index==2)
    {
        delete mainLayout;
        mainLayout=new QVBoxLayout ;
        mainLayout->addWidget(s.Preparechart());
        ui->stat2->setLayout(mainLayout);

    }
}

void MainWindow::on_xz_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Id")
           ui->tabetudiant->setModel(r.tri_id());
       else if(arg1 == "Taux")
                ui->tabetudiant->setModel(r.tri_taux());
       else if (arg1 == "Ide")
                ui->tabetudiant->setModel(r.tri_ide());
}
void MainWindow::on_xy_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Id")
           ui->tabetudiant->setModel(e.tri_id());
       else if(arg1 == "Nom")
                ui->tabetudiant->setModel(e.tri_nom());
}

void MainWindow::on_Modif2_clicked(){
    bool verif_ideve = true ; bool verif_nom = true ;
    int id= ui->Comboxid->currentText().toInt();

    QString Nom= ui->nom->text();
    if (Nom ==""){
           verif_nom = false;
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                       QObject::tr("Erreur taux.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
    QString season= ui->comsea->currentText();
    Evenement e (id,Nom,season);
    bool test = e.modifier();
    if(test){
        ui->tabevent->setModel(e.afficher());
    }
}



void MainWindow::on_pushButton_clicked()
{
    QPrinter printer;
    QPainter painter;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->imp->render(&printer);
}


/*void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery q;
    q.exec="Alter table remise add season varchar2(20)";
}*/
