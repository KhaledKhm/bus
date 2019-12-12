#ifndef PLACE_H
#define PLACE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class place{
    public:
        place();
        place(int, int, int);
        int getId();
        int getEtat();
        int getIdParking();
        bool ajouter();
        bool supprimer(int);
        bool modifier(place, int);
        QSqlQueryModel * afficher(QString, QString, QString);
        int currentLanguage;
    private:
        int idPlace, etatPlace, idParking;
};

#endif // PLACE_HZ
