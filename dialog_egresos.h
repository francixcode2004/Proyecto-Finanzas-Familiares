#ifndef DIALOG_IEGRESOS_H
#define DIALOG_IEGRESOS_H
#include <QDialog>
#include <QTableWidgetItem>
#include <string>
#include <iostream>
#include <pantalla_principal.h>
using namespace std;
namespace Ui {
class Dialog_egresos;
}

class Dialog_egresos : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_egresos(QWidget *parent = nullptr);
    ~Dialog_egresos();
    void cargar();
    double promedio_1();

private slots:
    void on_agregarboton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_btneliminar_clicked();

    void on_tbtLista_itemClicked(QTableWidgetItem *item);

    void on_btnmodificar_clicked();

    void on_btnbuscar_clicked();

private:
    Ui::Dialog_egresos *ui;
    const QString ARCHIVO = "egresos.csv";
    int m_u;
    int m_f;
    enum Columna
    {
        MONTO, FECHA, ROL, CATEGORIA,DESCRIPCION
    };
    QList<double> m_datos;
};

#endif // DIALOG_INGRESOS_H
