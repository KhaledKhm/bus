#ifndef STATISTIQUE_H
#define STATISTIQUE_H

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

class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
    int Statistique_partie1() ;
    int Statistique_partie2() ;
    void paintEvent(QPaintEvent *) ;

private slots:
    void on_Retour_stat_clicked();

private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H
