#include "supprimeruneremise.h"
#include "ui_supprimeruneremise.h"

Supprimeruneremise::Supprimeruneremise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Supprimeruneremise)
{
    ui->setupUi(this);
}

Supprimeruneremise::~Supprimeruneremise()
{
    delete ui;
}
