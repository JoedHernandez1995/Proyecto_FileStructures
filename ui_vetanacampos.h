/********************************************************************************
** Form generated from reading UI file 'vetanacampos.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VETANACAMPOS_H
#define UI_VETANACAMPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_vetanaCampos
{
public:
    QPushButton *btnAgregar;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineaNombre;
    QLabel *label_3;
    QComboBox *comboTipo;
    QLabel *label_4;
    QSpinBox *spinnerLength;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *radioPrimaria;

    void setupUi(QDialog *vetanaCampos)
    {
        if (vetanaCampos->objectName().isEmpty())
            vetanaCampos->setObjectName(QStringLiteral("vetanaCampos"));
        vetanaCampos->resize(400, 300);
        btnAgregar = new QPushButton(vetanaCampos);
        btnAgregar->setObjectName(QStringLiteral("btnAgregar"));
        btnAgregar->setGeometry(QRect(140, 210, 80, 23));
        label = new QLabel(vetanaCampos);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 10, 101, 16));
        label_2 = new QLabel(vetanaCampos);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 50, 57, 21));
        lineaNombre = new QLineEdit(vetanaCampos);
        lineaNombre->setObjectName(QStringLiteral("lineaNombre"));
        lineaNombre->setGeometry(QRect(160, 50, 113, 23));
        label_3 = new QLabel(vetanaCampos);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 90, 41, 21));
        comboTipo = new QComboBox(vetanaCampos);
        comboTipo->setObjectName(QStringLiteral("comboTipo"));
        comboTipo->setGeometry(QRect(160, 90, 79, 23));
        label_4 = new QLabel(vetanaCampos);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 130, 57, 21));
        spinnerLength = new QSpinBox(vetanaCampos);
        spinnerLength->setObjectName(QStringLiteral("spinnerLength"));
        spinnerLength->setGeometry(QRect(160, 130, 61, 24));
        label_5 = new QLabel(vetanaCampos);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 130, 57, 21));
        label_6 = new QLabel(vetanaCampos);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 170, 101, 21));
        radioPrimaria = new QRadioButton(vetanaCampos);
        radioPrimaria->setObjectName(QStringLiteral("radioPrimaria"));
        radioPrimaria->setGeometry(QRect(160, 170, 99, 21));

        retranslateUi(vetanaCampos);

        QMetaObject::connectSlotsByName(vetanaCampos);
    } // setupUi

    void retranslateUi(QDialog *vetanaCampos)
    {
        vetanaCampos->setWindowTitle(QApplication::translate("vetanaCampos", "Dialog", 0));
        btnAgregar->setText(QApplication::translate("vetanaCampos", "Agregar", 0));
        label->setText(QApplication::translate("vetanaCampos", "Agregar Campo", 0));
        label_2->setText(QApplication::translate("vetanaCampos", "Nombre:", 0));
        label_3->setText(QApplication::translate("vetanaCampos", "Tipo:", 0));
        comboTipo->clear();
        comboTipo->insertItems(0, QStringList()
         << QApplication::translate("vetanaCampos", "Char", 0)
         << QApplication::translate("vetanaCampos", "String", 0)
         << QApplication::translate("vetanaCampos", "Integer", 0)
         << QApplication::translate("vetanaCampos", "Double", 0)
        );
        label_4->setText(QApplication::translate("vetanaCampos", "Tama\303\261o:", 0));
        label_5->setText(QApplication::translate("vetanaCampos", "bytes", 0));
        label_6->setText(QApplication::translate("vetanaCampos", "Llave Primaria:", 0));
        radioPrimaria->setText(QApplication::translate("vetanaCampos", "Si/No", 0));
    } // retranslateUi

};

namespace Ui {
    class vetanaCampos: public Ui_vetanaCampos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VETANACAMPOS_H
