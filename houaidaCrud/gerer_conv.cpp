#include "gerer_conv.h"
#include "ui_gerer_conv.h"
#include "conv.h"
#include <QMessageBox>
#include<QString>
#include<QDebug>
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include "QImage"
gerer_conv::gerer_conv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_conv)
{
    ui->setupUi(this);
}

gerer_conv::~gerer_conv()
{
    delete ui;
}

void gerer_conv::on_ajouter_clicked()
{
    int id=ui->lineEdit_idConv->text().toInt();
    QString nomEntreprise=ui->lineEdit_nomEntreprise->text();
     QString dateFin=ui->dateEdit_conv->text();
   //condition de saisie sur id nom et date
      if( id<100000||id>999999 || id==0 ){

             { if(id==0 )
                     ui->lineEdit_idConv->setText("   *champ obligatoire");
                 else{
                     ui->lineEdit_idConv->setText("   cin non valide");


                     QMessageBox::critical(nullptr, QObject::tr("Ajouter une convention"),
                                 QObject::tr("Erreur d'ajout !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                 }
             }
      }
             else
             {    conv co (id,nomEntreprise,dateFin);

                  bool test=co.ajouter_convention();
                  if(test)
                  {
                      ui->message->setText(" convention  ajoutée");
                      QMessageBox::information(nullptr, QObject::tr("Ajouter une convention"),
                                        QObject::tr("convention ajoutée.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                  }
                  else
                  {
                      ui->message->setText("Erreur : convention non  ajoutée");
                             QMessageBox::critical(nullptr, QObject::tr("Ajouter une convention"),
                                         QObject::tr("Erreur d'ajout !.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                  }

             }
}

void gerer_conv::on_resaisir_clicked()
{
    ui->lineEdit_idConv->clear();
    ui->lineEdit_nomEntreprise->clear();
    ui->dateEdit_conv->clear();
}

void gerer_conv::on_retour_clicked()
{
     hide();
}

void gerer_conv::on_afficherConv_clicked()
{
    conv *con=new conv();
    ui->tableView->setModel(con->afficher());
}

void gerer_conv::on_supprimer_clicked()
{
    int id=ui->recherche_id->text().toInt();
     bool var=tmpconvention.rechercher(id);
    if(var)
     {
         bool test=tmpconvention.supprimer_conv(id);
          if(test)
          {
              ui->tableView->setModel(tmpconvention.afficher());//refresh
               QMessageBox::information(nullptr, QObject::tr("Supprimer une convention"),
                     QObject::tr("convention supprimée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

          }
        else{
         QMessageBox::critical(nullptr, QObject::tr("Supprimer une convention"),
                     QObject::tr("Erreur de suppression  !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer une convention"),
                     QObject::tr("Erreur ! id not found.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void gerer_conv::on_retour_affiche_clicked()
{
    hide();
}

void gerer_conv::on_rechercher_clicked()
{
    int id = ui->recherche_id->text().toInt();
    bool test=tmpconvention.rechercher(id);
    if(test==(true))
    {

    ui->tableView->setModel(tmpconvention.chercher(id));
    QMessageBox::information(nullptr, QObject::tr("chercher une convention"),
                      QObject::tr("convention existe.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher une conventione"),
                          QObject::tr("convention n'existe pas.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void gerer_conv::on_trier_id_clicked()
{
    bool test = tmpconvention.tri_id();
           if (test){
           ui->tableView->setModel(tmpconvention.tri_id());}//refresh
}

void gerer_conv::on_trier_nom_clicked()
{
    bool test = tmpconvention.tri_nom();
           if (test){
           ui->tableView->setModel(tmpconvention.tri_nom());}//refresh
}

void gerer_conv::on_pushButton_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/lenovo/Desktop/houaidaCrud/pdf2");
    //printer.setOutputFileName("C:/Users/OneEffect007/Desktop/pdf1");
    QPainter painter;
    painter.begin(&printer);

    QFont font;
    font.setPixelSize(35);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(20,300,"id: ");
    painter.drawText(20,500,"Date:");
    painter.drawText(20,650,"nom:");
    int id=ui->lineEdit_idConv->text().toInt();
    QString id_pdf=QString::number(id);
    QString date_pdf=ui->dateEdit_conv->text();
    QString nom_pdf=ui->lineEdit_nomEntreprise->text();
    font.setPixelSize(15);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(20,350,id_pdf);
    painter.drawText(20,550,date_pdf);
    painter.drawText(20,700,nom_pdf);


    QImage image("C:/Users/lenovo/Desktop/houaidaCrud");
    painter.drawImage(100,50,image);

    painter.end();

    qDebug()<<"le pdf a ete cree";
    QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}

void gerer_conv::on_resaisir_2_clicked()
{
    int id = ui->lineEdit_idConv->text().toInt();
    QString nomEntreprise= ui->lineEdit_nomEntreprise->text();
    QString dateFin= ui->dateEdit_conv->text();


  conv c(id,nomEntreprise,dateFin);
  bool test=c.update();

  if(test)
{


QMessageBox::information(nullptr, QObject::tr("modifier une convention"),
                  QObject::tr("convention modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier une convention "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
