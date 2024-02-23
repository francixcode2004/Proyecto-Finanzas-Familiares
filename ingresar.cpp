#include "ingresar.h"
#include "ui_ingresar.h"

Ingresar::Ingresar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingresar)
{
    ui->setupUi(this);
}

Ingresar::~Ingresar()
{
    delete ui;
}
