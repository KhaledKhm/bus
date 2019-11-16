#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Remise.h"
#include "evenement.h"
#include <QMainWindow>
#include<QDebug>

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

    void on_tri_clicked();

    void on_stat_clicked();
    
    void on_recherche_clicked();

private:
    Ui::MainWindow *ui;
    Remise r ;
    Evenement e;


};

#endif // MAINWINDOW_H
