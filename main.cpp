#include "gui.h"
#include <SFML/Graphics/Color.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

sf::Color randColor() {
  return sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
}

sf::Color dimColor(float val, sf::Color color) {
  return sf::Color(color.r * val, color.g * val, color.b * val, 255);
}

struct btnStates {
  sf::Color hoverColor;
  sf::Color unhoverColor;
};

void clickCallback(void *userCallbackData) {
  btnStates *state = (btnStates *)userCallbackData;
  state->hoverColor = randColor();
  state->unhoverColor = dimColor(0.5f, state->hoverColor);
}

void listCallback(void *userCallbackData, int selectedItem) {
  int *data = (int *)userCallbackData;
  std::cout << selectedItem << std::endl;
}

int main() {
  srand(std::time(0));
  gui myGui(800, 600, "ui");
  const int btnCount = 10;
  button btns[btnCount];
  btnStates states[btnCount];
  for (int i = 0; i < btnCount; i++) {
    states[i].hoverColor = randColor();
    states[i].unhoverColor = dimColor(0.5f, states[i].hoverColor);
    btns[i].setId(i);
    btns[i].setPosition(i * 80 + 20, 280);
    btns[i].setClickCallback(clickCallback);
    btns[i].setUserCallbackData(&states[i]);
    myGui.pushElement(&btns[i]);
  }

  const int listCount = 3;
  list myList[listCount];
  int contentSize = 5;
  const char *content[] = {"first", "second", "third", "fourth", "fifth"};
  for (int i = 0; i < listCount; i++) {
    myList[i].setContent(content, contentSize);
    myList[i].setPosition(i * 220 + 70, 10);
    int *d = new int(10);
    myList[i].setUserCallbackData(&d);
    myList[i].setChangeCallback(listCallback);
    myGui.pushElement(&myList[i]);
  }

  while (myGui.isOpen()) {
    for (int i = 0; i < btnCount; i++) {
      if (btns[i].isHover()) {
        // btns[i].setFillColor(states[i].hoverColor);
      } else {
      }
      // btns[i].setFillColor(states[i].unhoverColor);
    }
    myGui.update();
  }
  return 0;
}