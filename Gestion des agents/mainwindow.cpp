#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agent.h"
#include <QDebug>
#include <QMessageBox>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->showFullScreen() ;
    agent *ag= new agent();
    ui->tableView->setModel(ag->trieragent("nom"));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AjoutA_clicked()
{
    agent a ;
    a.ajouterAgent(ui);
    a.AfficherTableAgent(ui);
   }

void MainWindow::on_ModifA_clicked()
{
    agent a ;
    a.modifierAgent(ui);
    a.AfficherTableAgent(ui);
    agent *ag= new agent();
    ui->tableView->setModel(ag->trieragent("nom"));
}

void MainWindow::on_Actualiser_clicked()
{
    agent a ;
    a.AfficherTableAgent(ui);

}

void MainWindow::on_SuppA_clicked()
{
    QString cin=ui->CinSupp->text();
    agent a ;
    bool test=a.supprimerAgent(cin);
      if (test)
        a.AfficherTableAgent(ui);
}

void MainWindow::on_trier_clicked()
{
    QString col ;
        std::cout << "triii" << std::endl;
       QModelIndexList a = ui->tableView->selectionModel()->selectedColumns() ;
    for (int i =0 ;i<a.count();i++){
     col =  ui->tableView->selectionModel()->model()->headerData(a.at(i).column(),Qt::Horizontal).toString();
    qDebug() << col;
    }
         agent *e= new agent();
         ui->tableView->setModel(e->trieragent(col));

}

void MainWindow::on_Rechercher_clicked()
{
    QString valeur=ui->LECIN->text();
    agent *ag=new agent();
    ui->tableView->setModel(ag->rechercheragent(valeur));

}

void MainWindow::on_imprimer_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
                int a=0,b=0,c=0;
                QSqlQuery  query;
                query.prepare("select * from stat ");
                if (query.exec())
                {
                    while (query.next())
                    {

                a=query.value(0).toInt();
                b=query.value(1).toInt();
                c=query.value(2).toInt();
                }
                }

                QBarSet *set0=new QBarSet("chauffeur");
                QBarSet *set1=new QBarSet("administrateur");
                QBarSet *set2=new QBarSet("guichetier");

                *set0 <<a;
                *set1 <<b;
                *set2 <<c;

                QBarSeries *series =new QBarSeries();
                series->append(set0);
                series->append(set1);
                series->append(set2);
                series->append(set3);


                QChart *chart= new QChart();
                chart->addSeries(series);
                chart->setTitle("Statistiques des emplacements dans le parking");

                chart->setAnimationOptions(QChart::AllAnimations);
                QStringList categories;
                categories <<bloc;
                QBarCategoryAxis *axis=new QBarCategoryAxis();
                axis->append(categories);
                chart->createDefaultAxes();
                chart->setAxisX(axis,series);
                chart->legend()->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);

                QChartView *chartview =new QChartView(chart);
                chartview->setRenderHint(QPainter::Antialiasing);
                QPalette pal=qApp->palette();
                pal.setColor(QPalette::Window,QRgb(0xffffff));
                pal.setColor(QPalette::WindowText,QRgb(0x121212));
                qApp->setPalette(pal);

                ui->graphicsView->setChart(chart);
}
