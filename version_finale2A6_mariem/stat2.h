#ifndef STAT2_H
#define STAT2_H
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class Stat2
{
    QChart *chart;
    QChartView *chartView;
public:
    Stat2();
    QChartView * Preparechart();

};

#endif // STAT_H
