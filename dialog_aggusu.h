#ifndef DIALOG_AGGUSU_H
#define DIALOG_AGGUSU_H
#include "controlador_usuarios.h"

#include <QDialog>

namespace Ui {
class Dialog_aggusu;
}

class Dialog_aggusu : public QDialog
{
    Q_OBJECT


public:
    explicit Dialog_aggusu(QWidget *parent = nullptr);
    Controlador_usuarios *egresos()const;
    ~Dialog_aggusu();

private slots:
    void on_btnguardar_clicked();

    void on_btncancelar_clicked();

private:
    Ui::Dialog_aggusu *ui;
    Controlador_usuarios *m_egresos;
};

#endif // DIALOG_AGGUSU_H
