#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgets.h"
#include <QCompleter>

struct Auto;

class QtWidgets : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgets(QWidget *parent = Q_NULLPTR);
private slots:
	void showEvent(QShowEvent *event);
	void on_GenerateButton_clicked(); // СЛОТ ДЛЯ ГЕНЕРАЦИИ WORD ДОКУМЕНТА

private:
    Ui::QtWidgetsClass ui;
	QStringList doc_pattern; // ЛИСТ С НАЗВАНИЯМИ ШАБЛОНОВ ДОКУМЕНТОВ
	QStringList AutoNumbers; // ЛИСТ С ГОС. НОМЕРАМИ АВТОМОБИЛЕЙ
	QCompleter *completer;
	QVector<Auto> _Auto; // МАССИВ СТРУКТУР АВТОМОБИЛЕЙ

};

struct Auto {
	Auto() = default;
	Auto(QString _mark, QString _year, QString _value)
		: mark(_mark), year(_year), value(_value) {}

	QString mark, year, value;
}; // СТРУКТУРА С ИНФОРМАЦИЕЙ О АВТОМОБИЛЕ (МАРКА, ГОД ВЫПУСКА, ГОС. НОМЕР)
