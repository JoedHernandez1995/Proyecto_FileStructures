#-------------------------------------------------
#
# Project created by QtCreator 2014-08-19T22:56:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto_OrgaDeArchivos
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vetanacampos.cpp \
    registro.cpp \
    campo.cpp \
    busqueda.cpp

HEADERS  += mainwindow.h \
    vetanacampos.h \
    registro.h \
    campo.h \
    busqueda.h

FORMS    += mainwindow.ui \
    vetanacampos.ui \
    busqueda.ui
