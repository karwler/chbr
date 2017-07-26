#pragma once

#include "filer.h"
#include <QMainWindow>
#include <QShortcut>
#include <QSystemTrayIcon>
#include <QSlider>

namespace Ui {
	class MainWin;
}

class MainWin : public QMainWindow, public Filer {
    Q_OBJECT
public:
	explicit MainWin(bool safe=true, bool trayed=false, QWidget* parent=nullptr);
	~MainWin();

private slots:
	void on_actionSafe_triggered(bool checked);
	void on_actionTo_Tray_triggered();
	void on_actionExit_triggered();
	void on_exitButton_clicked();
	void on_lineEdit_textEdited(const QString& arg1);
	void on_horizontalSlider_sliderMoved(int position);

	void TrayIconClick(QSystemTrayIcon::ActivationReason reason);
	void TSliderMoved(int position);
	void TWinClick();

private:
	Ui::MainWin* ui;
	QSystemTrayIcon* tray;
	QMenu *menuL, *menuR;
	QSlider* tslider;

	void Save();
    void SetUi();
};
