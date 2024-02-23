#include "usuarios.h"
#include "ui_usuarios.h"
#include "controlador_usuarios.h"
#include "dialog_aggusu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


Usuarios::Usuarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usuarios)
{
    ui->setupUi(this);

    setWindowTitle("USUARIOS");
    // Configurar la tabla
    //ui->tblLista->setColumnCount(2);
    ui->tbtLista->setColumnCount(2);
    QStringList titulo;
    titulo << "Usuario" << "Contraseña";
    ui->tbtLista->setHorizontalHeaderLabels(titulo);
    // Leer desde el archivo
    cargar();
}

Usuarios::~Usuarios()
{
    delete ui;
}

void Usuarios::on_agregarboton_clicked()
{
    // Crear y mostrar el dialogo
    Dialog_aggusu pd(this);
    pd.setWindowTitle("EGRESOS");
    // Abrir la ventana y evaluar respuesta
    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Controlador_usuarios *m = pd.egresos();
    //Agregar a la tabla
    //Agregar a la tabla
    int fila = ui->tbtLista->rowCount();
    ui->tbtLista->insertRow(fila);
    ui->tbtLista->setItem(fila, USUARIO, new QTableWidgetItem(m->usuario()));
    ui->tbtLista->setItem(fila, CONTRASENA, new QTableWidgetItem(m->contrasena()));
}

void Usuarios::cargar()
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
            ui->tbtLista->setItem(fila, USUARIO, new QTableWidgetItem(datos[USUARIO]));
            ui->tbtLista->setItem(fila, CONTRASENA, new QTableWidgetItem(datos[CONTRASENA]));
        }
        archivo.close();
    }
}


void Usuarios::on_buttonBox_accepted()
{
    // Verificar que exista datos para guardar
    int filas = ui->tbtLista->rowCount();
    if (filas == 0){
        QMessageBox::warning(this,"Guardar usuarios","no existen datos para guardar");
        return;
    }
    // Abrir el archivo y guardar
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *usuario = ui->tbtLista->item(i, USUARIO);
            QTableWidgetItem *contrasena = ui->tbtLista->item(i, CONTRASENA);
            salida << usuario->text() << ";" << contrasena->text() << "\n";

        }
        archivo.close();
        QMessageBox::information(this,"Guardar usuarios","Usuarios guardados con éxito");
    }else{
        QMessageBox::critical(this,"Guardar usuarios", "No se puede escribir sobre " + ARCHIVO);
    }
}


void Usuarios::on_buttonBox_rejected()
{
    reject();
}

void Usuarios::on_btneliminar_clicked()
{
    ui->tbtLista->removeRow(m_f);

}


void Usuarios::on_tbtLista_itemClicked(QTableWidgetItem *item)
{
     m_f= item->row();
     QTableWidgetItem *usuario = ui->tbtLista->item(m_f,0);
     QTableWidgetItem *contrasena = ui->tbtLista->item(m_f,1);

     ui->Inusuario->setText(usuario->text());
     ui->Incontrasena->setText(contrasena->text());

}


void Usuarios::on_btnmodificar_clicked()
{
    ui->tbtLista->setItem(m_f,0,new QTableWidgetItem(ui->Inusuario->text()));
    ui->tbtLista->setItem(m_f,1,new QTableWidgetItem(ui->Incontrasena->text()));


}



