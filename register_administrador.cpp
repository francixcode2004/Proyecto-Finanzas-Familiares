    #include "register_administrador.h"
#include "ui_register_administrador.h"
#include "controlador_administrador.h"

Register_administrador::Register_administrador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register_administrador)
{
    ui->setupUi(this);
}

Register_administrador::~Register_administrador()
{
    delete ui;
}

QString Register_administrador::verificacion()
{
    return ui->inContra->text() + ";" + ui->inContraVeri->text();
}

QString Register_administrador::newUser()
{
    return ui->inNombre->text() + ";" + ui->inContra->text();
}


void Register_administrador::on_btncuenta_clicked()
{
    close();
    Controlador_administrador Usuario;
    bool contr;
    contr = Usuario.registrarse(verificacion(),newUser());
    if(contr == 0){
        QMessageBox::warning(this, "Error", "Comprueba las contraseñas e intenta nuevamente");
        return;
    }
}


