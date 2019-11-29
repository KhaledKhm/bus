#include "stat.h"
#include <QDebug>
#include <algorithm>
using namespace  std;
Stat::Stat()
{



}
QChartView * Stat::Preparechart(QString type,QString par)
{
    QSqlQuery query;
    int count1=0;
    int count2=0;
    int count3=0;
    int maxcount=0;

    if(par=="Localisation")
    { int count4=0;
      int count5=0;
      int count6=0;
      int count7=0;
      int count8=0;
      int count9=0;
    if(query.exec("select localisation from station"))
    {
    while(query.next())
      {
         if(query.value(0).toString()=="Bizerte")
             count1++;
         else if(query.value(0).toString()=="Tunis")
             count2++;
         else if(query.value(0).toString()=="Hamammet")
             count3++;
             else if(query.value(0).toString()=="Sousse")
                 count4++;
             else if(query.value(0).toString()=="Sfax")
                 count5++;
             else if(query.value(0).toString()=="Djerba")
                 count6++;
              else if(query.value(0).toString()=="Touzeur")
                     count7++;
                 else if(query.value(0).toString()=="Tabarka")
                     count8++;
                 else if(query.value(0).toString()=="Nabeul")
                     count9++;
       }
     }

    if(type=="PIE"){
      QPieSeries *series;
    series = new QPieSeries();

    series->append("Benzart", count1);
    series->append("Tunis", count2);
    series->append("Hamammet", count3);
    series->append("Sousse", count4);
    series->append("Sfax", count5);
    series->append("Jerba", count6);
    series->append("Touzeur", count7);
    series->append("Tabarka", count8);
    series->append("Nebeul", count9);
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Les Localisations");
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    }
    else if(type=="BARRE"){

        maxcount=max(count1,count2);
        maxcount=max(maxcount,count3);
        maxcount=max(maxcount,count4);
        maxcount=max(maxcount,count5);
        maxcount=max(maxcount,count6);
        maxcount=max(maxcount,count7);
        maxcount=max(maxcount,count8);
        maxcount=max(maxcount,count9);



             QBarSet *set0 = new QBarSet("Bizerte");
             QBarSet *set1 = new QBarSet("Tunis");
             QBarSet *set2 = new QBarSet("Hamammet");
             QBarSet *set3 = new QBarSet("Sousse");
             QBarSet *set4 = new QBarSet("Sfax");
             QBarSet *set5 = new QBarSet("Djerba");
             QBarSet *set6 = new QBarSet("Touzeur");
             QBarSet *set7 = new QBarSet("Tabarka");
             QBarSet *set8 = new QBarSet("Nabeul");


             *set0 << count1 ;
             *set1 << count2 ;
             *set2 << count3 ;
             *set3 << count4 ;
             *set4 << count5 ;
             *set5 << count6 ;
             *set6 << count7 ;
             *set7 << count8 ;
             *set8 << count9 ;


             QBarSeries *series = new QBarSeries();
                 series->append(set0);
                 series->append(set1);
                 series->append(set2);
                 series->append(set3);
                 series->append(set4);
                 series->append(set5);
                 series->append(set6);
                 series->append(set7);
                 series->append(set8);

                 chart = new QChart();
                 chart->addSeries(series);
                 chart->setTitle("STATISTIQUE");
                 chart->setAnimationOptions(QChart::SeriesAnimations);
                 QStringList categories;
                 categories << "Lieux" ;
                 QBarCategoryAxis *axisX = new QBarCategoryAxis();
                 axisX->append(categories);
                 chart->addAxis(axisX, Qt::AlignBottom);
                 series->attachAxis(axisX);
                 QValueAxis *axisY = new QValueAxis();
                 axisY->setRange(0,maxcount);
                 chart->addAxis(axisY, Qt::AlignLeft);
                 series->attachAxis(axisY);
                 chart->legend()->setVisible(true);
                 chart->legend()->setAlignment(Qt::AlignBottom);
                 chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
    }
    }


return chartView;
}
