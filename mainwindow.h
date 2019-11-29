#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "station.h"
#include "trajet.h"
#include "stat.h"
#include<QVBoxLayout>
#include <QMainWindow>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    private slots:
        void on_ajouterStation_clicked();
        void on_supprimerStation_clicked();
        void on_modifierStation_clicked();
        void on_ajouterTrajet_clicked();
        void on_supprimerTrajet_clicked();
        void on_modifierTrajet_clicked();
        void on_lineEdit_textChanged(const QString &arg1);

        void on_lineEdit_2_textChanged(const QString &arg1);

        void on_listertrier_2_currentIndexChanged(int index);

        void on_listertrier_currentIndexChanged(int index);

        void on_pushButton_clicked();

        void on_comboBox_stat_type_currentTextChanged();

        void on_comboBox_stat_par_currentTextChanged();

private:
        Ui::MainWindow *ui;
        station tmpStation;
        trajet tmpTrajet;
        QVBoxLayout* mainLayout;
            Stat s;
};

#endif // MAINWINDOW_H
