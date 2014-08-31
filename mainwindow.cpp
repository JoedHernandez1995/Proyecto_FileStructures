#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QInputDialog"
#include "vetanacampos.h"
#include "campo.h"
#include "registro.h"
#include "QList"
#include "QString"
#include "iostream"
#include <QFile>
#include <QTextStream>

using namespace std;

QFile archivo("./archivo.txt");
int registerLength=0;
QList <Campo> estructura;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tablaEstructura->setColumnCount(4);
    ui->tablaEstructura->setHorizontalHeaderItem(0,new QTableWidgetItem("Nombre"));
    ui->tablaEstructura->setHorizontalHeaderItem(1,new QTableWidgetItem("Tipo"));
    ui->tablaEstructura->setHorizontalHeaderItem(2,new QTableWidgetItem("Length"));
    ui->tablaEstructura->setHorizontalHeaderItem(3,new QTableWidgetItem("Llave Primaria"));
    archivo.setFileName("archivo.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
    //delete window;
}

void MainWindow::on_actionNuevo_Archivo_triggered()
{
  bool ok;

  QFile archivo("archivo.txt");

  QString text = QInputDialog::getText(this, tr("Nombre del Archivo"),tr("Ingrese el nombre:"), QLineEdit::Normal,"", &ok);  

  archivo.rename(text);

  int num = QInputDialog::getInt(this,tr("Numero de Campos"),tr("Ingrese el numero de campos"),1,1,2147483647,1,&ok,0);

 //vetanaCampos* window = new vetanaCampos(this,num);
 //window->show();
  vetanaCampos ventana(0,num);
  ventana.setModal(true);
  ventana.exec();

  QList<Campo> campos=ventana.getListaCampos();
  estructura=campos;
Registro registro;
registro.setListaCampos(ventana.getListaCampos());
cout<<"{";

int delimitadoresPorAgregar=0;

for(int i=0;i<registro.getLista().size();i++){
    cout<<"elemento numero: "<<i<<endl;
    registerLength+=(int)registro.getLista().at(i).getLength();
    delimitadoresPorAgregar++;
}
 delimitadoresPorAgregar++;//se agrega el delitadr de nueva linea
registerLength+=delimitadoresPorAgregar;

cout<<"}"<<endl;


}

void MainWindow::on_actionAgregar_triggered()
{

    QString registroEnviado;
    QString text;
    int num;
    //double numeroReal;
    bool ok;

    for(int i=0;i<estructura.size();i++){
        if(estructura.at(i).getType()=="Char"||estructura.at(i).getType()=="String"){

           text = QInputDialog::getText(this,(estructura.at(i).getname()),("Ingrese "+estructura.at(i).getname()),  QLineEdit::Normal,"", &ok);

            setFixedLength(text,estructura.at(i).getLength());

        }//fin si es de tipo cadena o caracter

            if(estructura.at(i).getType()=="Integer"||estructura.at(i).getType()=="Double"){
            num = QInputDialog::getInt(this,(estructura.at(i).getname()),("Ingrese "+estructura.at(i).getname()),1,1,2147483647,1,&ok,0);

            int tamanioEntrada=0;
            QString numero=QString::number(num);
            for(int i=0;i<numero.size();i++){
                tamanioEntrada++;

            setFixedLength(num,tamanioEntrada,estructura.at(i).getLength());
            }//fin for
        }//fin  si es entero o real

}//fin recorrido de la estructura
    registroEnviado+="\n";

    if(archivo.exists())
        cout<<"existe!"<<endl;
    else{

    }

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
        return;

    cout<<"abrio"<<endl;

    QTextStream in(&archivo);
    QTextStream out(&archivo);

   // while(!in.atEnd()){
       QString line=in.readLine();
       int availListHead=line.toInt();
       cout<<"avail:"<<availListHead<<endl;
       //QString availString=QString::number(availListHead);

       if(availListHead==-1){
           cout<<"Archivo vacio!"<<endl;
       }else{
           cout<<"El archivo contiene datos!"<<endl;
           //archivo.seek((availListHead-1)*registerLength)
           //out<<registroEnviado;
           cout<<"se escribio"<<endl;
       }//fin else por si el archivo NO esta vacio


       out<<'\n';

       archivo.close();

}



void MainWindow::on_actionListar_triggered()
{
    if(!archivo.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
        return;
    QTextStream out(&archivo);
    out<<"hello2\n";
    cout<<"hello";
    archivo.close();
}

void MainWindow::on_actionVer_Archivo_triggered()
{
    ui->tablaEstructura->setRowCount(estructura.length());
    for(int i = 0; i < estructura.length(); i++){
        QString name = estructura.at(i).getname();
        QString type = estructura.at(i).getType();
        int length = estructura.at(i).getLength();
        bool llave = estructura.at(i).IsKey();
        QString key;
        if(llave){
            key = "SI";
        }else{
            key = "NO";
        }
        ui->tablaEstructura->setItem(i,0,new QTableWidgetItem(name));
        ui->tablaEstructura->setItem(i,1,new QTableWidgetItem(type));
        ui->tablaEstructura->setItem(i,2,new QTableWidgetItem(QString::number(length)));
        ui->tablaEstructura->setItem(i,3,new QTableWidgetItem(key));
    }
}

void MainWindow::on_actionBorrar_triggered()
{
    //borrar un registro del arhivo
    /*
     *
     *abrimos archivo
     *
     *nos valdremos de  la impresion bonita de los registros en una tabla. Con la tabla, obtendremos el indice del registro
     *dentro del arhivo, su RRN.
     *
     *Con esto, usamos  la formula (availList-1)*registerLength para ir a este punto en el archivo, y en el caracter [0] pondremos & y en
     *los caracteres [1][2][3][4][5] pondremos el indice obtenido por la tabla, rellenado por 0`s. (00001), (00010)
     *
     *cerramos archivo
     */
}

void MainWindow::setFixedLength(QString &texto, int size){

    QFile archivo("./archivo.txt");

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
            return;

        QTextStream in(&archivo);
        QTextStream out(&archivo);

    //validar si tiene menos que el limite

          if(texto.size()<size){
              for (int i=texto.size();i<size;i++){
                  texto.append('-');
              }//fin del recorrido de la cadena
              out<<texto<<',';
          }//fin relleno de registro si es de menor longitud al limite

          QString newText="";

                 if(texto.size()>size){
                     for(int i=0;i<size;i++){
                         newText.append(texto.at(i));
                     }
                     out<<newText+',';
                 }

      archivo.close();

}//fin de la funcion


void MainWindow::setFixedLength(int &numero,int numberSize,int limiteTamanio){//number size es el numero de digitos que ingreso el usuario en la dialog

    QFile archivo("./archivo.txt");

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
            return;

        QTextStream in(&archivo);
        QTextStream out(&archivo);

        QString texto="";
        texto=QString::number(numero);

    if(numberSize<limiteTamanio){
        for (int i=numberSize;i<limiteTamanio;i++){
            texto.append('-');
        }//fin del recorrido de la cadena
        out<<texto<<',';
    }//fin relleno de registro si es de menor longitud al limite

    QString numToText="";
    QString newText="";
    numToText=QString::number(numero);

           if(numberSize>limiteTamanio){
               for(int i=0;i<limiteTamanio;i++){
                   newText.append(numToText.at(i));
               }
               out<<newText<<',';
           }
    archivo.close();

}//fin de la funcion
