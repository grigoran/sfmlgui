#include "Plot.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>

Plot::Plot(const float *data, int resolution) {
  this->resolution = resolution;
  this->data = data;
  vert = new sf::CircleShape[resolution];
  for (int i = 0; i < resolution; i++) {
    vert[i].setRadius(2.0f);
    vert[i].setFillColor(sf::Color::Blue);
  }
  this->size = sf::Vector2f(512.0f, 256.0f);
  rect.setSize(this->size);
  rect.setFillColor(sf::Color::White);
}

void Plot::setPosition(float x, float y) { rect.setPosition(x, y); }

void Plot::update() {
  sf::Vector2f glPos = rect.getPosition();
  sf::Vector2f pos;
  for (int i = 0; i < resolution; i++) {
    pos.x = glPos.x + ((float)i / resolution) * size.x;
    pos.y = glPos.y + (data[i] + 1) / 2 * size.y;
    vert[i].setPosition(pos);
  }
}

void Plot::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(rect, states);
  for (int i = 0; i < resolution; i++) {
    target.draw(vert[i], states);
  }
}