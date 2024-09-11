#include "Animated.h"
namespace Anim {
	// tools
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // get handle for using color chanching

	void clearCmd() // clear cmd only for windows
	{
		system("cls");
	}

	char getRandomChar() {
		const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		int index = rand() % (sizeof(alphabet) - 1);
		return alphabet[index];
	}

	void delayPrint(std::string text, int delay_ms) // delay print
	{
		for (char t : text)
		{
			std::cout << t << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
		}
		std::cout << std::endl;
	}
	// themes
	void rainbowPrint(std::string text) // Rainbow Theme without delay print
	{
		int color = 0;
		for (char t : text)
		{
			color = (color + 1) % 16;
			SetConsoleTextAttribute(hConsole, color);
			std::cout << t;
		}
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
	}
	void rainbowDelayPrint(std::string text, int delay_ms) // Rainbow Theme with delay print
	{
		int color = 0; (color + 1) % 16;
		for (char t : text)
		{
			color = (color + 1) % 16;
			SetConsoleTextAttribute(hConsole, color);
			std::cout << t;
			std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
		}
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
	}
	void bloodDelayPrint(std::string text, int delay_ms) // Blood theme
	{
		int brightcolor = 4, blackcolor = 12;
		int half = text.size() / 2;
		std::string first = text.substr(0, half);
		std::string second = text.substr(half);

		SetConsoleTextAttribute(hConsole, brightcolor);
		delayPrint(first, delay_ms);
		SetConsoleTextAttribute(hConsole, blackcolor);
		delayPrint(second, delay_ms);
		SetConsoleTextAttribute(hConsole, 7);
	}
	void makeColorTheme(std::string text, int color1, int color2, int delay_ms) // make color theme like Blood , Astolfo
	{
		int half = text.size() / 2;
		std::string first = text.substr(0, half);
		std::string second = text.substr(half);

		SetConsoleTextAttribute(hConsole, color1);
		delayPrint(first, delay_ms);
		SetConsoleTextAttribute(hConsole, color2);
		delayPrint(second, delay_ms);
		SetConsoleTextAttribute(hConsole, 7);
	}
	// modes
	void generateMode(std::string text, int delayMs)
	{
		std::string gnr(text.size(), ' ');
		for (size_t i = 0; i < text.size(); i++)
		{
			while (gnr[i] != text[i])
			{
				gnr[i] = getRandomChar();
				std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
				std::cout << "\r" << gnr;
				std::cout.flush();
				std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
			}
		}
		std::cout << std::endl;
	}
	void blinkMode(std::string text, int color, int repeat, int delay_ms) // blink mode like appearance for moment and dissapearing
	{
		for (int i = 0; i <= repeat; i++)
		{
			SetConsoleTextAttribute(hConsole, color);
			std::cout << text << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << "\r" << std::string(text.size(), ' ') << "\r" << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
		}
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << std::endl;
	}
	// mics
	void getColorInfo(int color) // get colors for starters
	{
		switch (color)
		{
			// dark colors
		case 1:
			SetConsoleTextAttribute(hConsole, 1);
			std::cout << "dark blue color";
			break;
		case 2:
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "dark green color";
			break;
		case 3:
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << "dark cyan color";
			break;
		case 4:
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "dark red color";
			break;
		case 5:
			SetConsoleTextAttribute(hConsole, 5);
			std::cout << "dark pink color";
			break;
		case 6:
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "dark yellow color";
			break;
		case 7:
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << "dark white color";
			break;
		case 8:
			SetConsoleTextAttribute(hConsole, 8);
			std::cout << "dark gray color";
			break;
		case 9:
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << "another dark blue color";
			break;
			// bright colors
		case 10:
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "bright green color";
			break;
		case 11:
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "bright cyan color";
			break;
		case 12:
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "bright red color";
			break;
		case 13:
			SetConsoleTextAttribute(hConsole, 13);
			std::cout << "bright pink color";
			break;
		case 14:
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "bright yellow color";
			break;
		case 15:
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "bright white color";
			break;
		}
	}
}