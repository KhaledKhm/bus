#include "stastic.h"
#include "ui_stastic.h"

statistic::statistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistic)
{
    ui->setupUi(this);
}

statistic::~stastic()
{
    delete ui;
}
