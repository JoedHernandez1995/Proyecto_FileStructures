#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QInputDialog"
#include "vetanacampos.h"
#include "campo.h"
#include "registro.h"
#include "busqueda.h"
#include "QList"
#include "QString"
#include "iostream"
#include <QFile>
#include <QTextStream>
#include <ostream>
#include <istream>
#include <QtCore>
#include <QObject>
#include <QTemporaryFile>

using namespace std;

/*
 *Hecho por Horacio Galdamez y Jose Hernandez
 *
 *Proyecto de Organizacion de Archivos
 *Este proyecto se vale de archivos de texto principalmente para poder guardar, agregar, buscar
 *y eliminar registros, implementando:
 *
 *AvailList
 *Indices
 *Arbol B
 */

QFile archivo("./archivo.txt");//el archivo donde se guardaran los registros
QFile archivoComp("./Compactado.txt");//el archivo nuevo en el que se escriben los registros no marcados
QFile archivorrn("./RRN.txt");//archivo donde se guardara el rrn del registro borrado mas reciente
QFile impBonita("./impBonita.txt");//archivo donde se guarda la "impresion bonita" del archivo.txt
QFile numeroRegistros("./numeroRegistros.txt");//archivo donde se guarda el numero de reigstro que se esta
                                                                                                  //agregando al archivo.txt, para no repetirse.
QFile indice("./indice.txt");//archivo donde se guardan los registros con su llave primaria
QFile resultados("./resultadosIndices.txt");//archivo donde se guardan los resultados de la busqueda del indice
int registerLength=0;//longitud del registro
QList <Campo> estructura;//lista de campos que forman la estructura de todo el archivo

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //creacion de la tabla que desplega la estructura que creo el usuario
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
}

void MainWindow::on_actionNuevo_Archivo_triggered()
{

    //opcion de crear una nueva estructura

  bool ok;//bandera requerida para la ventana de dialogo utilizada para que el usuario ingrese el campo


  QList <Campo> arregloDeEstructura;//representa la linea del encabezado del archivo de impresion bonita

  /*
   *A continuacion, se desplegan las ventanas de dialogo que ayudaran al usuario a crear la estructura
   *del archivo a su conveniencia.
   */

  QString text = QInputDialog::getText(this, tr("Nombre del Archivo"),tr("Ingrese el nombre:"), QLineEdit::Normal,"", &ok);  //desplegado de ventana de dialogo para que el usuario ingrese el nombre del archivo



  int num = QInputDialog::getInt(this,tr("Numero de Campos"),tr("Ingrese el numero de campos"),1,1,2147483647,1,&ok,0);//ventana de dialogo que pide el numero de campos que iran en la estructura

  vetanaCampos ventana(0,num);//creacion de la ventana que se desplega el numero de veces de campos
  ventana.setModal(true);//se valida que solo se pueda interactuar con esta ventana mientras este abierta
  ventana.exec();//se ejecuta la ventana

  QList<Campo> campos=ventana.getListaCampos();//arreglo de campos obtenidos de la ventana
  estructura=campos;//se le asigna la lista en memoria a otro arreglo
Registro registro;
registro.setListaCampos(ventana.getListaCampos());
cout<<"{";

arregloDeEstructura=campos;

int delimitadoresPorAgregar=0;

for(int i=0;i<registro.getLista().size();i++){
    cout<<"elemento numero: "<<i<<endl;
    registerLength+=(int)registro.getLista().at(i).getLength();
    delimitadoresPorAgregar++;
}
 delimitadoresPorAgregar++;//se agrega el delitadr de nueva linea


cout<<"}"<<endl;

insertarEncabezadoBonito(arregloDeEstructura);//metodo que esribe el encabezado de impresion bonita
                                                                                                  //en el encabezado del archivo

}

void MainWindow::on_actionAgregar_triggered()
{

    //metodo de agregar registro

    QString campoEnviarIndice;//campoEnviado al archivo de indices
    QString tipo;//tipo enviado al archivo del indice
         QString enviadoAIndice;//campo enviado al archivo de indice

    if(!numeroRegistros.open(QIODevice::ReadWrite))
        return;//se abre el archivo


    QTextStream escrituraDeRegistrosIN(&numeroRegistros);//lee cuantos registros existen en otro archivo de texto


    QString  temporal=escrituraDeRegistrosIN.readLine();//campo asignado a la linea del archivo leido

    int numeroActualDeRegistros=temporal.toInt()+1;//numero de registro escrito en el archivo de texto
    escrituraDeRegistrosIN.seek(0);//se ubica el file pointer en la linea cero del archivo
    escrituraDeRegistrosIN<<numeroActualDeRegistros;//se escribe el numero del archivo +1

    ///numeroDeRegistro=numeroActualEnString.at(temporal.size());


    numeroRegistros.close();//se cierra el archivo

    if(!impBonita.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
        return;//se abre el archivo

       QTextStream salidaBonita(&impBonita);

       salidaBonita<<numeroActualDeRegistros<<").-";//se escribe el numero de registro para saber su posicion

       impBonita.close();//se cierra el archivo


    QString registroEnviado;
    QString text;
    int num;
    //double numeroReal;
    bool ok;

    QList <QString> camposIndice;//campo enviadoal archivo de indice
    //estructura


    for(int i=0;i<estructura.size();i++){//se recorre la estructura, para conocer el tipo de cada campo en ella
        if(estructura.at(i).getType()=="Char"||estructura.at(i).getType()=="String"){//si el campo es caracter o cadena

           text = QInputDialog::getText(this,(estructura.at(i).getname()),("Ingrese "+estructura.at(i).getname()),  QLineEdit::Normal,"", &ok);//text es el texto que ingresa el usuario en la ventana

               setFixedLength(text,estructura.at(i).getLength());//metodo que valida que los todos los campos del archivo sean del mismo tamaño
               camposIndice.append(text);

               /*
                *rellenar otro qstring sin los ------ y enviar este qstring como parametro a la funcion de rellenado de indice
                **/


               //reescritura del campo, obviando los caracteres - que se utilizaron para rellenarlos
               for(int i=0;i<text.size();i++){
                   if(text.at(i)!='-'){
                       enviadoAIndice+=text.at(i);
                   }
               }

               cout<<"text NUEVO es: "<<enviadoAIndice.toStdString()<<endl;

        }//fin si es de tipo cadena o caracter

            if(estructura.at(i).getType()=="Integer"||estructura.at(i).getType()=="Double"){
            num = QInputDialog::getInt(this,(estructura.at(i).getname()),("Ingrese "+estructura.at(i).getname()),1,1,2147483647,1,&ok,0);//si el campo es de tipo interger o double


            int tamanioEntrada=0;
            QString numero=QString::number(num);//numero que el usuario ingreso
             camposIndice.append(QString::number(num));//campo enviado al indice
             setFixedLength(numero,estructura.at(i).getLength());//metodo que estandariza el tamaño del campo

             campoEnviarIndice=enviadoAIndice;//campo enviado al archivo de indice

             if(estructura.at(i).IsKey())//si ese campo es llave primaria
                tipo=estructura.at(i).getType();//se obtiene el tipo


            for(int i=0;i<numero.size();i++){
                tamanioEntrada++;

            }//fin for


        }//fin  si es entero o real

            if(i==estructura.size()-1)
                insertEndOfLine();

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


       QString line=in.readLine();
       int availListHead=line.toInt();
       cout<<"avail:"<<availListHead<<endl;

       if(availListHead==-1){
           cout<<"Archivo vacio!"<<endl;
       }else{
           cout<<"El archivo contiene datos!"<<endl;
           cout<<"se escribio"<<endl;
       }//fin else por si el archivo NO esta vacio

       if(!impBonita.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

       QTextStream salidaFinal(&impBonita);

       out<<'\n';


       archivo.close();
      impBonita.close();

      rellenarIndice(estructura,tipo,campoEnviarIndice,camposIndice);

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

    if(!impBonita.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

    QTextStream browser(&impBonita);

    ui->browserImpresion->setText(browser.readAll());

    impBonita.close();

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text))
        return;
    QTextStream in(&archivo);


    while(!in.atEnd()){
        QString line=in.readLine();
        //**************************************************************//

        QList<QString>arregloCamposLeidos=line.split(',');

        cout<<line.toStdString()<<endl;
    if(arregloCamposLeidos.at(0)[0]!='&'){//si el registro no esta marcado como borrado ...

        //***************** ***Agregado a Tabla********************//
        cout<<"Numero inicial de rows: "<<ui->tablaLista->rowCount()<<endl;

        int row=ui->tablaLista->rowCount();
        int recordSize=0;

            for(int i=0;i<arregloCamposLeidos.size()-1;i++){
                cout<<"Se insertaria "<<arregloCamposLeidos.at(i).toStdString()<<" en la fila"<<row<<" y en la columna "<<i<<endl;

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
    impBonita.close();
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



    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

    int numberOfLines=0;


    QTextStream in(&archivo);


    while(!in.atEnd()){

        QString line=in.readLine();
        numberOfLines++;

        if(numberOfLines==2){
            in.seek((2-1)*30);
             cout<<"pos: "<<in.pos();
            QString tempLine=line;
            tempLine[0]='&';
            in<<tempLine<<'\n';

        }

    }//fin while mientras no termine el archivo

    archivo.close();

}

void MainWindow::setFixedLength(QString &texto, int size){


    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
            return;

    if(!impBonita.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
        return;

        QTextStream in(&archivo);
        QTextStream out(&archivo);
        QTextStream salidaBonita(&impBonita);

        QString textoBonito=texto;

    //validar si tiene menos que el limite

          if(texto.size()<size){
              for (int i=texto.size();i<size;i++){
                  texto.append('-');
              }//fin del recorrido de la cadena
              out<<texto<<',';

              salidaBonita<<textoBonito<<'\t';
          }//fin relleno de registro si es de menor longitud al limite

          else

          if(texto.size()==size){
              out<<texto<<',';
              salidaBonita<<textoBonito<<'\t';
          }

          else

                 if(texto.size()>size){

                     QString newText="";

                     for(int i=0;i<size;i++){
                         newText.append(texto.at(i));
                     }
                     out<<newText+',';
                       salidaBonita<<newText;
                 }

      archivo.close();
      impBonita.close();

}//fin de la funcion


void MainWindow::setFixedLength(int &numero,int numberSize,int limiteTamanio){//number size es el numero de digitos que ingreso el usuario en la dialog


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

    if(!archivoComp.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

    if(!archivo.open(QIODevice::ReadWrite|QIODevice::Text))
        return;

    QTextStream in(&archivo);
    QTextStream out(&archivoComp);


    while(!in.atEnd()){
       QString line=in.readLine();
       if(line.at(0)!='&'){
           out<<line<<'\n';

       }//fin si el registro no esta marcado


    }//end of file

    archivoComp.close();
    archivo.close();

}//end of function

void MainWindow::insertEndOfLine(){
    if (!impBonita.open(QIODevice::WriteOnly|QIODevice::Append))
        return;

    QTextStream salida(&impBonita);
    salida<<'\n';

    impBonita.close();

}

void  MainWindow::insertarEncabezadoBonito(QList <Campo> campos){
    if (!impBonita.open(QIODevice::ReadWrite|QIODevice::Append))
        return;

    QTextStream out(&impBonita);
    QString lineaAsteriscos="";

    out<<"     ";

    for(int i=0;i<campos.size();i++){
        out<<campos.at(i).getname()+'\t';
    }//fin recorrido de campos

    out<<'\n';

    for(int i=0;i<campos.size();i++){
        for(int j=2;j<campos.at(i).getLength();j++){
            lineaAsteriscos+='*';
        }
    }


    out<<lineaAsteriscos<<'\n';

    impBonita.close();

}//fin de la funcion




void MainWindow::on_actionBuscar_triggered()
{
        QString fields="";
        QString types="";

        QString finalField;
        QString finalType;

        QString keyType;

        Campo campoFinal;


    for(int i=0;i<estructura.size();i++){
        fields+=estructura.at(i).getname()+",";
        types+=estructura.at(i).getType()+",";
    }

    //crear dialog window aqui
    busqueda search(0,fields,types,keyType);
    search.setModal(true);
    search.exec();

    QList <QString> resultado=search.getResultadoFinal();
    cout<<"SE ECONTRARON "<<resultado.size()<<" RESULTADOS";
    for(int i=0;i<resultado.size();i++){
        cout<<resultado.at(i).toStdString()<<endl;
    }

    //falta crear una lista a la que se le asignara el resultado de la busqueda en la ventana
    //de ahi, solo queda setear en un text browser el resultado

}//fin de la funcion busqueda

void MainWindow::rellenarIndice(QList <Campo> estructura,QString tipo,QString campo,QList <QString> campos){

    if(!indice.open(QIODevice::WriteOnly|QIODevice::Append))
        return;

    QTextStream out(&indice);

    for(int i=0;i<estructura.size();i++){
        if(estructura.at(i).getType()==tipo){
            cout<<"INDICE 1, SE ESCRIBE: "<<campo.toStdString()<<endl;
            for(int j=0;j<campos.size();j++){
                if(campos.at(j)==campo){
                    cout<<"INDICE 2 SE VA A REMOVER: "<<campos.at(j).toStdString()<<endl;
                    campos.removeAt(j);
                }
            }
        }
    }//fin for

    for(int i=0;i<campos.size();i++){
        QString campito="";
        for(int j=0;j<campos.at(i).size();j++){
            if(campos.at(i).at(j)!='-'){
                campito+=campos.at(i).at(j);
            }
        }
        cout<<"INDICE 3: SE ESCRIBE: "<<campito.toStdString()<<endl;
        out<<campito<<'\t';
    }

    out <<'\n';
    indice.close();

}






void MainWindow::on_pushButton_clicked()
{

    estructura.clear();
    for(int i = 0; i < ui->tablaEstructura->rowCount(); i++){
        QString name = ui->tablaEstructura->item(i,0)->text();
        QString type = ui->tablaEstructura->item(i,1)->text();
        int length = ui->tablaEstructura->item(i,2)->text().toInt();
        bool key;
        if(ui->tablaEstructura->item(i,3)->text().toStdString() == "True"){
            key = true;
        }else{
            key = false;
        }
        Campo camp1;
        camp1.setName(name);
        camp1.setType(type);
        camp1.setLength(length);
        camp1.setKey(key);
        estructura.append(camp1);
    }
    //Limpiar la Tabla
    if(ui->tablaEstructura->rowCount() != 0){
        for(int i = 0; i < ui->tablaEstructura->rowCount(); i++){
            ui->tablaEstructura->removeRow(i);
        }
    }
    //Agregar la nueva estructura
    ui->tablaEstructura->setRowCount(estructura.count());
    for(int i = 0; i < estructura.count();i++){
        ui->tablaEstructura->setItem(i,0,new QTableWidgetItem(estructura.at(i).getname()));
        ui->tablaEstructura->setItem(i,2,new QTableWidgetItem(estructura.at(i).getLength()));
        ui->tablaEstructura->setItem(i,1,new QTableWidgetItem(estructura.at(i).getType()));
        ui->tablaEstructura->setItem(i,3,new QTableWidgetItem(estructura.at(i).IsKey()));
    }

}
