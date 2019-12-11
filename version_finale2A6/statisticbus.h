
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
class statisticBus;
}

class statisticBus : public QDialog
{
    Q_OBJECT

public:
    explicit statisticBus(QWidget *parent = nullptr);
    ~statisticBus();
    int StatistiqueBus_partie1() ;
    int StatistiqueBus_partie2() ;
    void paintEvent(QPaintEvent *) ;
private slots:
    void on_retour_clicked();

private:
    Ui::statisticBus *ui;
};
