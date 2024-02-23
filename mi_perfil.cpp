#include "mi_perfil.h"
#include "ui_mi_perfil.h"
#include <pantalla_principal.h>
#include <widget.h>
#include <register.h>

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

Mi_perfil::Mi_perfil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mi_perfil)
{
    ui->setupUi(this);
    Register *user = new Register;
    m_usuario =user->nombre();
    ui->lbl_user->setText("Usuario: "+ m_usuario);
}

Mi_perfil::~Mi_perfil()
{
    delete ui;
}


void Mi_perfil::on_btnsalir_clicked()
{
    close();
    Register *ventana1= new Register;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}

void Mi_perfil::on_btnregresar_clicked()
{

    close();
    Pantalla_principal *ventana1= new Pantalla_principal;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->showMaximized();
}


