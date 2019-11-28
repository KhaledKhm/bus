#include "stat.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtCharts/QPieSlice>


QT_CHARTS_USE_NAMESPACE

Stat::Stat()
{

}
QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;

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
       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Les Types");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;


}
