#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"agent.h"
#include"service.h"
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
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
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_AjoutA_clicked();

    void on_ModifA_clicked();

    void on_Actualiser_clicked();

    void on_SuppA_clicked();

    void on_trier_clicked();

    void on_Rechercher_clicked();

    void on_imprimer_clicked();

private:
    Ui::MainWindow *ui;
   QGraphicsScene *scene;
   QTimer *timer ;
};

#endif // MAINWINDOW_H
