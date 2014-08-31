/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo_Archivo;
    QAction *actionVer_Archivo;
    QAction *actionModificar;
    QAction *actionAgregar;
    QAction *actionBuscar;
    QAction *actionBorrar;
    QAction *actionListar;
    QAction *actionCompactar;
    QAction *actionReindexar;
    QAction *actionExportar;
    QWidget *centralWidget;
    QTableWidget *tablaEstructura;
    QLabel *lb_info;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuRegistros;
    QMenu *menuOPeraciones;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(671, 417);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionNuevo_Archivo = new QAction(MainWindow);
        actionNuevo_Archivo->setObjectName(QStringLiteral("actionNuevo_Archivo"));
        actionVer_Archivo = new QAction(MainWindow);
        actionVer_Archivo->setObjectName(QStringLiteral("actionVer_Archivo"));
        actionModificar = new QAction(MainWindow);
        actionModificar->setObjectName(QStringLiteral("actionModificar"));
        actionAgregar = new QAction(MainWindow);
        actionAgregar->setObjectName(QStringLiteral("actionAgregar"));
        actionBuscar = new QAction(MainWindow);
        actionBuscar->setObjectName(QStringLiteral("actionBuscar"));
        actionBorrar = new QAction(MainWindow);
        actionBorrar->setObjectName(QStringLiteral("actionBorrar"));
        actionListar = new QAction(MainWindow);
        actionListar->setObjectName(QStringLiteral("actionListar"));
        actionCompactar = new QAction(MainWindow);
        actionCompactar->setObjectName(QStringLiteral("actionCompactar"));
        actionReindexar = new QAction(MainWindow);
        actionReindexar->setObjectName(QStringLiteral("actionReindexar"));
        actionExportar = new QAction(MainWindow);
        actionExportar->setObjectName(QStringLiteral("actionExportar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tablaEstructura = new QTableWidget(centralWidget);
        tablaEstructura->setObjectName(QStringLiteral("tablaEstructura"));
        tablaEstructura->setGeometry(QRect(10, 20, 401, 361));
        lb_info = new QLabel(centralWidget);
        lb_info->setObjectName(QStringLiteral("lb_info"));
        lb_info->setGeometry(QRect(40, 0, 211, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuRegistros = new QMenu(menuBar);
        menuRegistros->setObjectName(QStringLiteral("menuRegistros"));
        menuOPeraciones = new QMenu(menuBar);
        menuOPeraciones->setObjectName(QStringLiteral("menuOPeraciones"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuRegistros->menuAction());
        menuBar->addAction(menuOPeraciones->menuAction());
        menuArchivo->addAction(actionNuevo_Archivo);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionVer_Archivo);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionModificar);
        menuRegistros->addAction(actionAgregar);
        menuRegistros->addSeparator();
        menuRegistros->addAction(actionBuscar);
        menuRegistros->addSeparator();
        menuRegistros->addAction(actionBorrar);
        menuRegistros->addSeparator();
        menuRegistros->addAction(actionListar);
        menuOPeraciones->addAction(actionCompactar);
        menuOPeraciones->addSeparator();
        menuOPeraciones->addAction(actionReindexar);
        menuOPeraciones->addSeparator();
        menuOPeraciones->addAction(actionExportar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Proyecto", 0));
        actionNuevo_Archivo->setText(QApplication::translate("MainWindow", "Nuevo Archivo", 0));
        actionVer_Archivo->setText(QApplication::translate("MainWindow", "Ver Estructura", 0));
        actionModificar->setText(QApplication::translate("MainWindow", "Modificar Estructura", 0));
        actionAgregar->setText(QApplication::translate("MainWindow", "Agregar", 0));
        actionBuscar->setText(QApplication::translate("MainWindow", "Buscar", 0));
        actionBorrar->setText(QApplication::translate("MainWindow", "Borrar", 0));
        actionListar->setText(QApplication::translate("MainWindow", "Listar", 0));
        actionCompactar->setText(QApplication::translate("MainWindow", "Compactar", 0));
        actionReindexar->setText(QApplication::translate("MainWindow", "Reindexar", 0));
        actionExportar->setText(QApplication::translate("MainWindow", "Exportar", 0));
        lb_info->setText(QApplication::translate("MainWindow", "Seleccione una de las opciones", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuRegistros->setTitle(QApplication::translate("MainWindow", "Registros", 0));
        menuOPeraciones->setTitle(QApplication::translate("MainWindow", "Operaciones", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
