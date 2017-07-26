#pragma once

using uchar = unsigned char;
using uint = unsigned int;

const int MIN_B = 100000;
const int MAX_B = 2948310;
const char* const fpath = "/sys/devices/pci0000:00/0000:00:02.0/drm/card0/card0-LVDS-1/intel_backlight/brightness";

bool isNum(const char* str);
bool equal(const char* a, const char* b);
int minb(bool safe);
void CheckBrightness(int& bri, bool safe);
