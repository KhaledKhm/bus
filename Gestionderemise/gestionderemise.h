#ifndef GESTIONDEREMISE_H
#define GESTIONDEREMISE_H

#include <QWidget>

namespace Ui {
class Gestionderemise;
}

class Gestionderemise : public QWidget
{
    Q_OBJECT

public:
    explicit Gestionderemise(QWidget *parent = nullptr);
    ~Gestionderemise();

private:
    Ui::Gestionderemise *ui;
};

#endif // GESTIONDEREMISE_H
