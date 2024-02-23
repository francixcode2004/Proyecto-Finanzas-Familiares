#ifndef REGISTER_ADMINISTRADOR_H
#define REGISTER_ADMINISTRADOR_H

#include <QDialog>

namespace Ui {
class Register_administrador;
}

class Register_administrador : public QDialog
{
    Q_OBJECT

public:
    explicit Register_administrador(QWidget *parent = nullptr);
    ~Register_administrador();
    QString verificacion();
    QString newUser();

private slots:

    void on_btncuenta_clicked();

private:
    Ui::Register_administrador *ui;
};

#endif // REGISTER_ADMINISTRADOR_H
