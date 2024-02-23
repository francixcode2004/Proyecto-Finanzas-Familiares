#include "dialog_ingresos.h"
#include "ui_dialog_ingresos.h"
#include "dialog_aggin.h"
#include"controlador_ingresos.h"
#include<QFile>
#include <QTextStream>
#include <QMessageBox>

#define DESCRIPCION_RX "([a-zA-Z',.-]+( [a-zA-Z',.-]+)*){2,30}"
#define MONTO_RX "([0-9]+( [0-9]+)*){1,10}"

Dialog_ingresos::Dialog_ingresos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ingresos)
{
    ui->setupUi(this);
    QRegExp rxDescripcion(DESCRIPCION_RX),rxMonto(MONTO_RX);
    QRegExpValidator *validescrip =new QRegExpValidator(rxDescripcion,this);
    QRegExpValidator *valimonto = new QRegExpValidator(rxMonto, this);
    ui->Inmonto->setValidator(valimonto);
    ui->Indescripcion->setValidator(validescrip);
    setWindowTitle("INGRESOS");
    // Configurar la tabla
    //ui->tblLista->setColumnCount(4);
    ui->tbtLista->setColumnCount(5);
    QStringList titulo;
    titulo << "Monto" << "Fecha" << "Rol" << "Categoria"<<"Descripcion";
    ui->tbtLista->setHorizontalHeaderLabels(titulo);
    // Leer desde el archivo
    cargar();
}

Dialog_ingresos::~Dialog_ingresos()
{
    delete ui;
}

void Dialog_ingresos::on_agregarboton_clicked()
{
    // Crear y mostrar el dialogo
    Dialog_Aggin pd(this);
    pd.setWindowTitle("INGRESOS");
    // Abrir la ventana y evaluar respuesta
    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Controlador_ingresos *m = pd.ingresos();
    //Agregar a la tabla
    int fila = ui->tbtLista->rowCount();
    ui->tbtLista->insertRow(fila);
    ui->tbtLista->setItem(fila, MONTO, new QTableWidgetItem(m->monto()));
    ui->tbtLista->setItem(fila, FECHA, new QTableWidgetItem(m->fecha()));
    ui->tbtLista->setItem(fila, ROL, new QTableWidgetItem(m->rol()));
    ui->tbtLista->setItem(fila, CATEGORIA, new QTableWidgetItem(m->categoria()));
    ui->tbtLista->setItem(fila, DESCRIPCION, new QTableWidgetItem(m->descripcion()));
}

void Dialog_ingresos::cargar()
{
    // Verificar si el archivo existe
    QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;

    // cargar datos
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tbtLista->rowCount();
            ui->tbtLista->insertRow(fila);
            ui->tbtLista->setItem(fila, MONTO, new QTableWidgetItem(datos[MONTO]));
            ui->tbtLista->setItem(fila, FECHA, new QTableWidgetItem(datos[FECHA]));
            ui->tbtLista->setItem(fila, ROL, new QTableWidgetItem(datos[ROL]));
            ui->tbtLista->setItem(fila, CATEGORIA, new QTableWidgetItem(datos[CATEGORIA]));
            ui->tbtLista->setItem(fila, DESCRIPCION, new QTableWidgetItem(datos[DESCRIPCION]));
        }
        archivo.close();
    }
}


void Dialog_ingresos::on_buttonBox_accepted()
{
    // Verificar que exista datos para guardar
    int filas = ui->tbtLista->rowCount();
    if (filas == 0){
        QMessageBox::warning(this,"Guardar ingresos","ingresos sin datos para guardar");
        return;
    }
    close();
    // Abrir el archivo y guardar
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *monto = ui->tbtLista->item(i, MONTO);
            QTableWidgetItem *fecha = ui->tbtLista->item(i, FECHA);
            QTableWidgetItem *rol = ui->tbtLista->item(i, ROL);
            QTableWidgetItem *categoria = ui->tbtLista->item(i, CATEGORIA);
            QTableWidgetItem *descripcion = ui->tbtLista->item(i, DESCRIPCION);
            salida << monto->text() << ";" << fecha->text() << ";";
            salida << rol->text() << ";" << categoria->text()<<";"<<descripcion->text() << "\n";
        }
        archivo.close();
        QMessageBox::information(this,"Guardar ingresos","Ingresos guardados con éxito");
    }else{
        QMessageBox::critical(this,"Guardar ingresos", "No se puede escribir sobre " + ARCHIVO);
    }
    Pantalla_principal *ventana1= new Pantalla_principal;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->showMaximized();
}


void Dialog_ingresos::on_buttonBox_rejected()
{
    reject();
}

void Dialog_ingresos::on_btneliminar_clicked()
{
    ui->tbtLista->removeRow(m_f);

}


void Dialog_ingresos::on_tbtLista_itemClicked(QTableWidgetItem *item)
{
    m_f= item->row();
    QTableWidgetItem *monto = ui->tbtLista->item(m_f,0);
    QTableWidgetItem *fecha = ui->tbtLista->item(m_f,1);
    QTableWidgetItem *rol = ui->tbtLista->item(m_f,2);
    QTableWidgetItem *categoria = ui->tbtLista->item(m_f,3);
    QTableWidgetItem *descripcion = ui->tbtLista->item(m_f,4);

    ui->Inmonto->setText(monto->text());
    ui->Infecha->setSpecialValueText(fecha->text());
    ui->Inrol->currentTextChanged(rol->text());
    ui->Incategoria->currentTextChanged(categoria->text());
    ui->Indescripcion->setText(descripcion->text());
}


void Dialog_ingresos::on_btnmodificar_clicked()
{
    ui->tbtLista->setItem(m_f,0,new QTableWidgetItem(ui->Inmonto->text()));
    ui->tbtLista->setItem(m_f,1,new QTableWidgetItem(ui->Infecha->text()));
    ui->tbtLista->setItem(m_f,2,new QTableWidgetItem(ui->Inrol->currentText()));
    ui->tbtLista->setItem(m_f,3,new QTableWidgetItem(ui->Incategoria->currentText()));
    ui->tbtLista->setItem(m_f,4,new QTableWidgetItem(ui->Indescripcion->text()));


}

void Dialog_ingresos::on_btnbuscar_clicked()
{
    QString fechaBuscar = ui->Infecha_2->text();
    //int column = 0; // la columna donde está la fecha
    QList<QTableWidgetItem*> items = ui->tbtLista->findItems(fechaBuscar, Qt::MatchExactly);
    if (!items.isEmpty())
    {
        int row = items.at(0)->row();
        ui->tbtLista->selectRow(row);
    }
    else
    {
        QMessageBox::warning(this, "Advertencia", "Fecha no encontrada");
    }

}
double Dialog_ingresos::promedio()
{
    //int column = MONTO; // La columna donde se encuentra el monto
    int rowCount = ui->tbtLista->rowCount(); // El número de filas en la tabla
    float suma = 0;
    int montoInt=0;
    // Recorre todas las filas de la columna
    for (int row = 0; row < rowCount; row++)
    {
        // Obtiene el elemento de la celda
        QString monto = ui->tbtLista->item(row,MONTO)->text();
        string monto_1 = monto.toStdString();
        montoInt = stof(monto_1);
        suma += montoInt;
    }
    return suma;
}
