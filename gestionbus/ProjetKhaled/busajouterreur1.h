#ifndef BUSAJOUTERREUR1_H
#define BUSAJOUTERREUR1_H

#include <QWidget>

namespace Ui {
class busAjoutErreur1;
}

class busAjoutErreur1 : public QWidget
{
    Q_OBJECT

public:
    explicit busAjoutErreur1(QWidget *parent = nullptr);
    ~busAjoutErreur1();

private:
    Ui::busAjoutErreur1 *ui;
};

#endif // BUSAJOUTERREUR1_H
