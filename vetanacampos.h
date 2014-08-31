#ifndef VETANACAMPOS_H
#define VETANACAMPOS_H

#include <QDialog>
#include "QString"
#include "campo.h"

namespace Ui {
class vetanaCampos;
}

class vetanaCampos : public QDialog
{
    Q_OBJECT

public:
    explicit vetanaCampos(QWidget *parent = 0,int=1);
    ~vetanaCampos();

    //getFieldCount();

    QString getNombre();
    QString getTipo();
    int getLength();
    bool getKey();
    void setCampo(Campo);
    Campo getCampo();
    void setI(int);
    int getI();
    QList<Campo> getListaCampos();

    void addCampo (Campo);

private slots:

    void on_btnAgregar_clicked();

private:
    Ui::vetanaCampos *ui;
    int fieldCount;
    Campo campo1;
    int i;
    QList<Campo> camposPorAgregar;
};

#endif // VETANACAMPOS_H
