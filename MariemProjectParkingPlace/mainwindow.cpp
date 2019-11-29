#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "parking.h"
#include "place.h"
#include <QDebug>
#include "mailing/SmtpMime"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabParking->setModel(tmpParking.afficher());
    ui->tabPlace->setModel(tmpPlace.afficher());
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ajouterParking_clicked(){
    bool control = true;
    int idParking = ui->idParking->text().toInt();
    if(idParking < 0 || idParking > 99999){
        control = false;
    }
    int capaciteParking = ui->capaciteParking->text().toInt();
    if(capaciteParking < 0 || capaciteParking > 99999){
        control = false;
    }
    int etatParking = ui->etatParking->text().toInt();
    if(etatParking != 0 && etatParking != 1){
        control = false;
    }
    if(control){
        parking pa(idParking, capaciteParking, etatParking);
        bool test = pa.ajouter();
        if(test){
            ui->tabParking->setModel(tmpParking.afficher());
            qDebug() <<"Parking ajoute";
        }else{
           qDebug() <<"Erreur d'ajout de parking";
        }
     }else{
        qDebug() << "Erreur de controle de saisie";
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Control de saisie\n"
                                ""), QMessageBox::Cancel);
    }
}

void MainWindow::on_ajouterPlace_clicked(){
    int control= true;
    int idPlace = ui->idPlace->text().toInt();
    if (idPlace <0 || idPlace > 99999){
        control = false;
    }
    int etatPlace = ui->etatPlace->text().toInt();
    if (etatPlace !=0 && etatPlace !=1){
        control = false;
    }
    int idParking = ui->idparkingPlace->text().toInt();
    if (idParking < 0 || idParking > 99999){
        control = false;
    }
    if(control){
         place pl(idPlace, etatPlace, idParking);
        bool test = pl.ajouter();
        if(test){
        ui->tabPlace->setModel(tmpPlace.afficher());
           qDebug() <<"Place ajoute";
        }else{
           qDebug() <<"Erreur d'ajout de place";
        }
    }else{
        qDebug() << "Erreur de controle de saisie";
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Control de saisie\n"
                                ""), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimerParking_clicked(){
    bool control = true;
    int idParkingSuppr = ui->idParkingSuppr->text().toInt();
    if (idParkingSuppr <0 || idParkingSuppr > 99999){
        control = false;}
    if(control){
        bool test = tmpParking.supprimer(idParkingSuppr);
        if(test){
            ui->tabParking->setModel(tmpParking.afficher());
        }
    }else{
        qDebug() << "Erreur de controle de saisie";
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Control de saisie\n"
                                ""), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimerPlace_clicked(){
    bool control = true;
    int idPlaceSuppr = ui->idPlaceSuppr->text().toInt();
    if (idPlaceSuppr <0 || idPlaceSuppr > 99999){
        control = false;}
    if(control){
    bool test = tmpPlace.supprimer(idPlaceSuppr);
    if(test){
        ui->tabPlace->setModel(tmpPlace.afficher());
    }
}else{
qDebug() << "Erreur de controle de saisie";
QMessageBox::critical(nullptr, QObject::tr("Erreur"),
            QObject::tr("Control de saisie\n"
                        ""), QMessageBox::Cancel);
}
}

void MainWindow::on_modifierParking_clicked(){
    bool control=true;
    int idParking = ui->idParkingModif->text().toInt();
    if (idParking <0 || idParking > 99999){
        control = false;}
    int capaciteParking = ui->capaciteParkingModif->text().toInt();
    if (capaciteParking <0 || capaciteParking > 99999){
        control = false;}
    int etatParking = ui->etatParkingModif->text().toInt();
    if (etatParking != 0 && etatParking != 1){
        control = false;
    }
    parking pa(idParking, capaciteParking, etatParking);
    if(control){
    bool test = tmpParking.modifier(pa);
    if(test){
        ui->tabParking->setModel(tmpParking.afficher());
    }
    }else{
        qDebug() << "Erreur de controle de saisie";
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Control de saisie\n"
                                ""), QMessageBox::Cancel);
}
}

void MainWindow::on_modifierPlace_clicked(){
    bool control = true;
    int idPlace = ui->idPlaceModif->text().toInt();
    if (idPlace <0 || idPlace > 99999){
        control = false;}
    int etatPlace = ui->etatPlaceModif->text().toInt();
    if (etatPlace != 0 && etatPlace !=1 ){
        control = false;}
    int idparkingPlace = ui->idparkingPlaceModif->text().toInt();
    if (idparkingPlace < 0 || idparkingPlace > 99999){
        control = false;
    }
    place pl(idPlace, etatPlace, idparkingPlace);
    if (control){
    bool test = tmpPlace.modifier(pl);
    if(test){
        ui->tabPlace->setModel(tmpPlace.afficher());
     }
   }else{
        qDebug() << "Erreur de controle de saisie";
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Control de saisie\n"
                                ""), QMessageBox::Cancel);
    }
}

void MainWindow::on_identifianttri_clicked(){
    ui->tabParking->setModel(tmpParking.afficherTriId());
}

void MainWindow::on_capacitetri_clicked(){
    ui->tabParking->setModel(tmpParking.afficherTriCap());
}

void MainWindow::on_etattri_clicked(){
    ui->tabParking->setModel(tmpParking.afficherTriEt());
}


void MainWindow::on_rechId_clicked(){
    bool control = true;
    int id = ui->idr->text().toInt();
    if (id <0 || id > 99999){
        control = false;}
    if (control){
        ui->tabParking->setModel(tmpParking.afficherRechId(id));
    }
}

void MainWindow::on_rechCap_clicked(){
    bool control = true;
    int cap = ui->capr->text().toInt();
    if (cap <0 || cap > 99999){
        control = false;}
    if (control){
    ui->tabParking->setModel(tmpParking.afficherRechCap(cap));
    }
}

void MainWindow::on_rechEt_clicked(){
    bool control = true;
    int rech = ui->etatr->text().toInt();
    if (rech !=0 && rech !=1 ){
        control = false;}
    if (control){
    ui->tabParking->setModel(tmpParking.afficherRechEt(rech));
    }
}
void MainWindow::on_identifianttripl_clicked(){
    ui->tabPlace->setModel(tmpPlace.afficherTriId());
}

void MainWindow::on_etattripl_clicked(){
    ui->tabPlace->setModel(tmpPlace.afficherTriEt());
}

void MainWindow::on_rechIdpl_clicked(){
    int id = ui->idrpl->text().toInt();
    ui->tabPlace->setModel(tmpPlace.afficherRechId(id));
}

void MainWindow::on_rechEtpl_clicked(){
    int rech = ui->etatrpl->text().toInt();
    ui->tabPlace->setModel(tmpPlace.afficherRechEt(rech));
}

void MainWindow::on_rechIdparkingpl_clicked(){
    bool control = true;
    int rech = ui->idparkingrpl->text().toInt();
    if (rech != 0 && rech !=1){
        control = false;}
    if (control){
        ui->tabParking->setModel(tmpPlace.afficherIdParkingEt(rech));
    }
}

void MainWindow::on_idparkingtri_clicked(){
    ui->tabPlace->setModel(tmpPlace.afficherTriIdParking());
}

void MainWindow::on_envoyer_clicked(){
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("mariem.ayadi@esprit.tn");
    smtp.setPassword("marioumaayadi27..");
    MimeMessage message;
    message.setSender(new EmailAddress("mariem.ayadi@esprit.tn", "Capteur Parking (id)"));
    message.addRecipient(new EmailAddress("habib.majoul@esprit.tn", "Administrateur"));
    message.setSubject("BUS EN PLACE");
    MimeText text;
    text.setText("Bus (ID) - Parking (ID) - Place (NUMERO)\n");
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    if(smtp.sendMail(message)){
        QMessageBox::information(this, "OK", "Mail envoye correctement");
    }else{
        QMessageBox::critical(this, "Erreur", "Mail non envoye");
    }
    smtp.quit();
}

void MainWindow::on_tabWidget_2_currentChanged(int index){
    if(index == 2){
        QSqlQuery query, queryCount, queryTotal;
        QBarSet* tab[50];
        QBarSeries * series = new QBarSeries();
        QChart * chart;
        QStringList categories;
        queryTotal.prepare("SELECT COUNT(*) FROM place WHERE etat = 0"); //Trouver le nombre de places totals occupées
        queryTotal.exec(); // executer
        while(queryTotal.next()){ //parcourir les resultats de la requete
            query.prepare("SELECT id FROM parking"); //recevoir tout les id des parking
            query.exec(); //executer
            int numParking = 0, nb;
            while(query.next()){ //parcourir les resultats (les id 1 par 1)
                queryCount.prepare("SELECT COUNT(*) FROM place WHERE idparking = :id AND etat = 0"); //calculer le nombre de places occupées dans le parking courant
                queryCount.bindValue(":id", query.value(0).toString()); //associer la valeur au parametre
                queryCount.exec();
                while(queryCount.next()){
                    tab[numParking] = new QBarSet(query.value(0).toString());
                    nb = queryCount.value(0).toInt() * 100 / queryTotal.value(0).toInt(); //calcul de pourcentage
                    *tab[numParking] << nb;
                    series->append(tab[numParking]);
                    numParking++;
                }
            }
            chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Statistique Parking les plus occupés");

            chart->setAnimationOptions(QChart::AllAnimations);
            categories << "Nombre de bus Total: " + queryTotal.value(0).toString();
        }
        QBarCategoryAxis *axis=new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartview =new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QPalette pal=qApp->palette();
        pal.setColor(QPalette::Window,QRgb(0xffffff));
        pal.setColor(QPalette::WindowText,QRgb(0x121212));
        qApp->setPalette(pal);
        ui->statBox->setChart(chart);
    }
}
