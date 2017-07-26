#include "mainWin.h"
#include "ui_mainWin.h"
#include <QWidgetAction>
#include <QMessageBox>

MainWin::MainWin(bool safe, bool trayed, QWidget* parent) :
    QMainWindow(parent),
	Filer(safe),
	ui(new Ui::MainWin)
{
	// set up window ui
	ui->setupUi(this);

	ui->horizontalSlider->setRange(minb(safe), MAX_B);
	ui->horizontalSlider->setValue(brightness);
	ui->lineEdit->setText(QString::number(brightness));
	ui->actionSafe->setChecked(safe);

	// set up tray icon ui
	tray = new QSystemTrayIcon(QIcon("://icon.png"), this);
	tray->setVisible(trayed);
	connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconClick(QSystemTrayIcon::ActivationReason)));

	tslider = new QSlider(Qt::Horizontal, this);
	tslider->setRange(minb(safe), MAX_B);
	tslider->setValue(brightness);
	connect(tslider, SIGNAL(sliderMoved(int)), this, SLOT(TSliderMoved(int)));

	QWidgetAction* actS = new QWidgetAction(this);
	actS->setDefaultWidget(tslider);

	menuL = new QMenu(this);
	menuL->addAction(actS);

	QAction* actW = new QAction("To Window", this);
	connect(actW, SIGNAL(triggered(bool)), this, SLOT(TWinClick()));

	menuR = new QMenu(this);
	menuR->addAction(ui->actionSafe);
	menuR->addAction(actW);
	menuR->addAction(ui->actionExit);
}

MainWin::~MainWin() {
	delete ui;
}

void MainWin::Save() {
	if (SaveBrightness()) {
		QMessageBox::critical(this, "Error", "Couldn't write file " + QString(fpath) + ".");
		close();
	} else
		SetUi();
}

void MainWin::SetUi() {
	ui->lineEdit->setText(QString::number(brightness));
	ui->horizontalSlider->setValue(brightness);
	tslider->setValue(brightness);
}

void MainWin::on_actionSafe_triggered(bool checked) {
	safe = checked;

	int min = minb(safe);
	ui->horizontalSlider->setMinimum(min);
	tslider->setMinimum(min);

	if (brightness < min) {
		brightness = min;
		Save();
	}
}

void MainWin::on_actionTo_Tray_triggered() {
	hide();
	tray->show();
}

void MainWin::on_actionExit_triggered() {
	close();
}

void MainWin::on_exitButton_clicked() {
	close();
}

void MainWin::on_lineEdit_textEdited(const QString& arg1) {
	brightness = arg1.toInt();
	Save();
}

void MainWin::on_horizontalSlider_sliderMoved(int position) {
	brightness = position;
	Save();
}

void MainWin::TrayIconClick(QSystemTrayIcon::ActivationReason reason) {
	if (reason == QSystemTrayIcon::Trigger) {
		tray->setContextMenu(menuL);
		tray->contextMenu()->popup(QCursor::pos());
	}
	else if (reason == QSystemTrayIcon::Context) {
		tray->setContextMenu(menuR);
		tray->contextMenu()->popup(QCursor::pos());
	}
}

void MainWin::TSliderMoved(int position) {
	brightness = position;
	Save();
}

void MainWin::TWinClick() {
	tray->hide();
	show();
}
