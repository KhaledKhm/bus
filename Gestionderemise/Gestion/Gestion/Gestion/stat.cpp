#include "stat.h"
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

Stat::Stat()
{

}
QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;
       QFont font;

       if(query.exec("select type from remise "))
       {
       while(query.next())
         {
            if(query.value(0).toString()=="remisemoyenne")
                count1++;
            else if(query.value(0).toString()=="liquidation")
                count2++;
            else
                count3++;
          }
        }
         QPieSeries *series;
       series = new QPieSeries();
       series->append("remisemoyenne", count1);
       series->append("liquidation", count2);
       series->append("remisefaible", count3);
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
