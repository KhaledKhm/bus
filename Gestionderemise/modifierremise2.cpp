#include "modifierremise2.h"
#include "ui_modifierremise2.h"

modifierremise2::modifierremise2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifierremise2)
{
    ui->setupUi(this);
}

modifierremise2::~modifierremise2()
{
    delete ui;
}
