#ifndef __SHGLCD_I2COLED_H__
#define __SHGLCD_I2COLED_H__

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include <Adafruit_SSD1306.h>
#include "SHGLCD_base.h"


// When using a 0.98" OLED w/ an SSD1306 driver, the resolution will almost always be 128x64
#define SCREEN_WIDTH 128 // OLED width
#define SCREEN_HEIGHT 64 // OLED height 
#define OLED_RESET 4
Adafruit_SSD1306 glcd1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_SSD1306 * oled[] = { &glcd1 };

class SHGLCD_I2COLED : public SHGLCD_Base
{
public:

	void Init() {
		glcd1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
		glcd1.clearDisplay();
		glcd1.setFont();
		glcd1.setTextSize(2);
		glcd1.setTextColor(WHITE);
		glcd1.setCursor(30, 20);
		glcd1.print("SimHub");
		glcd1.display();
	}

	void Display(int idx) {
		oled[idx]->display();
	}

	void ClearDisplay(int idx) {
		oled[idx]->clearDisplay();
	}

	void SetContrast(int idx, int c) {
		//nokiaLCDs[idx]->setContrast(c);
	}

	int GetScreenCount() {
		return 1;
	}

	Adafruit_GFX * GetScreen(int idx) {
		return oled[idx];
	}

};
#endif