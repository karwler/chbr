#include "filer.h"
#include <iostream>

int main(int argc, char** argv) {
	bool add = false;
	bool safe = true;
	int bri = -1;

	for (int i=1; i!=argc; i++) {
		if (equal(argv[i], "-a"))
			add = true;
		else if (equal(argv[i], "-n"))
			safe = false;
		else if (equal(argv[i], "-h")) {
			std::cout << "<number>     : set brightness to <number>" << std::endl
					  << "-a <number>  : add <number> to current brightness" << std::endl
					  << "-n           : disable min limit" << std::endl;
			return 0;
		} if (isNum(argv[i]))
			bri = std::stoi(argv[i]);
	}

	Filer f(safe);
	if (f.brightness < 0) {
		std::cerr << "couldn't read file " << fpath << std::endl;
		return -1;
	}

	if (add)
		f.brightness += bri;
	else {
		if (bri < 0) {
			std::cerr << "invalid brightness" << std::endl;
			return -2;
		}
		f.brightness = bri;
	}

	int ret = f.SaveBrightness();
	if (ret)
		std::cerr << "couldn't write file " << fpath << std::endl;
	return ret;
}

