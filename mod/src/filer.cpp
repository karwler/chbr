#include "filer.h"
#include <fstream>

Filer::Filer(bool safe) :
	safe(safe),
	brightness(-1)
{
	LoadBrightness();
}

bool Filer::CanRun() {
	return std::fstream(fpath, std::ios::in | std::ios::out).good();
}

int Filer::LoadBrightness() {
	std::ifstream file(fpath);
	if (!file.good())
		return -1;

	file >> brightness;
	return 0;
}

int Filer::SaveBrightness() {
	CheckBrightness();

	std::ofstream file(fpath);
	if (!file.good())
		return -1;

	file << brightness;
	return 0;
}

void Filer::CheckBrightness() {
	::CheckBrightness(brightness, safe);
}
