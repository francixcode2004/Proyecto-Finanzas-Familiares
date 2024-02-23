#include "dialog_aggin.h"
#include "ui_dialog_aggin.h"
#include <QMessageBox>
#define DESCRIPCION_RX "([a-zA-Z',.-]+( [a-zA-Z',.-]+)*){2,30}"

Dialog_Aggin::Dialog_Aggin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Aggin)
{
    ui->setupUi(this);
    QRegExp rxDescripcion(DESCRIPCION_RX);
    QRegExpValidator *validescrip =new QRegExpValidator(rxDescripcion,this);
    ui->Indescripcion->setValidator(validescrip);
}

Controlador_ingresos *Dialog_Aggin::ingresos() const
{
    return m_ingresos;
}

Dialog_Aggin::~Dialog_Aggin()
{
    delete ui;
}

void Dialog_Aggin::on_btnguardar_clicked()
{

    QString monto = ui->Inmonto->text();
    QString fecha = ui->Infecha->text();
    QString rol = ui->Inrol->currentText();
    QString categoria = ui->Incategoria->currentText();
    QString descripcion = ui->Indescripcion->text();
    if(monto.isEmpty() or descripcion.isEmpty() or fecha.isEmpty() or rol.isEmpty() or categoria.isEmpty()){
        QMessageBox::warning(this,"ERROR!!!",
                             "No se puede agregar datos invalidos");

    }else{
        this->m_ingresos = new Controlador_ingresos(monto,fecha,rol,categoria, descripcion);
        accept();
    }
}


void Dialog_Aggin::on_btncancelar_clicked()
{
    reject();
}


