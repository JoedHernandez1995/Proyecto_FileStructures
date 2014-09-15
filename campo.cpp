#include "campo.h"
#include "string"

using namespace std;

Campo::Campo(){
}


void Campo::setName(QString nombre){
        name = nombre;
}

QString Campo::getname() const{
    return name;
}

void Campo::setType(QString tipo){
    type = tipo;
}

QString Campo::getType() const{
    return type;
}

void Campo::setLength(int longitud){
    length = longitud;
}

int Campo::getLength() const{
    return length;
}

void Campo::setKey(bool llave){
    key = llave;
}

bool Campo::IsKey() const{
    return key;
}
