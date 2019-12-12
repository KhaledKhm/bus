#ifndef GERER_PARKING_H
#define GERER_PARKING_H
#include "place.h"
#include "parking.h"
#include <QSystemTrayIcon>
#include <QDialog>

namespace Ui {
class gerer_parking;
}

class QSystemTrayIcon;

class gerer_parking : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_parking(QWidget *parent = nullptr);
    ~gerer_parking();
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
    void on_statCombo_currentIndexChanged(int index);
    void statistique1();
    void statistique2();
    bool isNaN(QString);
    void on_langueCombo_currentIndexChanged();

private:
    Ui::gerer_parking *ui;
    parking tmpParking;
    place tmpPlace;
    QSystemTrayIcon *mSystemTrayIcon;
    int currentLanguage;
};

#endif // GERER_PARKING_H
