#ifndef CAMPO_H
#define CAMPO_H
#include <QString>
#include<iostream>
#include "string"
#include <string>

using namespace std;

class Campo
{
public:
    Campo();

    void setName(QString);
    QString getname() const;
    void setType(QString);
    QString getType() const;
    void setLength(int);
    int getLength() const;
    void setKey(bool);
    bool IsKey() const;


private:
    QString name;
    QString type;
    int length;
    bool key;
};

#endif // CAMPO_H
