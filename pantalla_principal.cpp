#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
#include"agregar_miembro.h"
#include "widget.h"
#include "mi_perfil.h"
#include <QMessageBox>
#include <QDebug>
#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <dialog_ingresos.h>
#include <dialog_egresos.h>
#include "dialog_reporte.h"
#include "acerca.h"
#include <string>
#include <QString>

Pantalla_principal::Pantalla_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pantalla_principal)
{
    ui->setupUi(this);
    setWindowTitle("Principal");

    if(translatorEs.load(":/español.qm"))
        qDebug()<<"Traduccion cargada correctamente.";

    if(translatorEn.load(":/ingles.qm"))
        qDebug()<<"Traduccion cargada correctamente.";

    if(translatorPr.load(":/portugues.qm"))
        qDebug()<<"Traduccion cargada correctamente.";
    lienzo = QPixmap(1300,500);
    this->dibujar();
    ui->outCuadro->setPixmap(lienzo);

}

void Pantalla_principal::changeEvent(QEvent* event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}

void Pantalla_principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
}

void Pantalla_principal::dibujar()
{
    Dialog_egresos De;
    Dialog_ingresos Di;
    QColor CFondo(203, 255, 199);
    lienzo.fill(CFondo);
    QPainter painter(&lienzo);

    int x = 0;

    //Barra 1
    // Crear un pincel para los bordes
    QPen pincel;
    //pincel.setColor(Qt::green);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Crear un objeto color para el relleno
    QColor colorRelleno1(90,120,162);

    // Establecer el pincel al "pintor"
    painter.drawRect(390,40,120,420);
    painter.drawRect(810,40,120,420);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);

    //Obtener datos para la primera barra
    float nota1 = De.promedio_1()/10;
    int y=4*(nota1);
    pincel.setWidth(5);
    painter.setPen(pincel);
    painter.drawRect(x+820,400- y+50,100,+y);
    painter.drawText(860,160,QString::number(nota1*10)+" $");
    //Obtener datos para la segunda barra
    float nota2 = Di.promedio()/10;
    int y2=4*(nota2);
    pincel.setWidth(5);
    painter.setPen(pincel);
    painter.drawRect(x+400,400- y2+50,100,+y2);
    painter.drawText(440,160,QString::number(nota2*10)+" $");
}

void Pantalla_principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar reporte",
                                                         QDir::home().absolutePath() + "/reporte.png",
                                                         "Finanzas Familiares(*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information (this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

Pantalla_principal::~Pantalla_principal()
{
    delete ui;
}


void Pantalla_principal::on_pushButton_3_clicked()
{
    Agregar_miembro *ventana1= new Agregar_miembro;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}

void Pantalla_principal::on_actionSalir_triggered()
{
    close();
    Widget *ventana1= new Widget;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}

void Pantalla_principal::on_actionAcerca_de_triggered()
{
    // Crear un objeto del cuadro de diálogo
    Acerca *dialog = new Acerca(this);
    // Enviar datos a la otra ventana
    dialog->setVersion(VERSION);
    // Mostrar la venta en modo MODAL
    dialog->exec();
    // Luego de cerrar la ventana, se acceden a los datos de la misma
    qDebug() << dialog->valor();

}

void Pantalla_principal::on_actionMi_perfil_triggered()
{
    close();
    Mi_perfil *ventana1= new Mi_perfil;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}


void Pantalla_principal::on_pushButton_clicked()
{
    close();

    Dialog_ingresos *ventana1= new Dialog_ingresos;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}


void Pantalla_principal::on_pushButton_2_clicked()
{
    Dialog_reporte *ventana1 =new Dialog_reporte;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();


}


void Pantalla_principal::on_pushButton_4_clicked()
{
    close();
    Dialog_egresos *ventana1 = new Dialog_egresos;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();

}


void Pantalla_principal::on_actionEspanol_triggered()
{
    qApp->installTranslator(&translatorEs);

}


void Pantalla_principal::on_actionIngles_triggered()
{
    qApp->installTranslator(&translatorEn);
}


void Pantalla_principal::on_actionPortugues_triggered()
{
    qApp->installTranslator(&translatorPr);
}
