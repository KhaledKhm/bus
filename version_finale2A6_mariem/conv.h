#ifndef CONV_H
#define CONV_H

#include <QSqlQueryModel>
#include <QString>
#include <QTableView>

class conv
{
public:
    conv();
    conv(int,QString,QString);
    ~conv(){}
    QString get_nomEntreprise(){return  nomEntreprise ;}
    QString get_dateFin(){return  dateFin ;}
    int get_idConvention(){return id ;}
    void set_nomEntreprise(QString nomEntreprise){this->nomEntreprise=nomEntreprise ;}
    void set_dateFin(QString dateFin){this->dateFin=dateFin ;}
    void set_id(int id){this->id=id ;}
    bool ajouter_convention();
    QSqlQueryModel *afficher();
    bool supprimer_conv(int);
    bool rechercher(int);
    QSqlQueryModel *chercher(int);
    QSqlQueryModel * tri_id();
    QSqlQueryModel * tri_nom();
   //bool update();
    bool modifier();
    QSqlQueryModel * combox();
    void recherche_id_place(QTableView *, int);


private:
    int id;
    QString nomEntreprise,dateFin;
};

#endif // CONV_H
