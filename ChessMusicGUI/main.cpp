#include "ChessMusicGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChessMusicGUI w;
	w.show();
	return a.exec();
}
