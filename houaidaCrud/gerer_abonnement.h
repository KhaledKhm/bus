#ifndef GERER_ABONNEMENT_H
#define GERER_ABONNEMENT_H

#include <QDialog>
#include "abonnement_eleve.h"
#include "abonnement_normal.h"
#include "statistic.h"
namespace Ui {
class gerer_abonnement;
}

class gerer_abonnement : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_abonnement(QWidget *parent = nullptr);
    ~gerer_abonnement();



private slots:
    void on_ajouter_clicked();

    void on_resaisir_clicked();

    void on_retour_clicked();

    void on_afficherAb_clicked();

    void on_afficherEl_clicked();

    void on_radioButtonabonne_clicked();

    void on_radioButtoneleve_clicked();

    void on_trierAb_age_clicked();

    void on_trierAb_nom_clicked();

    void on_trirEl_age_clicked();

    void on_trirEl_nom_clicked();

    void on_supprimer_clicked();

    void on_rechercher_clicked();

    void on_retour_2_clicked();

    void on_modifier_clicked();



    void on_commandLinkButton_2_clicked();

private:
    Ui::gerer_abonnement *ui;
    abonnement_normal tmpabonne;
    abonnement_eleve tmpeleve;
    statistic *stat;

};

#endif // GERER_ABONNEMENT_H
