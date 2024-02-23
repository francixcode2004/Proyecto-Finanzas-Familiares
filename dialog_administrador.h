#ifndef DIALOG_ADMINISTRADOR_H
#define DIALOG_ADMINISTRADOR_H


#include <QMainWindow>
#include <QTranslator>
#include <QDebug>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog_administrador; }
QT_END_NAMESPACE

class Dialog_administrador : public QDialog
{
    Q_OBJECT

public:
    Dialog_administrador(QWidget *parent = nullptr);
    ~Dialog_administrador();
    QString user();

private slots:
    void on_btn_ini_clicked();
    void on_btn_regis_clicked();

private:
    Ui::Dialog_administrador *ui;

};
#endif // DIALOG_ADMINISTRADOR_H
