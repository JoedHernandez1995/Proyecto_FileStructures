/********************************************************************************
** Form generated from reading UI file 'busqueda.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSQUEDA_H
#define UI_BUSQUEDA_H

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
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_busqueda
{
public:
    QLabel *label;
    QComboBox *cb_busqueda;
    QLabel *label_2;
    QLineEdit *lb_busqueda;
    QPushButton *pushButton;
    QSpinBox *sb_busqueda;
    QLabel *lb_info;

    void setupUi(QDialog *busqueda)
    {
        if (busqueda->objectName().isEmpty())
            busqueda->setObjectName(QStringLiteral("busqueda"));
        busqueda->resize(400, 300);
        label = new QLabel(busqueda);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 141, 17));
        cb_busqueda = new QComboBox(busqueda);
        cb_busqueda->setObjectName(QStringLiteral("cb_busqueda"));
        cb_busqueda->setGeometry(QRect(190, 50, 181, 41));
        cb_busqueda->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(busqueda);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 71, 21));
        lb_busqueda = new QLineEdit(busqueda);
        lb_busqueda->setObjectName(QStringLiteral("lb_busqueda"));
        lb_busqueda->setGeometry(QRect(190, 110, 181, 41));
        pushButton = new QPushButton(busqueda);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 190, 121, 51));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        sb_busqueda = new QSpinBox(busqueda);
        sb_busqueda->setObjectName(QStringLiteral("sb_busqueda"));
        sb_busqueda->setGeometry(QRect(190, 110, 181, 41));
        sb_busqueda->setMaximum(99999);
        lb_info = new QLabel(busqueda);
        lb_info->setObjectName(QStringLiteral("lb_info"));
        lb_info->setGeometry(QRect(190, 170, 171, 101));
        lb_info->setWordWrap(true);

        retranslateUi(busqueda);

        QMetaObject::connectSlotsByName(busqueda);
    } // setupUi

    void retranslateUi(QDialog *busqueda)
    {
        busqueda->setWindowTitle(QApplication::translate("busqueda", "Dialog", 0));
        label->setText(QApplication::translate("busqueda", "Buscar Registro Por:", 0));
        label_2->setText(QApplication::translate("busqueda", "Buscar:", 0));
        pushButton->setText(QApplication::translate("busqueda", "Search", 0));
        lb_info->setText(QApplication::translate("busqueda", "Su busqueda ha sido realizada, favor cerrar esta ventana para observar resultados!", 0));
    } // retranslateUi

};

namespace Ui {
    class busqueda: public Ui_busqueda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSQUEDA_H
