#include "statremise.h"
#include "ui_statremise.h"

Statremise::Statremise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statremise)
{
    ui->setupUi(this);
}

Statremise::~Statremise()
{
    delete ui;
}
