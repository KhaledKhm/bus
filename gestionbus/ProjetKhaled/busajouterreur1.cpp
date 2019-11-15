#include "busajouterreur1.h"
#include "ui_busajouterreur1.h"

busAjoutErreur1::busAjoutErreur1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::busAjoutErreur1)
{
    ui->setupUi(this);
}

busAjoutErreur1::~busAjoutErreur1()
{
    delete ui;
}
