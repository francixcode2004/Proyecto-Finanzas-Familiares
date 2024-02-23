#include "miembro_f.h"

Miembro_f::Miembro_f(QObject *parent)
    : QObject{parent}
{

}

Miembro_f::Miembro_f(const QString &rol, const QString &nombre, const QString &apellido, const QString &edad):
    m_rol(rol),
    m_nombre(nombre),
    m_apellido(apellido),
    m_edad(edad)
{}

const QString &Miembro_f::rol() const
{
    return m_rol;
}

const QString &Miembro_f::nombre() const
{
    return m_nombre;
}

const QString &Miembro_f::apellido() const
{
    return m_apellido;
}

const QString &Miembro_f::edad() const
{
    return m_edad;
}





