#ifndef PROJETKHALED_H
#define PROJETKHALED_H

#include <QWidget>

#include <QMainWindow>
#include <QVBoxLayout>
#include "bus.h"
#include "fournisseur.h"
#include "materiel.h"
#include "statisticbus.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class ProjetKhaled;
}

class ProjetKhaled : public QDialog
{
    Q_OBJECT

public:
    explicit ProjetKhaled(QWidget *parent = nullptr);
    ~ProjetKhaled();

private slots:

    void on_ConfirmerAjoutBus_3_clicked();

    void on_ConfirmerModifBus2_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pbAjouterFournisseur_3_clicked();

    void on_pbModifierFournisseur_3_clicked();

    void on_pbSupprimerFournisseur_3_clicked();

    void on_pbMaterielAjout_3_clicked();

    void on_pbMaterielModif2_3_clicked();

    void on_pbMaterielSupprimer_3_clicked();

    void on_pbMaterielAfficher_3_clicked();

    void on_pbFournisseurAfficher_3_clicked();

    void on_pbBusAfficher_3_clicked();


    void on_pbMaterielRechercher_3_clicked();


    void on_pbBusRechercher_3_clicked();

    void on_pbFournisseurRechercher_3_clicked();



    //void on_pbMaterielTri1Alpha_3_clicked();

    void on_pbStat_3_clicked();



    void on_comboBox_3_currentTextChanged(const QString&arg1);



    void on_cbTriBus_3_currentTextChanged(const QString &arg1);

    void on_cbTriBus_5_currentTextChanged_(const QString &arg1);

    void on_cbTriBus_6_currentTextChanged_(const QString &arg1);

   void on_cbTriBus_6_currentTextChanged(const QString &arg1);

   void on_cbTriBus_5_currentTextChanged(const QString &arg1);

    void on_pbMaterielImprimer_3_clicked();


private:
    Ui::ProjetKhaled *ui;
    bus tmpBus;
        fournisseur tmpFournisseur;
        materiel tmpMateriel;

        QVBoxLayout * mainLayout;
           statisticBus s;

};

#endif // PROJETKHALED_H
