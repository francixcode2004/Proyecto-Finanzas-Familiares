#include "dialog_administrador.h"
#include "ui_dialog_administrador.h"
#include <pantalla_principal.h>
#include <QCoreApplication>
#include "controlador_administrador.h"
#include "register_administrador.h"

Dialog_administrador::Dialog_administrador(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_administrador)
{
     ui->setupUi(this);
}

Dialog_administrador::~Dialog_administrador()
{
    delete ui;
}

QString Dialog_administrador::user()
{
    return ui->in_user->text() + ";" + ui->in_pass->text();
}

void Dialog_administrador::on_btn_ini_clicked()
{
    close();
    Controlador_administrador Usuario;
    Usuario.login(user());

}

void Dialog_administrador::on_btn_regis_clicked()
{
    Register_administrador reg(this);
    reg.setWindowTitle("Registro de nuevo Usuario");
    int res = reg.exec();
    if (res == QDialog::Rejected){
        return;
    }
}

