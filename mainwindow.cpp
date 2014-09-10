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
#include <ostream>
#include <istream>

using namespace std;

QFile archivo("./archivo.txt");
QFile archivoComp("./Compactado.txt");
QFile archivorrn("./RRN.txt");
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

  //QFile archivo("archivo.txt");

  QString text = QInputDialog::getText(this, tr("Nombre del Archivo"),tr("Ingrese el nombre:"), QLineEdit::Normal,"", &ok);  

  //archivo.rename(text);

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
//registerLength+=delimitadoresPorAgregar;

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

                        setFixedLength(numero,estructura.at(i).getLength());

            for(int i=0;i<numero.size();i++){
                tamanioEntrada++;

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

    /*
     *Utilizar tokens para escribir registro por registro , ignorando todos aquellos que no tengan el caracter de omision al inicio
     *imprimir en tabla
     */
    ui->tablaLista->setColumnCount(estructura.size());
    for(int i = 0; i < estructura.size(); i++){
        ui->tablaLista->setHorizontalHeaderItem(i,new QTableWidgetItem(estructura.at(i).getname()));
    }

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

    QTextStream browser(&archivo);

    ui->browserImpresion->setText(browser.readAll());

    archivo.close();

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text))
        return;
    QTextStream in(&archivo);


    while(!in.atEnd()){
        QString line=in.readLine();
        //**************************************************************//

        QList<QString>arregloCamposLeidos=line.split(",");

        cout<<line.toStdString()<<endl;
       // cout<<"TAMAÑO:"<<arregloCamposLeidos.size()<<endl;

      //  cout<<"Primer caracter: "<<arregloCamposLeidos.at(0)[0]<<endl
    if(arregloCamposLeidos.at(0)[0]!='&'){//si el registro no esta marcado como borrado ...

        //***************** ***Agregado a Tabla********************//
        cout<<"Numero inicial de rows: "<<ui->tablaLista->rowCount()<<endl;

        int row=ui->tablaLista->rowCount();
        //bool endOfRecord=false;
        int recordSize=0;

            for(int i=0;i<arregloCamposLeidos.size()-1;i++){
                cout<<"Se insertaria "<<arregloCamposLeidos.at(i).toStdString()<<" en la fila"<<row<<" y en la columna "<<i<<endl;
                //if(ui->tablaLista->rowCount()==0)
                //ui->tablaLista->insertRow(row);

                QTableWidgetItem* item= new QTableWidgetItem();
                item->setText("hola");
                ui->tablaLista->setItem(row,i,item);
                recordSize++;

                if(recordSize==arregloCamposLeidos.size()-1){
                    cout<<"add plus 1"<<endl;
                    ui->tablaLista->insertRow(row);
                    cout<<"ahora hay "<<ui->tablaLista->rowCount()<<" filas"<<endl;
                    recordSize=0;
                }


            }//fin for recorrido de arreglo

        //*****************Fin de Agregado a Tabla**********************//

        }//fin de agregado de registros que no han sido marcados como borrados

    }//fin recorrido del archivo

    archivo.close();
}//fin de la funcion listado de registros en un archivo

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

   // int rrn=ui->tablaLista->currentRow();

    //cout<<"hola"<<endl;


    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

   // cout<<"hola2"<<endl;
    int numberOfLines=0;

    QTextStream in(&archivo);
    QTextStream out(&archivo);


    while(!in.atEnd()){
        //cout<<"hola3"<<endl;

        QString line=in.readLine();
        numberOfLines++;
        cout<<"se ha sumado uno a las filas"<<endl;

        if(3==numberOfLines){
            cout<<"se ha llegado a la mera linea"<<endl;
            cout<<line.toStdString()<<endl;
            QString tempLine="";
            for(int i=0;i<line.size();i++){
                tempLine+="&";
            }
            cout<<tempLine.toStdString()<<endl;
            out<<tempLine;
        }

    }//fin while mientras no termine el archivo

    archivo.close();

}

void MainWindow::setFixedLength(QString &texto, int size){

    //QFile archivo("./archivo.txt");

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

   // QFile archivo("./archivo.txt");

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

void MainWindow::on_actionCompactar_triggered()
{
    //opcion de compactacion
    //QFile archivoComp("./Compactado.txt");

    if(!archivoComp.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
        return;

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

    QTextStream in(&archivo);
    QTextStream out(&archivoComp);

    while(!in.atEnd()){
       QString line=in.readLine();
       //cout<<line.toStdString()<<endl;
       if(line.at(0)!='&'){
           //cout<<"es escribe "<<line.toStdString()<<" al archivo"<<endl;
           out<<line<<'\n';

       }//fin si el registro no esta marcado


    }//end of file

    archivoComp.close();
    archivo.close();

}//end of function
