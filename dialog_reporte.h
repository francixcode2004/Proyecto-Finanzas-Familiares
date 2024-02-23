#ifndef DIALOG_REPORTE_H
#define DIALOG_REPORTE_H

#include <QDialog>
#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class Dialog_reporte;
}

class Dialog_reporte : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_reporte(QWidget *parent = nullptr);

    ~Dialog_reporte();
    float promedio=0;
    int nota1=0,nota2=0,nota3=0,nota4=0,nota5=0,nota6=0;
protected:
    void paintEvent(QPaintEvent* event)override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_reporte *ui;
    QPixmap lienzo;
    QPixmap lienzo_1;
    const QString ARCHIVO = "egresos.csv";
    const QString ARCHIVO_1 = "ingresos.csv";
    void dibujar();
    void dibujar_1();
    float promediar(float a, float b, float c);
    int getAlto (int valor);
    void cargar();
};

#endif // DIALOG_REPORTE_H
