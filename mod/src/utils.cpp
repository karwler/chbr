#include "utils.h"
#include <iostream>

bool isNum(const char* str) {
	uint start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	uint i = start;
	for (; str[i]!='\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return false;
	return i != start;
}

bool equal(const char* a, const char* b) {
	uint i = 0;
	do {
		if (a[i] != b[i])
			return false;
	} while (a[i++] != '\0');
	return true;
}

int minb(bool safe) {
	return safe ? MIN_B : 0;;
}

void CheckBrightness(int& bri, bool safe) {
	if (bri > MAX_B)
		bri = MAX_B;
	else {
		int min = minb(safe);
		if (bri < min)
			bri = min;
	}
}
