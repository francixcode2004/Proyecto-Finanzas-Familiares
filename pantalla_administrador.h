#ifndef PANTALLA_ADMINISTRADOR_H
#define PANTALLA_ADMINISTRADOR_H

#include <QDialog>

namespace Ui {
class Pantalla_administrador;
}

class Pantalla_administrador : public QDialog
{
    Q_OBJECT

public:
    explicit Pantalla_administrador(QWidget *parent = nullptr);
    ~Pantalla_administrador();

private slots:
    void on_btn_usuarios_clicked();

    void on_btn_pantalla_clicked();

private:
    Ui::Pantalla_administrador *ui;
};

#endif // PANTALLA_ADMINISTRADOR_H
