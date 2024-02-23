#ifndef MIEMBRO_F_H
#define MIEMBRO_F_H

#include <QObject>
#include<string>

class Miembro_f : public QObject
{
    Q_OBJECT
public:
    explicit Miembro_f(QObject *parent = nullptr);
    Miembro_f(const QString &rol , const QString &nombre, const QString &apellido, const QString &edad);
    const QString &rol()const;
    const QString &nombre() const;
    const QString &apellido() const;
    const QString &edad() const;

signals:

private:
    QString m_rol;
    QString m_nombre;
    QString m_apellido;
    QString m_edad;
};
#endif // MIEMBRO_F_H
