#include "register.h"
#include "ui_register.h"
#include "usuario.h"

QString Register::nombre()
{
    QString nombre=ui->innombre1->text();
    return nombre;
}

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

QString Register::verificacion()
{
    return ui->inContra->text() + ";" + ui->inContraVeri->text();
}

QString Register::newUser()
{
    return ui->inNombre->text() + ";" + ui->inContra->text();
}


void Register::on_btncuenta_clicked()
{
 qDebug()<<"el nombre de usuario es: "<<nombre();
    Usuario Usuario;
    bool contr;
    contr = Usuario.registrarse(verificacion(),newUser());
    QString email = ui->inNombre->text();
    QRegExp emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if(ui->inNombre->text().isEmpty() or !emailRegex.exactMatch(email) or contr==0 or ui->inContra->text().isEmpty() or ui->inContraVeri->text().isEmpty() ){
        QMessageBox::warning(this, "Error", "Por favor, ingrese un correo valido y verifique .");
        return;

    }else{
        close();
    }
}


