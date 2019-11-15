#ifndef BUSMODIFICATIONERREUR1_H
#define BUSMODIFICATIONERREUR1_H

#include <QWidget>

namespace Ui {
class busModificationErreur1;
}

class busModificationErreur1 : public QWidget
{
    Q_OBJECT

public:
    explicit busModificationErreur1(QWidget *parent = nullptr);
    ~busModificationErreur1();

private:
    Ui::busModificationErreur1 *ui;
};

#endif // BUSMODIFICATIONERREUR1_H
