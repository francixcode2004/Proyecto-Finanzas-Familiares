#include "dialog_aggusu.h"
#include "ui_dialog_aggusu.h"
#include <QMessageBox>

Dialog_aggusu::Dialog_aggusu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_aggusu)
{
    ui->setupUi(this);
}

Controlador_usuarios *Dialog_aggusu::egresos() const
{
    return m_egresos;
}

Dialog_aggusu::~Dialog_aggusu()
{
    delete ui;
}

void Dialog_aggusu::on_btnguardar_clicked()
{
    QString usuario = ui->Inusuario->text();
    QString contrasena = ui->Incontrasena->text();

    if(usuario.isEmpty() or contrasena.isEmpty()){
        QMessageBox::warning(this,"ERROR!!!",
                             "No se puede agregar datos invalidos");

    }else{
        this->m_egresos = new Controlador_usuarios(usuario,contrasena);
        accept();
    }
}


void Dialog_aggusu::on_btncancelar_clicked()
{
    reject();
}
