#include "usuario.h"
#include <pantalla_principal.h>
#include "ui_pantalla_principal.h"
#include <QMessageBox>
#include <QWidget>

Usuario::Usuario(QObject *parent)
    : QObject{parent}
{

}



void Usuario::login(QString datos)
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


                Pantalla_principal *ventana1 = new Pantalla_principal;
                ventana1->setWindowModality(Qt::ApplicationModal);
                ventana1->showMaximized();


        } else {
            qDebug() << "Usuario No Registrado";



        }

    }else{
        qDebug() << "No se pudo abrir el archivo";
    }
}

bool Usuario::registrarse(QString verificacion, QString nuevoUsuario)
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
