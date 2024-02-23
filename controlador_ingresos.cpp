#include "controlador_ingresos.h"


Controlador_ingresos::Controlador_ingresos(QObject *parent)
    : QObject{parent}
{

}

Controlador_ingresos::Controlador_ingresos(const QString &monto, const QString &fecha, const QString &rol, const QString &categoria, const QString &descripcion):
    m_monto(monto),
    m_fecha(fecha),
    m_rol(rol),
    m_categoria(categoria),
    m_descripcion(descripcion)
{

}

const QString &Controlador_ingresos::monto() const
{
    return m_monto;
}

const QString &Controlador_ingresos::fecha() const
{
    return m_fecha;
}

const QString &Controlador_ingresos::rol() const
{
    return m_rol;
}

const QString &Controlador_ingresos::categoria() const
{
    return m_categoria;
}

const QString &Controlador_ingresos::descripcion() const
{
    return m_descripcion;
}
