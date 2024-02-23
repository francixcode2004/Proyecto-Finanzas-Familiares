#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    QString verificacion();
    QString newUser();
    QString nombre ();

private slots:

    void on_btncuenta_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
