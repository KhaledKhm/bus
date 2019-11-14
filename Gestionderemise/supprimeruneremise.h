#ifndef SUPPRIMERUNEREMISE_H
#define SUPPRIMERUNEREMISE_H

#include <QWidget>

namespace Ui {
class Supprimeruneremise;
}

class Supprimeruneremise : public QWidget
{
    Q_OBJECT

public:
    explicit Supprimeruneremise(QWidget *parent = nullptr);
    ~Supprimeruneremise();

private:
    Ui::Supprimeruneremise *ui;
};

#endif // SUPPRIMERUNEREMISE_H
