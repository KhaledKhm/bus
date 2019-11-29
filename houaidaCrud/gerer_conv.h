#ifndef GERER_CONV_H
#define GERER_CONV_H

#include <QDialog>
#include "conv.h"
namespace Ui {
class gerer_conv;
}

class gerer_conv : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_conv(QWidget *parent = nullptr);
    ~gerer_conv();

private slots:
    void on_ajouter_clicked();

    void on_resaisir_clicked();

    void on_retour_clicked();

    void on_afficherConv_clicked();

    void on_supprimer_clicked();

    void on_retour_affiche_clicked();

    void on_rechercher_clicked();

    void on_trier_id_clicked();

    void on_trier_nom_clicked();

    void on_pushButton_clicked();

    void on_resaisir_2_clicked();

private:
    Ui::gerer_conv *ui;
    conv tmpconvention;

};

#endif // GERER_CONV_H
