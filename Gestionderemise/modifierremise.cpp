#include "modifierremise.h"
#include "ui_modifierremise.h"

modifierremise::modifierremise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifierremise)
{
    ui->setupUi(this);
}

modifierremise::~modifierremise()
{
    delete ui;
}
