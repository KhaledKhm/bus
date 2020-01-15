#ifndef ARDUINO_TEMP_H
#define ARDUINO_TEMP_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QDialog>
#include"captemperature.h"
namespace Ui {
class Arduino_Temp;
}

class Arduino_Temp : public QDialog
{
    Q_OBJECT

public:
    explicit Arduino_Temp(QWidget *parent = nullptr);
    ~Arduino_Temp();

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Arduino_Temp *ui;
    QByteArray data; // variable contenant les données reçues

    capTemperature A; // objet temporaire
};

#endif // ARDUINO_TEMP_H
