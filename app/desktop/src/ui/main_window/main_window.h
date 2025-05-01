#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
public:
	MainWindow();

private:
	void setup_menu_bar();

	QMenuBar menu_bar;
	QMenu app_menu;
	QMenu about_menu;
};

#endif // MAIN_WINDOW