#ifndef INGRESAR_H
#define INGRESAR_H

#include <QDialog>

namespace Ui {
class Ingresar;
}

class Ingresar : public QDialog
{
    Q_OBJECT

public:
    explicit Ingresar(QWidget *parent = nullptr);
    ~Ingresar();

private:
    Ui::Ingresar *ui;
};

#endif // INGRESAR_H
