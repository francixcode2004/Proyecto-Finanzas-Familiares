#include "widget.h"
#include "ui_widget.h"
#include <pantalla_principal.h>
#include <QCoreApplication>
#include "dialog_administrador.h"
#include "usuario.h"
#include "register.h"
#include <QRegExp>

int iterador = 0;

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*
    QRegExp rxDescripcion(DESCRIPCION_RX);
    QRegExpValidator *validescrip =new QRegExpValidator(rxDescripcion,this);
    ui->Indescripcion->setValidator(validescrip);
    */;

    if(translatorEn.load(":/ingles.qm"))
        qDebug()<<"Traduccion cargada correctamente.";

    if(translatorPr.load(":/portugues.qm"))
        qDebug()<<"Traduccion cargada correctamente.";

    if(translatorEs.load(":/español.qm"))
        qDebug()<<"Traduccion cargada correctamente.";
}

void Widget::changeEvent(QEvent* event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::user()
{
    return ui->in_user->text() + ";" + ui->in_pass->text();
}

void Widget::on_btn_ini_clicked()
{
    QString email = ui->in_user->text();
    QRegExp emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if(ui->in_user->text().isEmpty() or !emailRegex.exactMatch(email) or ui->in_pass->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Por favor, ingrese un nombre de usuario o un correo valido.");
        return;

    }else{
        Usuario Usuario;
        Usuario.login(user());
        hide();
    }

}

void Widget::on_btn_regis_clicked()
{
    Register reg(this);
    reg.setWindowTitle("Registro de nuevo Usuario");
    int res = reg.exec();
    if (res == QDialog::Rejected){
        return;
    }
}



void Widget::on_Idiomas_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        qApp->installTranslator(&translatorEs);
        break;
    case 1:
        qApp->installTranslator(&translatorEn);
        break;
    case 2:
        qApp->installTranslator(&translatorPr);
        break;
    }
}




void Widget::on_btn_admin_clicked()
{
    close();
    Dialog_administrador *ventana1 = new Dialog_administrador;
    ventana1->setWindowModality(Qt::ApplicationModal);
    ventana1->show();
}

