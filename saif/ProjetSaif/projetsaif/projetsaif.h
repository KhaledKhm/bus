#ifndef PROJETSAIF_H
#define PROJETSAIF_H

#include <QMainWindow>
#include"service.h"
#include"agent.h"
QT_BEGIN_NAMESPACE
namespace Ui { class projetsaif; }
QT_END_NAMESPACE

class projetsaif : public QMainWindow
{
    Q_OBJECT

public:
    projetsaif(QWidget *parent = nullptr);
    ~projetsaif();

private slots:
    void on_pbAgentAjout_clicked();

    void on_pbAgentModif2_clicked();

    void on_pbAgentSupprimer_clicked();

    void on_pbServiceModif2_clicked();

    void on_pbServiceAjouter_clicked();

    void on_pbServiceSupprimer_clicked();

private:
    Ui::projetsaif *ui;
    service tmpService;
    agent tmpAgent;
};
#endif // PROJETSAIF_H
