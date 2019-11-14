#ifndef MODIFIERREMISE2_H
#define MODIFIERREMISE2_H

#include <QWidget>

namespace Ui {
class modifierremise2;
}

class modifierremise2 : public QWidget
{
    Q_OBJECT

public:
    explicit modifierremise2(QWidget *parent = nullptr);
    ~modifierremise2();

private:
    Ui::modifierremise2 *ui;
};

#endif // MODIFIERREMISE2_H
