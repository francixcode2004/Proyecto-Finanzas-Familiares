#include "controlador_egresos.h"


Controlador_egresos::Controlador_egresos(QObject *parent)
    : QObject{parent}
{

}

Controlador_egresos::Controlador_egresos(const QString &monto, const QString &fecha, const QString &rol, const QString &categoria, const QString &descripcion):
    m_monto(monto),
    m_fecha(fecha),
    m_rol(rol),
    m_categoria(categoria),
    m_descripcion(descripcion)
{

}

const QString &Controlador_egresos::monto() const
{
    return m_monto;
}

const QString &Controlador_egresos::fecha() const
{
    return m_fecha;
}

const QString &Controlador_egresos::rol() const
{
    return m_rol;
}

const QString &Controlador_egresos::categoria() const
{
    return m_categoria;
}

const QString &Controlador_egresos::descripcion() const
{
    return m_descripcion;
}
