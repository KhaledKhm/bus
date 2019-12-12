#include "gerer_parking.h"
#include "ui_gerer_parking.h"
#include "QMessageBox"
#include "parking.h"
#include "place.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include "mailing/SmtpMime"
#include <QSystemTrayIcon>

gerer_parking::gerer_parking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_parking)
{
    ui->setupUi(this);
    on_rafraichirPl_clicked();
    rafraichir();
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    mSystemTrayIcon->setVisible(true);
    currentLanguage = 0;
    tmpParking.currentLanguage = currentLanguage;
    tmpPlace.currentLanguage = currentLanguage;
}

gerer_parking::~gerer_parking(){
    delete ui;
}

bool gerer_parking::isNaN(QString ch){
    QString ch2 = "0123456789";
    int i, j;
    bool test;
    for(i = 0; i < ch.length(); i++){
        test = false;
        for(j = 0; j < ch2.length(); j++){
            if(ch[i] == ch2[j]){
                test = true;
                break;
            }
        }
        if(test == false){
            return 1;
        }
    }
    return 0;
}

void gerer_parking::rafraichir(){
    QSqlQuery q;
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM parking");
    ui->idSupprComboPar->setModel(model);
    ui->idModifComboPar->setModel(model);
    q.prepare("SELECT * FROM parking WHERE id = :x");
    q.bindValue(":x", ui->idModifComboPar->currentText());
    if(q.exec()){
        while(q.next()){
            ui->idModifPar->setText(q.value(0).toString());
            ui->capaciteModifPar->setText(q.value(1).toString());
            ui->etatModifComboPar->setCurrentIndex(q.value(2).toInt());
        }
    }
    ui->tabParking->setModel(tmpParking.afficher(ui->triComboPar->currentText(), ui->rechComboPar->currentText(), ui->rechTextPar->text()));
}

void gerer_parking::on_ajouterPar_clicked(){
    bool control = true;
    int idParking = ui->idPar->text().toInt();
    if(idParking <0 || idParking > 99999 || isNaN(ui->idPar->text())){
        control = false;
        if(!currentLanguage){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - l'identifiant doit etre compris\n"
                                    "entre 0 et 99999"), QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("INPUT CONTROL"),
                        QObject::tr("Error - Identifier must be\n"
                                    "between 0 and 99999"), QMessageBox::Cancel);
        }
    }
    int capaciteParking = ui->capacitePar->text().toInt();
    if(capaciteParking < 0 || capaciteParking > 99999 || isNaN(ui->capacitePar->text())){
        control = false;
        if(!currentLanguage){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - la capacite doit etre comprise\n"
                                    "entre 0 et 99999"), QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("INPUT CONTROL"),
                        QObject::tr("Error - Capacity must be\n"
                                    "between 0 and 99999"), QMessageBox::Cancel);
        }
    }
    int etatParking = ui->etatComboPar->currentText().toInt();
    if(control){
        parking pa(idParking, capaciteParking, etatParking);
        pa.currentLanguage = currentLanguage;
        bool test = pa.ajouter();
        if(test){
            rafraichir();
            if(!currentLanguage){
                mSystemTrayIcon->showMessage(tr("SUCCES D'AJOUT"),tr("Le parking vient d'etre ajouté"));
                QMessageBox::information(nullptr, QObject::tr("SUCCES D'AJOUT"),
                            QObject::tr("SUCCES - Le parking vient d'etre ajouté\n"
                                        ""), QMessageBox::Close);
            }else{
                mSystemTrayIcon->showMessage(tr("SUCCESS"),tr("The parking has been added successfully"));
                QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                            QObject::tr("SUCCESS - The parking has been successfully added\n"
                                        ""), QMessageBox::Close);
            }
        }else{
            if(!currentLanguage){
                QMessageBox::critical(nullptr, QObject::tr("ERREUR D'AJOUT"),
                            QObject::tr("Erreur - L'ajout du parking n'a pas été éffectué\n"
                                        ""), QMessageBox::Cancel);
            }else{
                QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                            QObject::tr("Error - The parking has not been added\n"
                                        ""), QMessageBox::Cancel);
            }
        }
     }
}

void gerer_parking::on_ajouterPl_clicked(){
    int control = true;
    int idPlace = ui->idPl->text().toInt();
    if (idPlace <0 || idPlace > 99999 || isNaN(ui->idPl->text())){
        control = false;
        if(!currentLanguage){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - l'identifiant de la place doit etre compris\n"
                                    "entre 0 et 99999"), QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("INPUT CONTROL"),
                        QObject::tr("Error - Place Identifier must be\n"
                                    "between 0 and 99999"), QMessageBox::Cancel);
        }
    }
    int etatPlace = ui->etatComboPl->currentText().toInt();
    int idParking = ui->idparkingComboPl->currentText().toInt();
    if(control){
         place pl(idPlace, etatPlace, idParking);
         pl.currentLanguage = currentLanguage;
        bool test = pl.ajouter();
        if(test){
            on_rafraichirPl_clicked();
            if(!currentLanguage){
                mSystemTrayIcon->showMessage(tr("SUCCES D'AJOUT"),tr("Le parking vient d'etre ajouté"));
                QMessageBox::information(nullptr, QObject::tr("SUCCES D'AJOUT"),
                            QObject::tr("SUCCES - La place vient d'etre ajoutée\n"
                                        ""), QMessageBox::Close);
            }else{
                mSystemTrayIcon->showMessage(tr("SUCCESS"),tr("The parking has been added successfully"));
                QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                            QObject::tr("SUCCESS - The place has been successfully added\n"
                                        ""), QMessageBox::Close);
            }
        }
    }
}

void gerer_parking::on_supprPar_clicked(){
    bool test = tmpParking.supprimer(ui->idSupprComboPar->currentText().toInt());
    if(test){
        rafraichir();
        if(!currentLanguage){
            QMessageBox::information(nullptr, QObject::tr("SUCCES DE SUPRESSION"),
                        QObject::tr("Succes - La supression du parking a été\n"
                                    "éffectuée avec succes"), QMessageBox::Close);
        }else{
            QMessageBox::information(nullptr, QObject::tr("DELETION SUCCESS"),
                        QObject::tr("SUCCESS - The parking has been successfully\n"
                                    "deleted"), QMessageBox::Close);
        }

    }
}

void gerer_parking::on_supprPl_clicked(){
    bool test = tmpPlace.supprimer(ui->idSupprComboPl->currentText().toInt());
    if(test){
        if(!currentLanguage){
            QMessageBox::information(nullptr, QObject::tr("SUCCES DE SUPRESSION"),
                        QObject::tr("Succes - La supression de la place a été\n"
                                    "éffectuée avec succes"), QMessageBox::Close);
        }else{
            QMessageBox::information(nullptr, QObject::tr("DELETION SUCCESS"),
                        QObject::tr("SUCCESS - The place has been successfully\n"
                                    "deleted"), QMessageBox::Close);
        }
        on_rafraichirPl_clicked();
    }
}

void gerer_parking::on_modifPar_clicked(){
    bool control = true;
    int id = ui->idModifComboPar->currentText().toInt();
    int idnew = ui->idModifPar->text().toInt();
    if (idnew <0 || idnew > 99999 || isNaN(ui->idModifPar->text())){
        control = false;
        if(!currentLanguage){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - l'identifiant du parking doit etre compris\n"
                                    "entre 0 et 99999"), QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("INPUT CONTROL"),
                        QObject::tr("Error - Parking Identifier must be\n"
                                    "between 0 and 99999"), QMessageBox::Cancel);
        }
    }
    int capacite = ui->capaciteModifPar->text().toInt();
    if (capacite <0 || capacite > 99999 || isNaN(ui->capaciteModifPar->text())){
        control = false;
        if(!currentLanguage){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - la capacite doit etre comprise\n"
                                    "entre 0 et 99999"), QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("INPUT CONTROL"),
                        QObject::tr("Error - The capacity must be\n"
                                    "between 0 and 99999"), QMessageBox::Cancel);
        }
    }
    int etat = ui->etatModifComboPar->currentText().toInt();
    parking pa(id, capacite, etat);
    pa.currentLanguage = currentLanguage;
    if(control){
        bool test = tmpParking.modifier(pa, idnew);
        if(test){
            if(!currentLanguage){
                QMessageBox::information(nullptr, QObject::tr("SUCCES DE MODIFICATION"),
                            QObject::tr("SUCCES - La modification à été effectuée\n"
                                        "avec succès"), QMessageBox::Cancel);
            }else{
                QMessageBox::information(nullptr, QObject::tr("MODIFICATION SUCCESS"),
                            QObject::tr("SUCCESS - The modification has been made\n"
                                        "with success"), QMessageBox::Cancel);
            }
            QSqlQueryModel* model = new QSqlQueryModel();
            model->setQuery("SELECT id FROM parking");
            ui->idSupprComboPar->setModel(model);
            ui->idModifComboPar->setModel(model);
            QSqlQuery q;
            q.prepare("SELECT * FROM parking WHERE id = :col");
            q.bindValue(":col", ui->idModifComboPar->currentText());
            if(q.exec()){
                while(q.next()){
                    ui->idModifPar->setText(q.value(0).toString());
                    ui->capaciteModifPar->setText(q.value(1).toString());
                    ui->etatModifComboPar->setCurrentIndex(q.value(2).toInt());
                }
            }
            ui->tabParking->setModel(tmpParking.afficher(ui->triComboPar->currentText(), ui->rechComboPar->currentText(), ui->rechTextPar->text()));        }
    }
}

void gerer_parking::on_modifPl_clicked(){
    bool control = true;
    int id = ui->idModifComboPl->currentText().toInt();
    int idnew = ui->idModifPl->text().toInt();
    if (idnew <0 || idnew > 99999 || isNaN(ui->idModifPl->text())){
        control = false;
        if(!currentLanguage){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - l'identifiant place doit etre compris\n"
                                    "entre 0 et 99999"), QMessageBox::Cancel);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - l'identifiant place doit etre compris\n"
                                    "entre 0 et 99999"), QMessageBox::Cancel);
        }
    }
    int etat = ui->etatModifComboPl->currentText().toInt();
    int idparking = ui->idparkingModifComboPl->currentText().toInt();
    place pl(id, etat, idparking);
    if(control){
    bool test = tmpPlace.modifier(pl, idnew);
    if(test){
        if(!currentLanguage){
            QMessageBox::information(nullptr, QObject::tr("SUCCES DE MODIFICATION"),
                        QObject::tr("SUCCES - La modification à été effectuée\n"
                                    "avec succès"), QMessageBox::Cancel);
        }else{
            QMessageBox::information(nullptr, QObject::tr("MODIFICATION SUCCESS"),
                        QObject::tr("SUCCESS - The modification has been made\n"
                                    "with success"), QMessageBox::Cancel);
        }
        on_rafraichirPl_clicked();
    }
   }
}

void gerer_parking::on_envoyer_clicked(){
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("mariem.ayadi@esprit.tn");
    smtp.setPassword("marioumaayadi27..");
    MimeMessage message;
    message.setSender(new EmailAddress("mariem.ayadi@esprit.tn", "Agent"));
    message.addRecipient(new EmailAddress("habib.majoul@esprit.tn", "Administrateur"));
    if(!currentLanguage){
        message.setSubject("Bus En Panne");
    }else{
        message.setSubject("Bus Out Of Order");
    }
    MimeText text;
    if(!currentLanguage){
        text.setText("Un bus est tombé en panne !!\n");
    }else{
        text.setText("A bus is out of order !!\n");
    }
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    if(smtp.sendMail(message)){
        if(!currentLanguage){
            QMessageBox::information(this, "Succes", "Mail envoye correctement");
        }else{
            QMessageBox::information(this, "Success", "Mail sent correctly");
        }
    }else{
        if(!currentLanguage){
            QMessageBox::critical(this, "Erreur", "Mail non envoye");
        }else{
            QMessageBox::critical(this, "Error", "Mail not sent");
        }
    }
    smtp.quit();
}

void gerer_parking::on_triComboPar_currentIndexChanged(){
    ui->tabParking->setModel(tmpParking.afficher(ui->triComboPar->currentText(), ui->rechComboPar->currentText(), ui->rechTextPar->text()));
}

void gerer_parking::on_rechComboPar_currentIndexChanged(){
    ui->tabParking->setModel(tmpParking.afficher(ui->triComboPar->currentText(), ui->rechComboPar->currentText(), ui->rechTextPar->text()));
}

void gerer_parking::on_triComboPl_currentIndexChanged(){
    ui->tabPlace->setModel(tmpPlace.afficher(ui->triComboPl->currentText(), ui->rechComboPl->currentText(), ui->rechTextPl->text()));
}

void gerer_parking::on_rechComboPl_currentIndexChanged(){
    ui->tabPlace->setModel(tmpPlace.afficher(ui->triComboPl->currentText(), ui->rechComboPl->currentText(), ui->rechTextPl->text()));
}

void gerer_parking::on_rechTextPar_textEdited(){
    ui->tabParking->setModel(tmpParking.afficher(ui->triComboPar->currentText(), ui->rechComboPar->currentText(), ui->rechTextPar->text()));
}

void gerer_parking::on_rechTextPl_textEdited(){
    ui->tabPlace->setModel(tmpPlace.afficher(ui->triComboPl->currentText(), ui->rechComboPl->currentText(), ui->rechTextPl->text()));
}

void gerer_parking::on_rafraichirPar_clicked(){
    rafraichir();
}

void gerer_parking::on_rafraichirPl_clicked(){
    QSqlQuery q;
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM place");
    ui->idSupprComboPl->setModel(model);
    ui->idModifComboPl->setModel(model);
    QSqlQueryModel* model2 = new QSqlQueryModel();
    model2->setQuery("SELECT id FROM parking");
    ui->idparkingComboPl->setModel(model2);
    ui->idparkingModifComboPl->setModel(model2);

        q.prepare("SELECT * FROM place WHERE id = :x");
        q.bindValue(":x", ui->idModifComboPl->currentText());
        if(q.exec()){
            while(q.next()){
                ui->idModifPl->setText(q.value(0).toString());
                ui->etatModifComboPl->setCurrentIndex(q.value(1).toInt());
                ui->idparkingModifComboPl->setCurrentText(q.value(2).toString());
            }
        }
    ui->tabPlace->setModel(tmpPlace.afficher(ui->triComboPl->currentText(), ui->rechComboPl->currentText(), ui->rechTextPl->text()));
}


void gerer_parking::on_idModifComboPar_currentIndexChanged(int index)
{
    QSqlQuery q;
    q.prepare("SELECT * FROM parking WHERE id = :col");
    q.bindValue(":col", ui->idModifComboPar->currentText());
    if(q.exec()){
        while(q.next()){
            ui->idModifPar->setText(q.value(0).toString());
            ui->capaciteModifPar->setText(q.value(1).toString());
            ui->etatModifComboPar->setCurrentIndex(q.value(2).toInt());
        }
    }
}

void gerer_parking::on_idModifComboPl_currentIndexChanged(int index){
    QSqlQuery q;
    q.prepare("SELECT * FROM place WHERE id = :col");
    q.bindValue(":col", ui->idModifComboPl->currentText());
    if(q.exec()){
        while(q.next()){
            ui->idModifPl->setText(q.value(0).toString());
            ui->etatModifComboPl->setCurrentIndex(q.value(1).toInt());
            ui->idparkingModifComboPl->setCurrentText(q.value(2).toString());
        }
    }
}

void gerer_parking::on_tabWidget_currentChanged(int index){
    if(index == 0){
        rafraichir();
    }
    if(index == 1){
        on_rafraichirPl_clicked();
    }
    if(index == 2){
        if(ui->statCombo->currentIndex() == 0){
            statistique1();
        }
        if(ui->statCombo->currentIndex() == 1){
            statistique2();
        }
    }
}

void gerer_parking::on_statCombo_currentIndexChanged(int index){
    if(ui->tabWidget->currentIndex() == 2){
        if(index == 0){
            statistique1();
        }
        if(index == 1){
            statistique2();
        }
    }
}

void gerer_parking::statistique1(){
    QSqlQuery query, queryCount, queryTotal;
    QBarSet* tab[50];
    QBarSeries * series = new QBarSeries();
    QChart * chart;
    QStringList categories;
    queryTotal.prepare("SELECT COUNT(*) FROM place WHERE etat = 0"); //Trouver le nombre de places totales occupées
    queryTotal.exec(); // executer
    while(queryTotal.next()){ //parcourir les resultats de la requete
        query.prepare("SELECT id FROM parking"); //recevoir tous les ids des parking
        query.exec(); //executer
        int numParking = 0, nb;
        while(query.next()){ //parcourir les resultats (les id 1 par 1)
            queryCount.prepare("SELECT COUNT(*) FROM place WHERE idparking = :id AND etat = 0"); //calculer le nombre de places occupées dans le parking courant
            queryCount.bindValue(":id", query.value(0).toString()); //associer la valeur au parametre
            queryCount.exec();
            while(queryCount.next()){
                nb = queryCount.value(0).toInt() * 100 / queryTotal.value(0).toInt(); //calcul de pourcentage
                QString nbS = QString::number(nb);
                tab[numParking] = new QBarSet("P" + query.value(0).toString() + " (" + nbS + "%)");
                *tab[numParking] << nb;
                series->append(tab[numParking]);
                numParking++;
            }
        }
        chart = new QChart();
        chart->addSeries(series);
        if(!currentLanguage){
            chart->setTitle("Statistique: Parkings les plus occupés");
        }else{
            chart->setTitle("Statistics: Most occupied parkings");
        }
        chart->setAnimationOptions(QChart::AllAnimations);
        if(!currentLanguage){
            categories << "Nombre de places occupées: " + queryTotal.value(0).toString();
        }else{
            categories << "Number of occupied places: " + queryTotal.value(0).toString();
        }
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

void gerer_parking::statistique2(){
    QSqlQuery query, queryCount, queryTotal;
    QBarSet* tab[50];
    QBarSeries * series = new QBarSeries();
    QChart * chart;
    QStringList categories;
    queryTotal.prepare("SELECT COUNT(*) FROM place WHERE etat = 1"); //Trouver le nombre de places totales non occupées
    queryTotal.exec(); // executer
    while(queryTotal.next()){ //parcourir les resultats de la requete
        query.prepare("SELECT id FROM parking"); //recevoir tous les ids des parking
        query.exec(); //executer
        int numParking = 0, nb;
        while(query.next()){ //parcourir les resultats (les id 1 par 1)
            queryCount.prepare("SELECT COUNT(*) FROM place WHERE idparking = :id AND etat = 1"); //calculer le nombre de places non occupées dans le parking courant
            queryCount.bindValue(":id", query.value(0).toString()); //associer la valeur au parametre
            queryCount.exec();
            while(queryCount.next()){
                nb = queryCount.value(0).toInt() * 100 / queryTotal.value(0).toInt(); //calcul de pourcentage
                QString nbS = QString::number(nb);
                tab[numParking] = new QBarSet("P" + query.value(0).toString() + " (" + nbS + "%)");
                *tab[numParking] << nb;
                series->append(tab[numParking]);
                numParking++;
            }
        }
        chart = new QChart();
        chart->addSeries(series);
        if(!currentLanguage){
            chart->setTitle("Statistique: Parkings les moins occupés");
        }else{
            chart->setTitle("Statistics: Most unoccupied parkings");
        }
        chart->setAnimationOptions(QChart::AllAnimations);
        if(!currentLanguage){
            categories << "Nombre de places occupées: " + queryTotal.value(0).toString();
        }else{
            categories << "Number of unoccupied places: " + queryTotal.value(0).toString();
        }
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

void gerer_parking::on_langueCombo_currentIndexChanged(){
    currentLanguage = ui->langueCombo->currentIndex();
    tmpParking.currentLanguage = currentLanguage;
    tmpPlace.currentLanguage = currentLanguage;
    if(!currentLanguage){
        ui->trierPar->setText("Trier par");
        ui->rafraichirPar->setText("Actualiser");
        ui->rafraichirPl->setText("Actualiser");
        ui->trierParPl->setText("Trier par");
        ui->triComboPar->clear();
        ui->triComboPar->addItem("Identifiant");
        ui->triComboPar->addItem("Capacite");
        ui->triComboPar->addItem("Etat");
        ui->triComboPl->clear();
        ui->triComboPl->addItem("Identifiant");
        ui->triComboPl->addItem("Etat");
        ui->triComboPl->addItem("ID Parking");
        ui->trierParPl->setText("Trier par");
        ui->rechComboPar->clear();
        ui->rechComboPar->addItem("Identifiant");
        ui->rechComboPar->addItem("Capacite");
        ui->rechComboPar->addItem("Etat");
        ui->rechComboPl->clear();
        ui->rechComboPl->addItem("Identifiant");
        ui->rechComboPl->addItem("Etat");
        ui->rechComboPl->addItem("ID Parking");
        ui->rechercher->setText("Rechercher");
        ui->rechercherPl->setText("Rechercher");
        ui->ajouterPar->setText("Ajouter");
        ui->ajouterPl->setText("Ajouter");
        ui->modifPar->setText("Modifier");
        ui->modifPl->setText("Modifier");
        ui->supprPar->setText("Supprimer");
        ui->supprPl->setText("Supprimer");
        ui->statCombo->clear();
        ui->statCombo->addItem("Parkings les plus occupés");
        ui->statCombo->addItem("Parkings les moins occupés");
        ui->tabWidget->setTabText(0, "Gestion des Parkings");
        ui->tabWidget->setTabText(1, "Gestion des Places");
        ui->tabWidget->setTabText(2, "Statistiques");
        ui->tabWidget->setTabText(3, "Alerter une Panne");
        ui->envoyer->setText("Alerter");
        ui->langueCombo->setItemText(0, "Français");
        ui->langueCombo->setItemText(1, "Anglais");
    }else{
        ui->trierPar->setText("Order by");
        ui->rafraichirPar->setText("Refresh");
        ui->rafraichirPl->setText("Refresh");
        ui->trierParPl->setText("Order by");
        ui->triComboPar->clear();
        ui->triComboPar->addItem("Identifier");
        ui->triComboPar->addItem("Capacity");
        ui->triComboPar->addItem("State");
        ui->triComboPl->clear();
        ui->triComboPl->addItem("Identifier");
        ui->triComboPl->addItem("State");
        ui->triComboPl->addItem("Parking ID");
        ui->rechComboPar->clear();
        ui->rechComboPar->addItem("Identifier");
        ui->rechComboPar->addItem("Capacity");
        ui->rechComboPar->addItem("State");
        ui->rechComboPl->clear();
        ui->rechComboPl->addItem("Identifier");
        ui->rechComboPl->addItem("State");
        ui->rechComboPl->addItem("Parking ID");
        ui->rechercher->setText("Search");
        ui->rechercherPl->setText("Search");
        ui->ajouterPar->setText("Add");
        ui->ajouterPl->setText("Add");
        ui->modifPar->setText("Modify");
        ui->modifPl->setText("Modify");
        ui->supprPar->setText("Delete");
        ui->supprPl->setText("Delete");
        ui->statCombo->clear();
        ui->statCombo->addItem("Most occupied parkings");
        ui->statCombo->addItem("Most unoccupied parkings");
        ui->tabWidget->setTabText(0, "Parking Management");
        ui->tabWidget->setTabText(1, "Place Management");
        ui->tabWidget->setTabText(2, "Statistics");
        ui->tabWidget->setTabText(3, "Alert a Breakdown");
        ui->envoyer->setText("Alert");
        ui->langueCombo->setItemText(0, "French");
        ui->langueCombo->setItemText(1, "English");
    }
}

