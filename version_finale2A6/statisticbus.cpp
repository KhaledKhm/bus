#include "statisticbus.h"
#include "ui_statisticbus.h"
#include <QMediaPlayer>
statisticBus::statisticBus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statisticBus)
{
    ui->setupUi(this);
}

statisticBus::~statisticBus()
{
    delete ui;
}

void statisticBus::on_retour_clicked()
{    QMediaPlayer * music = new QMediaPlayer();
     music->setMedia(QUrl("qrc:/new/sound/boutton.wav"));
     music->play();
    hide();
}
int statisticBus::StatistiqueBus_partie1()
{

    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from bus where nbPlace=30") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}

int statisticBus::StatistiqueBus_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from bus where nbPlace=50") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
void statisticBus::paintEvent(QPaintEvent *)
{

    int a=StatistiqueBus_partie1();
    cout<<a<<endl  ;
    int b=StatistiqueBus_partie2();
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
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*x);
    ui->label->setText("Bus de 30 places") ;
    painter.setBrush(Qt::cyan);
    painter.drawPie(size,16*x,16*y);
    ui->label_2->setText("Bus de 50 places") ;
    /*painter.setBrush(Qt::green);
    painter.drawPie(size,16*(y+x),16*m);
    ui->label_3->setText("ouvrier") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y+x),16*z);
    ui->label_4->setText("administratif") ;
*/
}
