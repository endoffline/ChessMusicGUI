#include "ChessMusicGUI.h"
#include <QtWidgets/QApplication>
#include "Game.h"
#include "CSVReader.h"
#include <qDebug>

int FMOD_Main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChessMusicGUI w;
	w.show();

	
	return a.exec();
}
