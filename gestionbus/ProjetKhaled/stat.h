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

/*
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
#endif // STAT_H
