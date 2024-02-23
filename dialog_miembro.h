#ifndef DIALOG_MIEMBRO_H
#define DIALOG_MIEMBRO_H

#include <QDialog>
#include <QMessageBox>
#include"miembro_f.h"

namespace Ui {
class Dialog_miembro;
}

class Dialog_miembro : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_miembro(QWidget *parent = nullptr);
    Miembro_f *miembro()const;
    ~Dialog_miembro();

private slots:

    void on_btnguardar_clicked();

    void on_btncancel_clicked();

private:
    Ui::Dialog_miembro *ui;
    Miembro_f *m_miembro;
};

#endif // DIALOG_MIEMBRO_H
