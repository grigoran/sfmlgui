#include "gui.h"
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>

int main() {
  float offset = 0;
  Gui myGui(800, 600, "ui");
  int resolution = 512;
  float *data = new float[resolution];
  Plot plot(data, resolution);
  plot.setPosition(100, 100);

  myGui.pushElement(&plot);

  while (myGui.isOpen()) {
    for (int i = 0; i < resolution; i++) {
      data[i] = sin(offset + 2 * M_PI * ((float)i / resolution));
    }
    offset += 10e-4;
    plot.update();
    myGui.update();
  }
  return 0;
}