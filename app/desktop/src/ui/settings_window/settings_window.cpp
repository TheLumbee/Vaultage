#include "settings_window.h"

SettingsWindow::SettingsWindow()
{
	setWindowTitle("Settings");
	resize(1000, 618);
	connect(this, &QWidget::close, &QWidget::deleteLater);
}