#ifndef CONTROLADOR_ADMINISTRADOR_H
#define CONTROLADOR_ADMINISTRADOR_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QTableWidgetItem>

class Controlador_administrador : public QObject
{
    Q_OBJECT

public:
    explicit Controlador_administrador(QObject *parent = nullptr);
    void login(QString datos);
    bool registrarse(QString verificacion, QString nuevoUsuario);

private:
    const QString ARCHIVO = "administradores.csv";

signals:

};

#endif // CONTROLADOR_ADMINISTRADOR_H
