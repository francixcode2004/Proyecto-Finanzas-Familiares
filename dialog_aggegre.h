#ifndef DIALOG_AGGEGRE_H
#define DIALOG_AGGEGRE_H
#include "controlador_egresos.h"

#include <QDialog>

namespace Ui {
class Dialog_aggegre;
}

class Dialog_aggegre : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_aggegre(QWidget *parent = nullptr);
    Controlador_egresos *egresos()const;
    ~Dialog_aggegre();

private slots:
    void on_btnguardar_clicked();

    void on_btncancelar_clicked();

private:
    Ui::Dialog_aggegre *ui;
    Controlador_egresos *m_egresos;
};

#endif // DIALOG_AGGIN_H
