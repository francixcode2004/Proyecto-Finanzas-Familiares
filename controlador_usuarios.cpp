#include "controlador_usuarios.h"

Controlador_usuarios::Controlador_usuarios(QObject *parent)
    : QObject{parent}
{

}

Controlador_usuarios::Controlador_usuarios(const QString &usuario, const QString &contrasena):
    m_usuario(usuario),
    m_contrasena(contrasena)

{


}

const QString &Controlador_usuarios::usuario() const
{
    return m_usuario;
}

const QString &Controlador_usuarios::contrasena() const
{
    return m_contrasena;
}
