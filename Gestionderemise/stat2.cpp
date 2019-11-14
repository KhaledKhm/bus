#include "stat2.h"
#include "ui_stat2.h"

Stat2::Stat2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stat2)
{
    ui->setupUi(this);
}

Stat2::~Stat2()
{
    delete ui;
}
