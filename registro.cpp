#include "registro.h"
#include <QList>
#include <campo.h>

Registro::Registro()
{
}

void Registro::addField(Campo camp1){
    campos.append(camp1);
}

void Registro::deleteField(int){

}

void Registro::modifiyField(int,Campo){

}

QList <Campo> Registro::getLista(){
return campos;
}

void Registro::setListaCampos(QList<Campo> lista){
    campos=lista;
}
