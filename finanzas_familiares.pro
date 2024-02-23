QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = Qt-Linguist
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aggusuarios.cpp \
    controlador_administrador.cpp \
    controlador_ingresos.cpp \
    controlador_egresos.cpp \
    controlador_usuarios.cpp \
    dialog_administrador.cpp \
    dialog_aggin.cpp \
    dialog_aggusu.cpp \
    dialog_ingresos.cpp \
    dialog_aggegre.cpp \
    dialog_egresos.cpp \
    dialog_reporte.cpp \
    main.cpp \
    pantalla_administrador.cpp \
    pantalla_principal.cpp \
    register.cpp \
    acerca.cpp \
    agregar_miembro.cpp \
    dialog_miembro.cpp \
    mi_perfil.cpp \
    miembro_f.cpp \
    register_administrador.cpp \
    usuario.cpp \
    usuarios.cpp \
    widget.cpp

HEADERS += \
    aggusuarios.h \
    controlador_administrador.h \
    controlador_ingresos.h \
    controlador_egresos.h \
    controlador_usuarios.h \
    dialog_administrador.h \
    dialog_aggin.h \
    dialog_aggusu.h \
    dialog_ingresos.h \
    dialog_aggegre.h \
    dialog_egresos.h \
    dialog_reporte.h \
    pantalla_administrador.h \
    pantalla_principal.h \
    register.h \
    acerca.h \
    agregar_miembro.h \
    dialog_miembro.h \
    mi_perfil.h \
    miembro_f.h \
    register_administrador.h \
    usuario.h \
    usuarios.h \
    widget.h

FORMS += \
    aggusuarios.ui \
    dialog_administrador.ui \
    dialog_aggin.ui \
    dialog_aggusu.ui \
    dialog_ingresos.ui \
    dialog_aggegre.ui \
    dialog_egresos.ui \
    dialog_reporte.ui \
    pantalla_administrador.ui \
    pantalla_principal.ui \
    register.ui \
    acerca.ui \
    agregar_miembro.ui \
    dialog_miembro.ui \
    mi_perfil.ui \
    register_administrador.ui \
    usuarios.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Idioms.qrc \
    icons.qrc \
    images.qrc

DISTFILES +=
