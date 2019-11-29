#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "place.h"
#include "parking.h"
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
        void on_ajouterPlace_clicked();
        void on_supprimerPlace_clicked();
        void on_modifierPlace_clicked();
        void on_ajouterParking_clicked();
        void on_supprimerParking_clicked();
        void on_modifierParking_clicked();
        void on_identifianttri_clicked();
        void on_capacitetri_clicked();
        void on_etattri_clicked();
        void on_rechId_clicked();
        void on_rechCap_clicked();
        void on_rechEt_clicked();
        void on_identifianttripl_clicked();
        void on_etattripl_clicked();
        void on_rechIdpl_clicked();
        void on_rechEtpl_clicked();
        void on_envoyer_clicked();
        void on_idparkingtri_clicked();
        void on_rechIdparkingpl_clicked();
        void on_tabWidget_2_currentChanged(int index);

private:
        Ui::MainWindow *ui;
        parking tmpParking;
        place tmpPlace;
};

#endif // MAINWINDOW_H
