#ifndef CONTROLADOR_EGRESOS_H
#define CONTROLADOR_EGRESOS_H

#include <QObject>
#include<string>

class Controlador_egresos: public QObject
{
    Q_OBJECT
public:
    explicit Controlador_egresos(QObject *parent = nullptr);
    Controlador_egresos(const QString &monto,const QString &fecha,const QString &rol,const QString &categoria,const QString &descripcion);
    const QString &monto()const;
    const QString &fecha()const;
    const QString &rol()const;
    const QString &categoria()const;
    const QString &descripcion()const;
signals:

private:
    QString m_monto;
    QString m_fecha;
    QString m_rol;
    QString m_categoria;
    QString m_descripcion;
};

#endif // CONTROLADOR_EGRESOS_H
