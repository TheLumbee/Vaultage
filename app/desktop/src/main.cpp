#include <QApplication>

#include "ui/main_window/main_window.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainWindow window;
	window.resize(1200, 800);
	window.show();
	return app.exec();
}