#ifndef USUARIOS_H
#define USUARIOS_H

#include <QDialog>
#include <QTableWidgetItem>
#include <string>
#include <iostream>


namespace Ui {
class Usuarios;
}

class Usuarios : public QDialog
{
    Q_OBJECT

public:
    explicit Usuarios(QWidget *parent = nullptr);
    ~Usuarios();
    void cargar();

private slots:
    void on_agregarboton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_btneliminar_clicked();

    void on_tbtLista_itemClicked(QTableWidgetItem *item);

    void on_btnmodificar_clicked();

private:
    Ui::Usuarios *ui;
    const QString ARCHIVO = "usuarios.csv";
    int m_u;
    int m_f;
    enum Columna
    {
        USUARIO, CONTRASENA
    };
};

#endif // USUARIOS_H
