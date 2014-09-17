#include "busqueda.h"
#include "ui_busqueda.h"
#include "campo.h"
#include <QFile>
#include <QTextStream>

busqueda::busqueda(QWidget *parent, QString fields, QString types,QString keyTypes) :
    QDialog(parent),
    ui(new Ui::busqueda)
{
    ui->setupUi(this);

    ui->lb_info->setVisible(false);

    keyTypes+="1";

    QList <QString> campos=fields.split(',');
    QList <QString> tipos=types.split(',');

    for(int i=0;i<campos.size();i++){
        ui->cb_busqueda->addItem(campos.at(i)+" ("+tipos.at(i)+")");
    }//fin recorrido de la lista de campos
}

busqueda::~busqueda()
{
    delete ui;
}

QList<QString> busqueda::on_pushButton_clicked()
{

    ui->lb_info->setVisible(true);
    //este es el boton de busqueda

    numeroDeCampo=ui->cb_busqueda->currentIndex();
    QString query=ui->lb_busqueda->text();

    cout<<"11"<<endl;

    QFile indice("./indice.txt");
    QFile resultado("./resultadosIndices.txt");

    cout<<"22"<<endl;

    QString buscado=ui->cb_busqueda->currentText();
    QList <QString>lista=buscado.split('(');

    cout<<"IMPRESION DE LISTA: "<<endl;
    for(int i=0;i<lista.size();i++){
        cout<<lista.at(i).toStdString()+',';
    }

    cout<<endl;

    if(lista.at(1)=="Integer)"||lista.at(1)=="Double)"){//busqueda de un numero
        QString numero=ui->sb_busqueda->text();

        cout<<"33"<<endl;

        indice.open(QIODevice::ReadOnly);
        resultado.open(QIODevice::WriteOnly);

        //*************inicio busqueda en archivo***********//
        QTextStream in(&indice);

        while(!in.atEnd()){
            QString line=in.readLine();
            QList<QString> lista=line.split('\t');

            cout<<"IMPRESION DE LINEA DEL ARCHIVO DE INDICE: "<<endl;
            for(int i=0;i<lista.size();i++){
                cout<<lista.at(i).toStdString()+',';
            }
            cout<<endl;

            cout<<"44"<<endl;

            if(lista.at(numeroDeCampo)==numero){
                resultadoFinal.append(line+'\n');
                cout<<"se encontro el resultado"<<endl;
            }

        }//fin recorrido de archivo

        //*************fin busqueda en archivo***********//

        indice.close();
        resultado.close();

    }else{//busqueda de un string

        QString query=ui->lb_busqueda->text();

        indice.open(QIODevice::ReadOnly);
        resultado.open(QIODevice::WriteOnly|QIODevice::Append);

        cout<<"55"<<endl;

        //*************inicio busqueda en archivo***********//
        QTextStream in(&indice);

        while(!in.atEnd()){
            QString line=in.readLine();
            QList<QString> lista=line.split('\t');

            cout<<"66"<<endl;

            if(lista.at(numeroDeCampo)==query){
                resultadoFinal.append(line+'\n');
            }

        }//fin recorrido de archivo

        //*************fin busqueda en archivo***********//

    }//fin if else

    indice.close();
    resultado.close();

    return resultadoFinal;

}

void busqueda::on_cb_busqueda_currentIndexChanged(int index)
{
    QString mensaje=ui->cb_busqueda->currentText();
    QList <QString> lista=mensaje.split('(');

    int numero=index;
    numero+=1;

    if(lista.at(1)=="Integer)"||lista.at(1)=="Double)"){
        ui->lb_busqueda->setVisible(false);
        ui->sb_busqueda->setVisible(true);
    }else{
        ui->lb_busqueda->setVisible(true);
        ui->sb_busqueda->setVisible(false);
    }//fin if

}//fin de la funcion

QList <QString> busqueda::getResultadoFinal(){
    return resultadoFinal;


}
