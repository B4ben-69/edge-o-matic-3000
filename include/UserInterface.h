#ifndef __User_Interface_h
#define __User_Interface_h

#include "../config.h"

#define CHART_START_Y 10
#define CHART_END_Y (SCREEN_HEIGHT - 11)
#define CHART_HEIGHT (CHART_END_Y - CHART_START_Y)
#define CHART_START_X 9
#define CHART_END_X (SCREEN_WIDTH)
#define CHART_WIDTH (CHART_END_X - CHART_START_X)

#include <Adafruit_SSD1306.h>

class UserInterface {
public:
  UserInterface(Adafruit_SSD1306* display);

  // Common Element Drawing Functions
  void drawChartAxes();
  void drawChart(int peakLimit);
  void drawStatus(const char* status);

  // Chart Data
  void addChartReading(int index, int value);
  void setMotorSpeed(uint8_t perc);

  // Render Controls
  void render();

private:
  Adafruit_SSD1306* display;

  // Chart Data:
  int chartReadings[2][CHART_WIDTH] = {{0}, {0}};
  uint8_t chartCursor[2] = {0,0};
};

#endif