#ifndef STAT2_H
#define STAT2_H

#include <QWidget>

namespace Ui {
class Stat2;
}

class Stat2 : public QWidget
{
    Q_OBJECT

public:
    explicit Stat2(QWidget *parent = nullptr);
    ~Stat2();

private:
    Ui::Stat2 *ui;
};

#endif // STAT2_H
