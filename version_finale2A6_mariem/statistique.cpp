#include "statistique.h"
#include "ui_statistique.h"

#include <iostream>
#include <QDebug>

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
int statistique::Statistique_partie1()
{

    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from abonnement_normal where prix='100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}

int statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from abonnement_normal where prix='60'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
void statistique::paintEvent(QPaintEvent *)
{

    int a=Statistique_partie1();
    cout<<a<<endl  ;
    int b=Statistique_partie2();
    cout<<b<<endl ;

    float s1= a*100 ;
        float s2= b*100 ;

        float nb = a+b;
        float q1 ;
        q1 = s1/nb ;
        float q2 ;
        q2 = s2/nb ;

        float x  ;
        x= (q1*360)/100 ;
        float y  ;
        y = (q2*360)/100 ;

        float z  ;
        z=360-(x+y) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-300,this->width()-300);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*x);
    ui->label->setText("abonnement normal") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*x,16*y);
    ui->label_2->setText("abonnement eleve") ;
    /*painter.setBrush(Qt::green);
    painter.drawPie(size,16*(y+x),16*m);
    ui->label_3->setText("ouvrier") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y+x),16*z);
    ui->label_4->setText("administratif") ;
*/
}
void statistique::on_Retour_stat_clicked()
{
    hide();
}
