#ifndef USUARIO_H
#define USUARIO_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <pantalla_principal.h>
#include <ui_pantalla_principal.h>

class Usuario : public QObject
{
    Q_OBJECT
public:
    explicit Usuario(QObject *parent = nullptr);
    void login(QString datos);
    bool registrarse(QString verificacion, QString nuevoUsuario);

private:
    const QString ARCHIVO = "usuarios.csv";

signals:

};

#endif // USUARIO_H
