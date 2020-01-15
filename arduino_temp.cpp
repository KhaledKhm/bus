#include "arduino_temp.h"
#include "ui_arduino_temp.h"

Arduino_Temp::Arduino_Temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arduino_Temp)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

Arduino_Temp::~Arduino_Temp()
{
    delete ui;
}
void Arduino_Temp::update_label()
{

    data=A.read_from_arduino();
//QString x=QString::fromStdString(data.toStdString());
        ui->labelmsg->setText(data);

 /* if(data=="1")
  {
      ui->labelmsg->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
  // alors afficher ON
  }

   /* else if (data=="0")
  {
      ui->label->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
   //alors afficher off
  }

  else if(data=="2")
  {
      ui->label->setText("AUTO");   // si les données reçues de arduino via la liaison série sont égales à 2
   //alors afficher auto
  }*/
}
void Arduino_Temp::on_pushButton_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino

}

void Arduino_Temp::on_pushButton_2_clicked()
{
    A.write_to_arduino("0"); //envoyer 0 à arduino

}

void Arduino_Temp::on_pushButton_3_clicked()
{
   /* data=A.read_from_arduino();
    int x=data.toInt();
    if(x>73)
    A.write_to_arduino("1"); //envoyer 1 à arduino
    else
     A.write_to_arduino("0"); //envoyer 0 à arduino*/
  //  mod auto
    A.write_to_arduino("2"); //envoyer 2 à arduino*/


}
