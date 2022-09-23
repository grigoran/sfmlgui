#include "list.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

list::list()
    : hover(false), isMenuOpen(false), selectedItem(0), isChanged(false),
      contentSize(0), fontSize(12), fontSpacing(5) {
  rectColor = sf::Color(18, 130, 222, 255);
  rectHoverColor = sf::Color(111, 169, 217, 255);
  rect.setSize(sf::Vector2f(200.0f, fontSize + fontSpacing * 2));
  rect.setFillColor(sf::Color::Cyan);

  menuBackground.setSize(sf::Vector2f(200.0f, 100.0f));
  menuBackground.setFillColor(sf::Color(15, 98, 166, 255));
  menuBackground.move(0.0f, rect.getSize().y);
  font.loadFromFile("../Hack-Bold.ttf");

  selectedContent.setFont(font);
  selectedContent.setCharacterSize(fontSize);
  selectedContent.setFillColor(sf::Color::Black);
  selectedContent.setPosition(0, fontSpacing);

  changeCallback = defaultCallback;
}

void list::setChangeCallback(void (*callback)(void *, int)) {
  changeCallback = callback;
}

void list::setUserCallbackData(void *data) { userCallbackData = data; }

void list::setContent(const char **content, int size) {
  this->content = new sf::Text[size];
  for (int i = 0; i < size; i++) {
    this->content[i].setFont(font);
    this->content[i].setString(content[i]);
    this->content[i].setCharacterSize(fontSize);
    this->content[i].setFillColor(sf::Color::Black);
    this->content[i].setPosition(
        rect.getPosition().x, rect.getSize().y + i * (fontSize + fontSpacing));
  }
  contentSize = size;
  selectedContent.setString(this->content[0].getString());
}

void list::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(rect, states);
  target.draw(selectedContent);
  if (isMenuOpen) {
    target.draw(menuBackground);
    for (int i = 0; i < contentSize; i++) {
      target.draw(content[i]);
    }
  }
}

void list::click(sf::Vector2i mousePos) {
  if (!isMenuOpen)
    isMenuOpen = true;
  else {
    for (int i = 0; i < contentSize; i++) {
      if (i != selectedItem &&
          content[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        selectedItem = i;
        selectedContent.setString(content[i].getString());
        changeCallback(userCallbackData, selectedItem);
        isMenuOpen = false;
      }
    }
  }
}

void list::setHover(sf::Vector2i mousePos) {
  float c = 1.1;
  rect.setFillColor(rectHoverColor);
  for (int i = 0; i < contentSize; i++) {
    if (content[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
      content[i].setFillColor(sf::Color::Red);
    } else
      content[i].setFillColor(sf::Color::Black);
  }
}

void list::mouseOut() { isMenuOpen = false; }

sf::FloatRect list::getGlobalBounds() {
  rect.setFillColor(rectColor);
  if (!isMenuOpen)
    return rect.getGlobalBounds();
  else {
    sf::FloatRect bound = rect.getGlobalBounds();
    float menuHeight = menuBackground.getSize().y;
    bound.height += menuHeight;
    return bound;
  }
}

void list::setPosition(float x, float y) {
  rect.setPosition(x, y);
  selectedContent.setPosition(x, y + fontSpacing);
  menuBackground.setPosition(x, y + fontSize + fontSpacing * 2);
  for (int i = 0; i < contentSize; i++) {
    content[i].setPosition(x, fontSpacing + y + rect.getSize().y +
                                  i * (fontSize + fontSpacing));
  }
}

void list::defaultCallback(void *, int) {}