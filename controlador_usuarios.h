#ifndef CONTROLADOR_USUARIOS_H
#define CONTROLADOR_USUARIOS_H

#include <QObject>
#include<string>

class Controlador_usuarios: public QObject
{
public:
    explicit Controlador_usuarios(QObject *parent = nullptr);
    Controlador_usuarios(const QString &usuario, const QString &contrasena);
    const QString &usuario()const;
    const QString &contrasena()const;
signals:

private:
    QString m_usuario;
    QString m_contrasena;

};

#endif // CONTROLADOR_USUARIOS_H
