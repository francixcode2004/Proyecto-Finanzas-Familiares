#ifndef DIALOG_AGGIN_H
#define DIALOG_AGGIN_H
#include "controlador_ingresos.h"

#include <QDialog>

namespace Ui {
class Dialog_Aggin;
}

class Dialog_Aggin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Aggin(QWidget *parent = nullptr);
    Controlador_ingresos *ingresos()const;
    ~Dialog_Aggin();

private slots:
    void on_btnguardar_clicked();

    void on_btncancelar_clicked();

private:
    Ui::Dialog_Aggin *ui;
    Controlador_ingresos *m_ingresos;
};

#endif // DIALOG_AGGIN_H
