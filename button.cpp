#include "button.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

button ::button(int id) : clicked(false) {
  rect.setSize(sf::Vector2f(40.0f, 40.0f));
  rect.setFillColor(sf::Color::Red);
  lastTimeClicked = sf::milliseconds(0);
  clickCallback = defaultCallback;
  this->id = id;
}
button ::button() {
  color = sf::Color(18, 130, 222, 255);
  hoverColor = sf::Color(111, 169, 217, 255);
  rect.setSize(sf::Vector2f(40.0f, 40.0f));
  rect.setFillColor(sf::Color::Red);
  lastTimeClicked = sf::milliseconds(0);
  clickCallback = defaultCallback;
  this->id = 0;
}

void button::setId(int id) { this->id = id; }

void button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(rect, states);
}

sf::FloatRect button::getGlobalBounds() { return rect.getGlobalBounds(); }
void button::setPosition(float x, float y) { rect.setPosition(x, y); }

bool button::isHover() { return hover; }
void button::setHover(sf::Vector2i mousePos) { rect.setFillColor(hoverColor); }
void button::mouseOut() { rect.setFillColor(color); }

void button::setFillColor(sf::Color color) { rect.setFillColor(color); }

void button::setClickCallback(void (*callback)(void *)) {
  clickCallback = callback;
}

void button::setUserCallbackData(void *data) { userCallbackData = data; }

void button::click(sf::Vector2i mousePos) {
  if (clock.getElapsedTime().asMilliseconds() -
          lastTimeClicked.asMilliseconds() >
      100) {
    clicked = true;
    lastTimeClicked = clock.getElapsedTime();
    clickCallback(userCallbackData);
  }
}

bool button::isClicked() {
  if (clicked) {
    clicked = false;
    return true;
  } else
    return false;
}

void button::defaultCallback(void *) {}