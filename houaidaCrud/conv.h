#ifndef CONV_H
#define CONV_H
#include <QSqlQueryModel>


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
bool update();

private:
    int id;
    QString nomEntreprise,dateFin;


};

#endif // CONV_H
