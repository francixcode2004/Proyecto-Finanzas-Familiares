#ifndef PANTALLA_PRINCIPAL_H
#define PANTALLA_PRINCIPAL_H

#include <QMainWindow>
#include <QTranslator>
#include <QDebug>
#include <iostream>
#define VERSION "0.2"
using namespace std;
namespace Ui {
class Pantalla_principal;
}

class Pantalla_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pantalla_principal(QWidget *parent = nullptr);

    ~Pantalla_principal();

private slots:


    void on_pushButton_3_clicked();

    void on_actionSalir_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionMi_perfil_triggered();

    void on_actionGuardar_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_actionEspanol_triggered();

    void on_actionIngles_triggered();

    void on_actionPortugues_triggered();


protected:
    void changeEvent(QEvent*);
    void paintEvent(QPaintEvent* event)override;

private:
    Ui::Pantalla_principal *ui;
    QString usuario1;
    QPixmap lienzo;
    QTranslator translatorEs;
    QTranslator translatorEn;
    QTranslator translatorPr;
    void dibujar();
};

#endif // PANTALLA_PRINCIPAL_H
