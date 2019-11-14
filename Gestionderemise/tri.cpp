#include "tri.h"
#include "ui_tri.h"

Tri::Tri(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tri)
{
    ui->setupUi(this);
}

Tri::~Tri()
{
    delete ui;
}
