#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
class uielement : public sf::Drawable {
private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  virtual void click(sf::Vector2i mousePos);
  virtual void setHover(sf::Vector2i mousePos);
  virtual sf::FloatRect getGlobalBounds();
  virtual void mouseOut();
};

#endif
