#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

namespace Anim
{
	void clearCmd();
	char getRandomChar();
	void delayPrint(std::string text, int delay_ms);
	void rainbowPrint(std::string text);
	void rainbowDelayPrint(std::string text, int delay_ms);
	void bloodDelayPrint(std::string text, int delay_ms);
	void makeColorTheme(std::string text, int color1, int color2, int delay_ms);
	void generateMode(std::string text, int delayMs);
	void blinkMode(std::string text, int color, int repeat, int delay_ms);
	void getColorInfo(int color);
}
