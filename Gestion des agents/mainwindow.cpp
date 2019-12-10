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
    //service *serv=new service();
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
     ui->cbModifCINAgent->setModel(a.comboidAgent());
     ui->cbSuppCINAgent->setModel(a.comboidAgent());
    a.AfficherTableAgent(ui);

}

void MainWindow::on_SuppA_clicked()
{
    QString cin=ui->cbSuppCINAgent->currentText();
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
    QString valeur=ui->LERECHERCHER->text();
    agent *ag=new agent();
    ui->tableView->setModel(ag->rechercheragent(valeur));

}

void MainWindow::on_imprimer_clicked()
{
    QString nom,prenom,date_naiss,salaire,sexe,id;
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/OMEN/Desktop/ProjetSaif/pdf.pdf");
    QPainter painter;
    painter.begin(&printer);
    QFont font;
    QString cin=ui->lineEdit_cin_pdf->text();
    QSqlQuery query;
    query.prepare("select * from agent where CIN ="+cin);
    if (query.exec())
    {
        while (query.next())
        {
             nom=query.value(1).toString();
             prenom=query.value(2).toString();
             date_naiss=query.value(3).toString();
             salaire=query.value(4).toString();
             sexe=query.value(5).toString();
             id=query.value(6).toString();
        }
    }
    qDebug()<<nom;
    font.setPixelSize(35);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(20,300,"nom :");
    painter.drawText(20,400,"prenom :");
    painter.drawText(20,500,"date de naissance :");
    painter.drawText(20,600,"salaire :");
    painter.drawText(20,700,"sexe :");
    painter.drawText(20,800,"identifiant :");
    font.setPixelSize(22);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(250,300,nom);
    painter.drawText(250,400,prenom);
    painter.drawText(350,500,date_naiss);
    painter.drawText(250,600,salaire);
    painter.drawText(250,700,sexe);
    painter.drawText(250,800,id);
    painter.end();

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
                //series->append(set3);


                QChart *chart= new QChart();
                chart->addSeries(series);
                chart->setTitle("Statistiques des emplacements dans le parking");

                chart->setAnimationOptions(QChart::AllAnimations);
                QStringList categories;
                categories <<"service";
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

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.prepare("insert into stat values(14,20,18)");
    query.exec();
}

void MainWindow::on_ajou_clicked()
{

    service s ;
    s.ajouterService(ui);
    s.AfficherTableService(ui);
}

void MainWindow::on_Actu_clicked()
{
  service s ;
    s.AfficherTableService(ui);
    ui->cbModifServ->setModel(s.comboidService());
    ui->cbSuppServ->setModel(s.comboidService());
}

void MainWindow::on_sup_clicked()
{
    QString id=ui->cbSuppServ->currentText();
    service s ;
    bool test=s.supprimerService(id);
      if (test)
        s.AfficherTableService(ui);

}

void MainWindow::on_modif_clicked()
{
    service s ;
    s.modifierService(ui);
    s.AfficherTableService(ui);

}
