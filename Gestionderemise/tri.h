#ifndef TRI_H
#define TRI_H

#include <QWidget>

namespace Ui {
class Tri;
}

class Tri : public QWidget
{
    Q_OBJECT

public:
    explicit Tri(QWidget *parent = nullptr);
    ~Tri();

private:
    Ui::Tri *ui;
};

#endif // TRI_H
