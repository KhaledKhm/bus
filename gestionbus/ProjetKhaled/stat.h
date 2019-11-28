#ifndef STAT_H
#define STAT_H

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QtCharts/QChartView>

#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class Stat
{
    QChart *chart;
    QChartView *chartView;
public:
    Stat();
    QChartView *Preparechart();

};


#endif // STAT_H
