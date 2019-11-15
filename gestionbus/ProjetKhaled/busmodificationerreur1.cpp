#include "busmodificationerreur1.h"
#include "ui_busmodificationerreur1.h"

busModificationErreur1::busModificationErreur1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::busModificationErreur1)
{
    ui->setupUi(this);
}

busModificationErreur1::~busModificationErreur1()
{
    delete ui;
}
