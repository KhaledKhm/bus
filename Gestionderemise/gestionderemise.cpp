#include "gestionderemise.h"
#include "ui_gestionderemise.h"

Gestionderemise::Gestionderemise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestionderemise)
{
    ui->setupUi(this);
}

Gestionderemise::~Gestionderemise()
{
    delete ui;
}
