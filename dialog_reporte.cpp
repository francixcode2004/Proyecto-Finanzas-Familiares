#include "dialog_reporte.h"
#include "ui_dialog_reporte.h"
#include "dialog_egresos.h"
#include "dialog_ingresos.h"

Dialog_reporte::Dialog_reporte(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::Dialog_reporte)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();
    ui->outCuadro->setPixmap(lienzo);
    lienzo_1 = QPixmap(500,500);
    this->dibujar_1();
    ui->outCuadro_1->setPixmap(lienzo_1);

}


Dialog_reporte::~Dialog_reporte()
{
    delete ui;
}

void Dialog_reporte::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
    ui->outCuadro_1->setPixmap(lienzo_1);
}

void Dialog_reporte::dibujar()
{
    Dialog_egresos De;
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

    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);

    //Obtener datos para la primera barra
    float nota1 = De.promedio_1()/10;
    int y=this->getAlto(nota1);
    pincel.setWidth(5);
    painter.setPen(pincel);
    painter.drawRect(x+200,400- y+50,100,+y);
    promedio = De.promedio_1();
    ui->outEgre->setText("TOTAL EGRESO $"+ QString::number(promedio));
}

void Dialog_reporte::dibujar_1()
{
    Dialog_ingresos DI;
     QColor CFondo(203, 255, 199);
    lienzo_1.fill(CFondo);

    QPainter painter(&lienzo_1);

    ui->outIngre->setText("TOTAL INGRESO $"+ QString::number(DI.promedio()));
    ui->inPromedio->setText("               "+ QString::number(DI.promedio()-promedio));
    int x = 0;

    //Barra 1
    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    //pincel.setColor(Qt::green);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Crear un objeto color para el relleno
    QColor colorRelleno1(90,120,162);
    // Crear otro objeto color para el borde
    // Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);
    //Obtener datos para la primera barra
    nota4 = DI.promedio()/10;
    int y=this->getAlto(nota4);

    painter.drawRect(x+200,400- y+50,100,+y);



}

float Dialog_reporte::promediar(float a,float b, float c){
 return a + b + c;
}

int Dialog_reporte::getAlto(int valor)
{
    return 4*valor;
}


void Dialog_reporte::on_pushButton_clicked()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                             "Guardar imagen",
                                                             QString(),
                                                             "Imágenes .png (*.png)");
    QString nombreArchivo_1 = QFileDialog::getSaveFileName(this,
                                                             "Guardar imagen",
                                                             QString(),
                                                             "Imágenes .png (*.png)");
        // Validar que el nombre del archivo no sea vacío
        if ( !nombreArchivo.isEmpty() ){
            // Guardar imagen
            if (lienzo.save(nombreArchivo)){
                // Si todo va bien, muestra un mensaje de información
                QMessageBox::information(this,
                                         "Guardar imagen",
                                         "Archivo almacenado en: " + nombreArchivo);
            } else{
                // Si hay algún error, muestro advertencia
                QMessageBox::warning(this,
                                     "Guardar imagen",
                                     "No se pudo almacenar la imagen.");
            }
            if (lienzo_1.save(nombreArchivo_1)){
                // Si todo va bien, muestra un mensaje de información
                QMessageBox::information(this,
                                         "Guardar imagen",
                                         "Archivo almacenado en: " + nombreArchivo);
            } else{
                // Si hay algún error, muestro advertencia
                QMessageBox::warning(this,
                                     "Guardar imagen",
                                     "No se pudo almacenar la imagen.");
            }
        }
}

