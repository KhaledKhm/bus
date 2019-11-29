#ifndef STAT_H
#define STAT_H
#include <QtCharts>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSeries>
#include <QSqlQuery>
#include <QString>
QT_CHARTS_USE_NAMESPACE
class Stat
{
    QChart *chart;
    QChartView *chartView;
public:
    Stat();
    QChartView * Preparechart(QString,QString);

};

#endif // STAT_H
