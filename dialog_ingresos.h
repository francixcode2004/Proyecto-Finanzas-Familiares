#ifndef DIALOG_INGRESOS_H
#define DIALOG_INGRESOS_H

#include "qdatetime.h"
#include <QDialog>
#include <QTableWidgetItem>
#include <string>
#include <iostream>
#include <pantalla_principal.h>

using namespace std;
namespace Ui {
class Dialog_ingresos;
}

class Dialog_ingresos : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ingresos(QWidget *parent = nullptr);
    ~Dialog_ingresos();
    double promedio();
private slots:
    void on_agregarboton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_btneliminar_clicked();

    void on_tbtLista_itemClicked(QTableWidgetItem *item);

    void on_btnmodificar_clicked();

    void on_btnbuscar_clicked();

private:
    Ui::Dialog_ingresos *ui;
    const QString ARCHIVO = "ingresos.csv";
    int m_u;
    int m_f;
    enum Columna
    {
        MONTO, FECHA, ROL, CATEGORIA,DESCRIPCION
    };
    void cargar();


};

#endif // DIALOG_INGRESOS_H
