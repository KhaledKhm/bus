#ifndef GERER_EVENEMENT_H
#define GERER_EVENEMENT_H
#include "rem.h"
#include "even.h"
#include <QMainWindow>
#include<QDebug>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
#include <QVBoxLayout>
#include <QDialog>
#include "stat2.h"
#include "stateven.h"
namespace Ui {
class gerer_evenement;
}

class gerer_evenement : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_evenement(QWidget *parent = nullptr);
    ~gerer_evenement();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    //void on_tri_clicked();

    //void on_tri2_clicked();
    void on_xz_currentTextChanged(const QString &arg1);

    void on_Modif2_clicked();

    void on_xy_currentTextChanged(const QString &arg1);

    void on_stat_currentchanged(int index);

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_Actualiser3_clicked();

    void on_combrech_currentIndexChanged(const QString &arg1);

    void on_rech_currentIndexChanged(const QString &arg1);


    void on_stat2_currentchanged(int index);


private:
    Ui::gerer_evenement *ui;
    rem r ;
    QVBoxLayout * mainLayout;
        Stat2 s;
        Stateven s2;
    even e;
};

#endif // GERER_EVENEMENT_H
