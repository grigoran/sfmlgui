#include "gui.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

Gui::Gui(int resolutionX, int resolutionY, const char *title)
    : window(sf::VideoMode(resolutionX, resolutionY), title) {}

void Gui::update() {
  mousePos = sf::Mouse::getPosition(window);
  sf::Event event;

  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();
  }

  for (int i = 0; i < uielements.size(); i++) {
    if (uielements[i]->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        uielements[i]->click(mousePos);
      uielements[i]->setHover(mousePos);
    } else
      uielements[i]->mouseOut();
  }
  draw();
}

void Gui::draw() {
  int grayScale = 200;
  window.clear(sf::Color(grayScale, grayScale, grayScale, 255));
  for (int i = 0; i < uielements.size(); i++) {
    window.draw(*uielements[i]);
  }
  window.display();
}

bool Gui::isOpen() { return window.isOpen(); }

void Gui::pushElement(uielement *elem) { uielements.push_back(elem); }