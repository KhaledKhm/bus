#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_retour_clicked();

    void on_gererAbonne_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
