#include "stateven.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

Stateven::Stateven()
{

}
QChartView * Stateven::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;
       int count4=0;
       QFont font;

       if(query.exec("select season from evenement "))
       {
       while(query.next())
         {
            if(query.value(0).toString()=="Hiver")
                count1++;
            else if(query.value(0).toString()=="Etee")
                count2++;
            else if(query.value(0).toString()=="Autumn")
                count3++;
            else if(query.value(0).toString()=="Printemps")
                count4++;
          }
        }
         QPieSeries *series;
       series = new QPieSeries();
       series->append("Hiver", count1);
       series->append("Etee", count2);
       series->append("Autumn", count3);
       series->append("Printemps", count4);
       QPieSlice * slice1=series->slices().at(0);
       slice1->setExploded();
       slice1->setPen(QPen(Qt::black, 2));
       slice1->setBrush(Qt::darkRed);
       slice1->setLabelVisible();
       QPieSlice * slice2=series->slices().at(1);
       slice2->setLabelVisible();
       QPieSlice * slice3=series->slices().at(2);
       slice3->setLabelVisible();
       chart = new QChart();
       chart->setAnimationOptions(QChart::AllAnimations);
       chart->addSeries(series);
       chart->setTitle("Les Types");
       chart->legend()->hide();
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);


       return chartView;


}
