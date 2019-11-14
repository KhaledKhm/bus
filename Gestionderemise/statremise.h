#ifndef STATREMISE_H
#define STATREMISE_H

#include <QWidget>

namespace Ui {
class Statremise;
}

class Statremise : public QWidget
{
    Q_OBJECT

public:
    explicit Statremise(QWidget *parent = nullptr);
    ~Statremise();

private:
    Ui::Statremise *ui;
};

#endif // STATREMISE_H
