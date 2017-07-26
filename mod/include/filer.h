#pragma once

#include "utils.h"
#include <QString>

class Filer {
public:
	Filer(bool safe=true);

	static bool CanRun();

	int LoadBrightness();
	int SaveBrightness();

	int brightness;
protected:
	bool safe;

	void CheckBrightness();
};
