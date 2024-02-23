#ifndef AGGUSUARIOS_H
#define AGGUSUARIOS_H

#include <QDialog>

namespace Ui {
class Aggusuarios;
}

class Aggusuarios : public QDialog
{
    Q_OBJECT

public:
    explicit Aggusuarios(QWidget *parent = nullptr);
    ~Aggusuarios();

private:
    Ui::Aggusuarios *ui;
};

#endif // AGGUSUARIOS_H
