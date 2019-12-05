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

int append_digits(int i1,int i2){
    int i2_copy=i2;
    while(i2_copy){
        i1*=10;
        i2_copy/=10;
    }
    return i1+i2;
}
Stat::Stat()
{}
QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;

       if(query.exec("Select quantite from materiel"))
       {
       while(query.next())
         {
            if(query.value(2).toInt()>-1 || query.value(2).toInt()<11)
                count1++;
            else if(query.value(2).toInt()>11 || query.value(2).toInt()<50)
                count2++;
            else if(query.value(2).toInt()>49)
                count3++;
          }
        }
         QPieSeries *series;
       series = new QPieSeries();

       series->append("Entre 1 et 10", count1);
       series->append("Entre 10 et 50", count2);
       series->append("50+", count3);
       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques de quantite des materiels");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;


}
