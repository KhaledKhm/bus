#ifndef STATISTIC_H
#define STATISTIC_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
using namespace std;
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class statistic;
}

class statistic : public QDialog
{
    Q_OBJECT

public:
    explicit statistic(QWidget *parent = nullptr);
    ~statistic();
    int Statistique_partie1() ;
    int Statistique_partie2() ;
    void paintEvent(QPaintEvent *) ;
private slots:
    void on_retour_clicked();

private:
    Ui::statistic *ui;
};


/*
using namespace std;
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class statistic;
}

class statistic : public QDialog
{
    Q_OBJECT

public:
    explicit statistic(QWidget *parent = nullptr);
    int Statistique_partie1() ;
    int Statistique_partie2() ;
    void paintEvent(QPaintEvent *) ;
    ~statistic();

private slots:
    void on_retour_clicked();

private:
    Ui::statistic *ui;
};
*/

#endif // STATISTIC_H
