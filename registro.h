#ifndef REGISTRO_H
#define REGISTRO_H
#include <QList>
#include <campo.h>

class Registro {

public:

    Registro();
    void addField(Campo);
    void deleteField(int);
    void modifiyField(int,Campo);
    QList <Campo> getLista();
    void setListaCampos(QList<Campo>);

private:
    QList <Campo> campos;

};

#endif // REGISTRO_H
