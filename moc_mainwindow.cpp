/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 32),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 26),
QT_MOC_LITERAL(4, 72, 25),
QT_MOC_LITERAL(5, 98, 30),
QT_MOC_LITERAL(6, 129, 25),
QT_MOC_LITERAL(7, 155, 14),
QT_MOC_LITERAL(8, 170, 4),
QT_MOC_LITERAL(9, 175, 8),
QT_MOC_LITERAL(10, 184, 15),
QT_MOC_LITERAL(11, 200, 24),
QT_MOC_LITERAL(12, 225, 12),
QT_MOC_LITERAL(13, 238, 6),
QT_MOC_LITERAL(14, 245, 14),
QT_MOC_LITERAL(15, 260, 10),
QT_MOC_LITERAL(16, 271, 4),
QT_MOC_LITERAL(17, 276, 5),
QT_MOC_LITERAL(18, 282, 14),
QT_MOC_LITERAL(19, 297, 28),
QT_MOC_LITERAL(20, 326, 25),
QT_MOC_LITERAL(21, 352, 21)
    },
    "MainWindow\0on_actionNuevo_Archivo_triggered\0"
    "\0on_actionAgregar_triggered\0"
    "on_actionListar_triggered\0"
    "on_actionVer_Archivo_triggered\0"
    "on_actionBorrar_triggered\0setFixedLength\0"
    "int&\0QString&\0insertEndOfLine\0"
    "insertarEncabezadoBonito\0QList<Campo>\0"
    "campos\0rellenarIndice\0estructura\0tipo\0"
    "campo\0QList<QString>\0on_actionCompactar_triggered\0"
    "on_actionBuscar_triggered\0"
    "on_pushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08,
       3,    0,   80,    2, 0x08,
       4,    0,   81,    2, 0x08,
       5,    0,   82,    2, 0x08,
       6,    0,   83,    2, 0x08,
       7,    3,   84,    2, 0x08,
       7,    2,   91,    2, 0x08,
      10,    0,   96,    2, 0x08,
      11,    1,   97,    2, 0x08,
      14,    4,  100,    2, 0x08,
      19,    0,  109,    2, 0x08,
      20,    0,  110,    2, 0x08,
      21,    0,  111,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString, QMetaType::QString, 0x80000000 | 18,   15,   16,   17,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionNuevo_Archivo_triggered(); break;
        case 1: _t->on_actionAgregar_triggered(); break;
        case 2: _t->on_actionListar_triggered(); break;
        case 3: _t->on_actionVer_Archivo_triggered(); break;
        case 4: _t->on_actionBorrar_triggered(); break;
        case 5: _t->setFixedLength((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->setFixedLength((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->insertEndOfLine(); break;
        case 8: _t->insertarEncabezadoBonito((*reinterpret_cast< QList<Campo>(*)>(_a[1]))); break;
        case 9: _t->rellenarIndice((*reinterpret_cast< QList<Campo>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QString>(*)>(_a[4]))); break;
        case 10: _t->on_actionCompactar_triggered(); break;
        case 11: _t->on_actionBuscar_triggered(); break;
        case 12: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
