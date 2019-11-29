#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerer_abonnement.h"
#include "gerer_conv.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_abonne_clicked()
{
    gerer_abonnement g;
    g.exec();
}

void MainWindow::on_convention_clicked()
{
    gerer_conv c;
    c.exec();
}
