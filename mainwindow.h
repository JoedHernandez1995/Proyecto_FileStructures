#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "campo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNuevo_Archivo_triggered();

    void on_actionAgregar_triggered();

    void on_actionListar_triggered();

    void on_actionVer_Archivo_triggered();

    void on_actionBorrar_triggered();

    void setFixedLength(int&,int,int);
    void setFixedLength(QString &, int);
    void insertEndOfLine();
    void insertarEncabezadoBonito(QList<Campo> campos);
    void rellenarIndice(QList <Campo> estructura,QString tipo,QString campo,QList <QString> campos);

    void on_actionCompactar_triggered();

    void on_actionBuscar_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
