#include "controlador_administrador.h"
#include <QMessageBox>
#include <QWidget>
#include "pantalla_administrador.h"

Controlador_administrador::Controlador_administrador(QObject *parent)
    : QObject{parent}
{

}


void Controlador_administrador::login(QString datos)
{

    bool encontrado = false;
    QStringList usuariosIn = datos.split(";");
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream salida(&archivo);

        while(!salida.atEnd()){
            QString lineaArch = salida.readLine();
            QStringList usuariosArch = lineaArch.split(";");
            if(usuariosIn == usuariosArch){
                encontrado = true;
            }
        }

        archivo.close();
        if (encontrado){
            qDebug() << "Usuario Registrado";



                Pantalla_administrador *ventana1 = new Pantalla_administrador;
                ventana1->setWindowModality(Qt::ApplicationModal);
                ventana1->show();


        } else {
            qDebug() << "Usuario No Registrado";



        }

    }else{
        qDebug() << "No se pudo abrir el archivo";
    }
}

bool Controlador_administrador::registrarse(QString verificacion, QString nuevoUsuario)
{
    QStringList contras = verificacion.split(";");
    if(!(contras[0] == contras[1])){
        return 0;
    } else {
        QFile archivo(ARCHIVO);
        if (archivo.open(QFile::Append)) {
            QTextStream salida(&archivo);
            salida << nuevoUsuario << "\n";
            archivo.close();

            return 1;
        }
    }
}
