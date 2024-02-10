#include "QtWidgets.h"
#include <fstream>
#include <QFile>
#include <QString>
#include <QTextCodec>
#include <QLineEdit>
#include <string>

#define Uses_MSO2007 // ПОДКЛЮЧЕНИЕ БИБЛИОТЕКИ INTEROP WORD
#import "C:\Program Files\Common Files\Microsoft Shared\Office12\MSO.DLL"
#import "C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB"
#import "D:\MS WORD\Office12\MSWORD.OLB" \
rename("ExitWindows", "_ExitWindows")
#import "C:\Program Files\Common Files\Microsoft Shared\DAO\DAO360.DLL" \
rename("EOF","EndOfFile") rename("BOF","BegOfFile")

void Replace(Word::FindPtr &f, std::string find_text, std::string replacement_text); // ФУНКЦИЯ ДЛЯ ПОИСКА И ЗАМЕНЫ ТЕКСТА В ДОКУМЕНТЕ WORD

QtWidgets::QtWidgets(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.lineEdit_DocPattern, QOverload<const QString &>::of(&QLineEdit::textChanged), [=](const QString& text)
	{
		ui.lineEdit_DocPattern->setText(text.toUpper());
	});
	QObject::connect(ui.lineEdit_AutoNumber, QOverload<const QString &>::of(&QLineEdit::textChanged), [=](const QString& text)
	{
		ui.lineEdit_AutoNumber->setText(text.toUpper());
	});
	QObject::connect(ui.GenerateButton, &QPushButton::clicked, this, &QtWidgets::on_GenerateButton_clicked);

}

void QtWidgets::showEvent(QShowEvent * event)
{
	QFile ifs("FileNamesRu.txt"); // БЕРЕМ ИНФОРМАЦИЮ О ШАБЛОНАХ ДОКУМЕНТОВ ИЗ ФАЙЛА.
	ifs.open(QIODevice::ReadOnly);
	QTextCodec *codec = QTextCodec::codecForName("CP1251");

	for (int i = 0; !ifs.atEnd(); i++)
	{
		QString str = codec->toUnicode(ifs.readLine());
		if (str != "\r\n")
		{
			str.resize(str.size() - 2);
			doc_pattern.push_back(str);
		}
	}
	ifs.close();

	ifs.setFileName("NumberAuto.txt"); // БЕРЕМ ИНФОРМАЦИЮ О ГОС. НОМЕРАХ АВТОМОБИЛЕЙ ИЗ ФАЙЛА.
	QString mark_now = "PAZ", year_now = "2019";

	ifs.open(QIODevice::ReadOnly);
	for (int i = 0; !ifs.atEnd(); i++)
	{
		QString str = codec->toUnicode(ifs.readLine());
		if (str != "\r\n")
		{
			str.resize(str.size() - 2);

			if (str[0] == '/')
				if (str[1] == '2')
					year_now = str.remove(0, 1);
				else
					mark_now = str.remove(0, 1);
			else
			{
				AutoNumbers.push_back(str);
				_Auto.push_back(Auto(mark_now, year_now, str));
			}
		}
	}
	ifs.close();

	completer = new QCompleter(doc_pattern, this); // СОЗДАЕМ И ДОБАВЛЯЕМ completer В LineEdit
	completer->setCompletionMode(QCompleter::PopupCompletion);
	ui.lineEdit_DocPattern->setCompleter(completer);

	completer = new QCompleter(AutoNumbers, this);
	completer->setCompletionMode(QCompleter::PopupCompletion);
	completer->setFilterMode(Qt::MatchContains);
	ui.lineEdit_AutoNumber->setCompleter(completer);

	ui.dateEdit->setDate(QDate::currentDate().addMonths(-1));

	QMainWindow::showEvent(event);
}

void QtWidgets::on_GenerateButton_clicked()
{
	using namespace Word;

	::CoInitialize(NULL);
	{
		std::string FileNameRu = ui.lineEdit_DocPattern->text().toLocal8Bit().data(); // ПЕРЕВОДИМ СТРОКУ С НАЗВАНИЕМ ШАБЛОНА ДОКУМЕНТА В КИРИЛЛИЦУ
		if (FileNameRu.empty())
			return;
		QString FileNameEng;
	
		int i = 0;
			for (; i < _Auto.size(); i++)
			{
				if (_Auto[i].value == ui.lineEdit_AutoNumber->text())
					break;
			}

		for (char& el : FileNameRu)
		{
			switch (el)
			{
			case 'А':
				FileNameEng.push_back('A');
				break;
			case 'Б':
				FileNameEng.push_back('B');
				break;
			case 'В':
				FileNameEng.push_back('V');
				break;
			case 'Г':
				FileNameEng.push_back('G');
				break;
			case 'Д':
				FileNameEng.push_back('D');
				break;
			case 'Е':
				FileNameEng.push_back('E');
				break;
			case 'Ж':
				FileNameEng.push_back("ZH");
				break;
			case 'З':
				FileNameEng.push_back('Z');
				break;
			case 'И':
				FileNameEng.push_back('I');
				break;
			case 'Й':
				FileNameEng.push_back('Y');
				break;
			case 'К':
				FileNameEng.push_back('K');
				break;
			case 'Л':
				FileNameEng.push_back('L');
				break;
			case 'М':
				FileNameEng.push_back('M');
				break;
			case 'Н':
				FileNameEng.push_back('N');
				break;
			case 'О':
				FileNameEng.push_back('O');
				break;
			case 'П':
				FileNameEng.push_back('P');
				break;
			case 'Р':
				FileNameEng.push_back('R');
				break;
			case 'С':
				FileNameEng.push_back('S');
				break;
			case 'Т':
				FileNameEng.push_back('T');
				break;
			case 'У':
				FileNameEng.push_back('U');
				break;
			case 'Ф':
				FileNameEng.push_back('F');
				break;
			case 'Х':
				FileNameEng.push_back("KH");
				break;
			case 'Ц':
				FileNameEng.push_back('C');
				break;
			case 'Ч':
				FileNameEng.push_back("CH");
				break;
			case 'Ш':
				FileNameEng.push_back("SH");
				break;
			case 'Ы':
				FileNameEng.push_back('Y');
				break;
			case 'Э':
				FileNameEng.push_back('E');
				break;
			case 'Ю':
				FileNameEng.push_back("YU");
				break;
			case 'Я':
				FileNameEng.push_back("YA");
				break;
			case ' ':
				FileNameEng.push_back(' ');
				break;
			}
		}
			
		FileNameEng = "D:\\MY PROJECTS\\wd\\Resources\\" + FileNameEng + "-" + _Auto[i].mark + (ui.checkBox->isChecked() ? "-COMPANY_1" : "-COMPANY_2"); // D:\\MY PROJECTS\\wd\\Resources\\DVS-VAZ-COMPANY_2

		_ApplicationPtr word(L"Word.Application");
		word->Visible = true;
		word->Activate();

		_DocumentPtr wdoc1 = word->Documents->Open(&_variant_t(FileNameEng.toLocal8Bit().data()));
		
		Word::FindPtr f = word->Selection->Find;
		
		if (ui.dateEdit->date().day()<10) // ЗАМЕНЯЕМ КЛЮЧИ В ШАБЛОНЕ
			Replace(f, "<D>", "0" + std::to_string(ui.dateEdit->date().day()));
		else
			Replace(f, "<D>", std::to_string(ui.dateEdit->date().day()));

		if (ui.dateEdit->date().month() < 10)
			Replace(f, "<M>", "0" + std::to_string(ui.dateEdit->date().month()));
		else
			Replace(f, "<M>", std::to_string(ui.dateEdit->date().month()));

		Replace(f, "<YY>", std::to_string(ui.dateEdit->date().year()));
		Replace(f, "<NNNN>",_Auto[i].value.toLocal8Bit().data());
		Replace(f, "<GG>",_Auto[i].year.toLocal8Bit().data());

		wdoc1->Range()->Copy(); // КОПИРУЕМ СОДЕРЖИМОЕ ДОКУМЕНТА

		wdoc1->Close(&_variant_t(Word::WdSaveOptions::wdDoNotSaveChanges));
		word->Quit();
	}
	::CoUninitialize();
}

void Replace(Word::FindPtr &f, std::string find_text, std::string replacement_text) // ФУНКЦИЯ ДЛЯ ПОИСКА И ЗАМЕНЫ ТЕКСТА В ДОКУМЕНТЕ WORD
{
	f->ClearFormatting();
	f->Text = find_text.c_str();
	f->Replacement->ClearFormatting();
	f->Replacement->Text = replacement_text.c_str();
	f->Execute(&vtMissing, &vtMissing, &vtMissing, &vtMissing, &vtMissing, &vtMissing, &vtMissing, &vtMissing, &vtMissing, &vtMissing, &_variant_t(Word::WdReplace::wdReplaceAll), &vtMissing, &vtMissing, &vtMissing, &vtMissing);
}
