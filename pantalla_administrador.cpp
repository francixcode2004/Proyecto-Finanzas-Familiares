#include "pantalla_administrador.h"
#include "ui_pantalla_administrador.h"
#include "usuarios.h"
#include "pantalla_principal.h"

Pantalla_administrador::Pantalla_administrador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pantalla_administrador)
{
    ui->setupUi(this);
}

Pantalla_administrador::~Pantalla_administrador()
{
    delete ui;
}

void Pantalla_administrador::on_btn_usuarios_clicked()
{
    close();
    Usuarios *ventana1 = new Usuarios;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}


void Pantalla_administrador::on_btn_pantalla_clicked()
{
    close();
    Pantalla_principal *ventana1 = new Pantalla_principal;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->showMaximized();
}

