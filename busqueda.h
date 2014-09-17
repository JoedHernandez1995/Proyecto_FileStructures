#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <QDialog>
#include "campo.h"

namespace Ui {
class busqueda;
}

class busqueda : public QDialog
{
    Q_OBJECT

public:

    int numeroDeCampo;
    QList<QString> resultadoFinal;

    QList <QString> getResultadoFinal();

    explicit busqueda(QWidget *parent = 0, QString fields="", QString types="", QString keyTypes="");
    ~busqueda();

private slots:
    QList<QString> on_pushButton_clicked();

    void on_cb_busqueda_currentIndexChanged(int index);

private:
    Ui::busqueda *ui;
};

#endif // BUSQUEDA_H
