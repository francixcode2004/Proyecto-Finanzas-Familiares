#include "aggusuarios.h"
#include "ui_aggusuarios.h"

Aggusuarios::Aggusuarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aggusuarios)
{
    ui->setupUi(this);
}

Aggusuarios::~Aggusuarios()
{
    delete ui;
}
