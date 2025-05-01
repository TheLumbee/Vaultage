#include "main_window.h"

#include <QAction>
#include <QApplication>
#include <QIcon>
#include <QMenuBar>

#include "ui/settings_window/settings_window.h"

MainWindow::MainWindow()
{
	setWindowTitle("Vaultage");
	setup_menu_bar();
}

void MainWindow::setup_menu_bar()
{
	// App Menu
	app_menu.setTitle("Application");

	QAction* action = app_menu.addAction("Settings");
	connect(action, &QAction::triggered,
		[]
		{
			SettingsWindow* settings_window = new SettingsWindow();
			settings_window->show();
		});

	action = app_menu.addAction("Quit");
	connect(action, &QAction::triggered, [] { qApp->quit(); });

	menu_bar.addMenu(&app_menu);

	// About Menu
	about_menu.setTitle("About");
	action = about_menu.addAction("About Qt");
	connect(action, &QAction::triggered, [] { qApp->aboutQt(); });

	menu_bar.addMenu(&about_menu);

	// Set menu bar to main window
	setMenuBar(&menu_bar);
}