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
        void on_ajouterPl_clicked();
        void on_supprPl_clicked();
        void on_modifPl_clicked();

        void on_ajouterPar_clicked();
        void on_supprPar_clicked();
        void on_modifPar_clicked();

        void on_tabWidget_currentChanged(int index); //stat

        void on_triComboPar_currentIndexChanged();
        void on_rechComboPar_currentIndexChanged();
        void on_triComboPl_currentIndexChanged();
        void on_rechComboPl_currentIndexChanged();
        void on_rechTextPar_textEdited();
        void on_rechTextPl_textEdited();

        void on_envoyer_clicked();

        void on_rafraichirPar_clicked();
        void on_rafraichirPl_clicked();
        void rafraichir();

        void on_idModifComboPar_currentIndexChanged(int index);

        void on_idModifComboPl_currentIndexChanged(int index);
private:
        Ui::MainWindow *ui;
        parking tmpParking;
        place tmpPlace;
};

#endif // MAINWINDOW_H
