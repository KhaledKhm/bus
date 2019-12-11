#include "menu.h"
#include "ui_menu.h"
#include "gerer_abonne.h"
#include "gerer_parking.h"
#include "gerer_evenement.h"
#include "projetkhaled.h"
Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_retour_clicked()
{
    hide();
}

void Menu::on_gererAbonne_clicked()
{
    gerer_abonne ab;
    ab.exec();
}

void Menu::on_radioButton_3_clicked()
{
    gerer_parking pa;
    pa.exec();
}

void Menu::on_radioButton_5_clicked()
{
    gerer_evenement even;
    even.exec();
}

void Menu::on_radioButton_2_clicked()
{
    ProjetKhaled bus;
    bus.exec();
}
