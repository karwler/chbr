#include "mainWin.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>

int main(int argc, char** argv) {
	bool safe = true;
	bool trayed = false;

	for (int i=1; i!=argc; i++) {
		if (equal(argv[i], "-n"))
			safe = false;
		else if (equal(argv[i], "-t"))
			trayed = true;
		else if (equal(argv[i], "-h")) {
			std::cout << "-n : disable min limit" << std::endl
					  << "-t : start in system tray" << std::endl;
			return 0;
		}
	}

	QApplication a(argc, argv);
	MainWin w(safe, trayed);
	if (w.brightness < 0) {
		QMessageBox::critical(nullptr, "Error", "Couldn't read file " + QString(fpath) + ".");
		return -1;
	}
	if (!trayed)
		w.show();
	return a.exec();
}
