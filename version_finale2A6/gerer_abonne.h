#ifndef GERER_ABONNE_H
#define GERER_ABONNE_H

#include <QDialog>
#include "abonnement_el.h"
#include "abonnement_normal.h"
#include "conv.h"
#include "statistique.h"
QT_BEGIN_NAMESPACE
namespace Ui {
QT_END_NAMESPACE
class gerer_abonne;
}

class gerer_abonne : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_abonne(QWidget *parent = nullptr);
    ~gerer_abonne();

private slots:
    void on_ajouterAbonne_clicked();

    void on_radioButton_Ab_clicked();

    void on_radioButton_el_clicked();

    void on_afficher_Ab_clicked();

    void on_afficher_EL_clicked();

    void on_Retour_ab_clicked();

    void on_modifierAbonne_clicked();

    void on_supprimerAbonne_clicked();

    void on_comboTri_Ab_currentTextChanged(const QString &arg1);

    void on_comboTri_EL_currentTextChanged(const QString &arg1);

    void on_Recherche_Cin_textChanged(const QString &arg1);

    void on_Resaisir_clicked();
//////////////////////////////////////////////////////////////////////////////////////////

    void on_ajouter_Conv_clicked();

    void on_afficherConv_clicked();

    void on_retour_conv_clicked();

    void on_resaisir_Conv_clicked();

    void on_supprimer_conv_clicked();

    void on_modifier_conv_clicked();

    void on_recherche_id_2_textChanged(const QString &arg1);

    void on_comboTri_conv_currentTextChanged(const QString &arg1);

    void on_Imprimer_2_clicked();

    void on_statistique_ab_clicked();

private:
    Ui::gerer_abonne *ui;
    Abonnement_Normal tmpabonne;
    Abonnement_EL tmpeleve;
     conv tmpconvention;
     statistique *stat;

};

#endif // GERER_ABONNE_H
