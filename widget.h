#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QTranslator>
#include <QDebug>
#include <ui_widget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    QString nombre ();
    ~Widget();
    QString user();

private slots:
    void on_btn_ini_clicked();
    void on_btn_regis_clicked();

    void on_Idiomas_currentIndexChanged(int index);


    void on_btn_admin_clicked();

protected:
    void changeEvent(QEvent*);


private:
    Ui::Widget *ui;
    QTranslator translatorEs;
    QTranslator translatorEn;
    QTranslator translatorPr;
};
#endif // WIDGET_H
