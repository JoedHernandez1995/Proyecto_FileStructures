#include "vetanacampos.h"
#include "ui_vetanacampos.h"
#include <iostream>

using namespace std;

vetanaCampos::vetanaCampos(QWidget *parent, int numeroCampos) :
    QDialog(parent),
    ui(new Ui::vetanaCampos)
{
    ui->setupUi(this);
    i=0;

    fieldCount=numeroCampos;

}

vetanaCampos::~vetanaCampos()
{
    delete ui;
}

QString vetanaCampos::getNombre(){
    return ui->lineaNombre->text();
}

QString vetanaCampos::getTipo(){
    return ui->comboTipo->itemText(ui->comboTipo->currentIndex());
}

int vetanaCampos::getLength(){
    return ui->spinnerLength->value();
}

bool vetanaCampos::getKey(){
    return ui->radioPrimaria->isChecked();
}
void vetanaCampos::setCampo(Campo camp){
    this->campo1 = camp;
}

Campo vetanaCampos::getCampo(){
    return campo1;
}

void vetanaCampos::setI(int j){
    i = j;
}

int vetanaCampos::getI(){
    return i;
}

int getFieldCount(){
    //return fieldCount;
}

void vetanaCampos::on_btnAgregar_clicked()
{
    campo1.setName(ui->lineaNombre->text());
    campo1.setType(ui->comboTipo->itemText(ui->comboTipo->currentIndex()));
    campo1.setLength(ui->spinnerLength->value());
    campo1.setKey(ui->radioPrimaria->isChecked());
    i++;

    //enviar el campo al registro
    this->camposPorAgregar.append(campo1);
    cout<<"agregado a lista";
    cout<<"tamaño: "<<camposPorAgregar.size()<<endl;

    ui->lineaNombre->setText("");
    ui->comboTipo->itemText(0);
    ui->spinnerLength->setValue(0);
    ui->radioPrimaria->setChecked(false);


    if(i==fieldCount){
        this->setEnabled(false);
        cout<<"Ha llegado al limite de campos!"<<" ("<<(fieldCount)<<" campos.)"<<endl;
        this->setVisible(false);


    }

}

QList<Campo> vetanaCampos::getListaCampos(){
    return camposPorAgregar;
}

void vetanaCampos::addCampo(Campo campo){
    camposPorAgregar.append(campo);
}
