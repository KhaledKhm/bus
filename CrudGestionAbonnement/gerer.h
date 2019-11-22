#ifndef GERER_H
#define GERER_H
#include "abonne.h"
#include "eleve.h"
#include <QDialog>

namespace Ui {
class gerer;
}

class gerer : public QDialog
{
    Q_OBJECT

public:
    explicit gerer(QWidget *parent = nullptr);
    ~gerer();

private slots:
    void on_ajouter_clicked();

    void on_resaisir_clicked();


    //void on_nom_returnPressed();

   //void on_cin_returnPressed();

   // void on_prenom_returnPressed();

   // void on_adresse_returnPressed();

    //void on_date_debut_returnPressed();

    //void on_age_returnPressed();

    //void on_date_fin_returnPressed();




    void on_retour_clicked();

    void on_afficherAb_clicked();
    void on_afficherEl_clicked();

    QString GetRandomString() const;

    void on_trierAb_clicked();

    void on_trierEl_clicked();

    void on_supprimer_clicked();

    void on_radioButtoneleve_clicked();

    void on_radioButtonabonne_clicked();

private:
    Ui::gerer *ui;
    abonne tmpabonne;
    eleve tmpeleve;
};

#endif // GERER_H
