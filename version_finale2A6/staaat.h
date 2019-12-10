#ifndef STAAAT_H
#define STAAAT_H
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE

class staaat
{
    QChart *chart;
    QChartView *chartView;
public:
    staaat();
    QChartView * Preparechart();
};

#endif // STAAAT_H
