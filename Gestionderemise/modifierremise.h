#ifndef MODIFIERREMISE_H
#define MODIFIERREMISE_H

#include <QWidget>

namespace Ui {
class modifierremise;
}

class modifierremise : public QWidget
{
    Q_OBJECT

public:
    explicit modifierremise(QWidget *parent = nullptr);
    ~modifierremise();

private:
    Ui::modifierremise *ui;
};

#endif // MODIFIERREMISE_H
