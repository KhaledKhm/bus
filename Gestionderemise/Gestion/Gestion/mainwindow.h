#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Remise.h"
#include "evenement.h"
#include <QMainWindow>
#include<QDebug>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
#include <QVBoxLayout>
#include "stat.h"

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    //void on_tri_clicked();

    //void on_tri2_clicked();

    void on_recherche_clicked();

    void on_rechtaux_clicked();

    void on_rechide_clicked();

    void on_stat_clicked();

    void on_Oof_textChanged(const QString &arg1);

    void on_Stat_currentChanged(int index);

    void on_xz_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Remise r ;
    Evenement e;
    QVBoxLayout * mainLayout;
        Stat s;


};

#endif // MAINWINDOW_H
