#ifndef STATEVEN_H
#define STATEVEN_H
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class Stateven
{
    QChart *chart;
    QChartView *chartView;
public:
    Stateven();
    QChartView * Preparechart();

};
#endif // STATEVEN_H
