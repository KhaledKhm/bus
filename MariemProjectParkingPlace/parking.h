#ifndef PARKING_H
#define PARKING_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class parking{
    public:
        parking();
        parking(int, int, int);
        int getId();
        int getCapacite();
        int getEtat();
        bool ajouter();
        bool supprimer(int);
        bool modifier(parking);
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficherTriId();
        QSqlQueryModel * afficherTriCap();
        QSqlQueryModel * afficherTriEt();
        QSqlQueryModel * afficherRechId(int);
        QSqlQueryModel * afficherRechCap(int);
        QSqlQueryModel * afficherRechEt(int);
    private:
        int idParking, capaciteParking, etatParking;
};

#endif // PARKING_H
