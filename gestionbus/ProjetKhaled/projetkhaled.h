#ifndef PROJETKHALED_H
#define PROJETKHALED_H

#include <QMainWindow>
#include "bus.h"
#include "fournisseur.h"
#include "materiel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProjetKhaled; }
QT_END_NAMESPACE

class ProjetKhaled : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjetKhaled(QWidget *parent = nullptr);
    ~ProjetKhaled();

private slots:
    void on_ConfirmerAjoutBus_clicked();

    void on_ConfirmerModifBus2_clicked();

    void on_pb_supprimer_clicked();

    void on_pbAjouterFournisseur_clicked();

    void on_pbModifierFournisseur_clicked();

    void on_pbSupprimerFournisseur_clicked();

    void on_pbMaterielAjout_clicked();

    void on_pbMaterielModif2_clicked();

    void on_pbMaterielSupprimer_clicked();

    void on_pbMaterielAfficher_clicked();

    void on_pbFournisseurAfficher_clicked();

    void on_pbBusAfficher_clicked();

private:
    Ui::ProjetKhaled *ui;
    bus tmpBus;
    fournisseur tmpFournisseur;
    materiel tmpMateriel;
};


#endif // PROJETKHALED_H
