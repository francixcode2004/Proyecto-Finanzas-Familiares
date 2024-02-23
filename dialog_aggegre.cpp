#include "dialog_aggegre.h"
#include "ui_dialog_aggegre.h"
#include <QMessageBox>
#define DESCRIPCION_RX "([a-zA-Z',.-]+( [a-zA-Z',.-]+)*){2,30}"

Dialog_aggegre::Dialog_aggegre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_aggegre)
{
    ui->setupUi(this);
    QRegExp rxDescripcion(DESCRIPCION_RX);
    QRegExpValidator *validescrip =new QRegExpValidator(rxDescripcion,this);
    ui->Indescripcion->setValidator(validescrip);
}

Controlador_egresos *Dialog_aggegre::egresos() const
{
    return m_egresos;
}

Dialog_aggegre::~Dialog_aggegre()
{
    delete ui;
}

void Dialog_aggegre::on_btnguardar_clicked()
{
    QString monto = ui->Inmonto->text();
    QString fecha = ui->Infecha->text();
    QString rol = ui->Inrol->currentText();
    QString categoria = ui->Incategoria_1->currentText();
    QString descripcion = ui->Indescripcion->text();
    if(monto.isEmpty() or descripcion.isEmpty() or fecha.isEmpty() or rol.isEmpty() or categoria.isEmpty()){
        QMessageBox::warning(this,"ERROR!!!",
                             "No se puede agregar datos invalidos");

    }else{
        this->m_egresos = new Controlador_egresos(monto,fecha,rol,categoria, descripcion);
        accept();
    }
}


void Dialog_aggegre::on_btncancelar_clicked()
{
    reject();
}


