/********************************************************************************
** Form generated from reading UI file 'QtWidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETS_H
#define UI_QTWIDGETS_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsClass
{
public:
    QWidget *centralWidget;
    QPushButton *GenerateButton; // КНОПКА СОЗДАНИЯ ДОКУМЕНТА WORD
    QCheckBox *checkBox; // ОПРЕДЕЛЯЕТ КОМПАНИЮ, ВЫПОЛНИВШУЮ УСЛУГИ
    QDateEdit *dateEdit; // ДАТА ДОКУМЕНТА
    QLabel *label_DocPattern;
    QLabel *label_AutoNumber;
    QLineEdit *lineEdit_DocPattern; // НАЗВАНИЕ ШАБЛОНА ДОКУМЕНТА
    QLineEdit *lineEdit_AutoNumber; // ГОС. НОМЕР АВТОМОБИЛЯ

    void setupUi(QMainWindow *QtWidgetsClass)
    {
        if (QtWidgetsClass->objectName().isEmpty())
            QtWidgetsClass->setObjectName(QStringLiteral("QtWidgetsClass"));
        QtWidgetsClass->resize(349, 185);
        centralWidget = new QWidget(QtWidgetsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GenerateButton = new QPushButton(centralWidget);
        GenerateButton->setObjectName(QStringLiteral("GenerateButton"));
        GenerateButton->setGeometry(QRect(120, 140, 151, 31));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(300, 150, 16, 17));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(250, 100, 81, 22));
        dateEdit->setWrapping(false);
        dateEdit->setFrame(true);
        dateEdit->setReadOnly(false);
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit->setAccelerated(true);
        dateEdit->setKeyboardTracking(true);
        dateEdit->setProperty("showGroupSeparator", QVariant(false));
        dateEdit->setDateTime(QDateTime(QDate(2024, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        dateEdit->setTimeSpec(Qt::LocalTime);
        dateEdit->setDate(QDate(2024, 1, 1));
        label_DocPattern = new QLabel(centralWidget); 
        label_DocPattern->setObjectName(QStringLiteral("label_DocPattern"));
        label_DocPattern->setGeometry(QRect(10, 20, 111, 16));
        label_AutoNumber = new QLabel(centralWidget);
        label_AutoNumber->setObjectName(QStringLiteral("label_AutoNumber"));
        label_AutoNumber->setGeometry(QRect(40, 60, 101, 16));
        lineEdit_DocPattern = new QLineEdit(centralWidget);
        lineEdit_DocPattern->setObjectName(QStringLiteral("lineEdit_DocPattern"));
        lineEdit_DocPattern->setGeometry(QRect(130, 20, 201, 20));
        lineEdit_AutoNumber = new QLineEdit(centralWidget);
        lineEdit_AutoNumber->setObjectName(QStringLiteral("lineEdit_AutoNumber"));
        lineEdit_AutoNumber->setGeometry(QRect(130, 60, 201, 20));
        QtWidgetsClass->setCentralWidget(centralWidget);

        retranslateUi(QtWidgetsClass);

        QMetaObject::connectSlotsByName(QtWidgetsClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsClass)
    {
        QtWidgetsClass->setWindowTitle(QApplication::translate("QtWidgetsClass", "QtWidgets", Q_NULLPTR));
        GenerateButton->setText(QApplication::translate("QtWidgetsClass", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        checkBox->setText(QString());
        label_DocPattern->setText(QApplication::translate("QtWidgetsClass", "\320\250\320\260\320\261\320\273\320\276\320\275 \320\224\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", Q_NULLPTR));
        label_AutoNumber->setText(QApplication::translate("QtWidgetsClass", "\320\223\320\276\321\201. \320\275\320\276\320\274\320\265\321\200 \320\242\320\241", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsClass: public Ui_QtWidgetsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETS_H
