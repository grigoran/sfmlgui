#include "uielement.h"
#include <SFML/Graphics/Color.hpp>

class button : public uielement {
private:
  int id;
  sf::Color color;
  sf::Color hoverColor;
  sf::RectangleShape rect;
  sf::Clock clock;
  sf::Time lastTimeClicked;
  bool clicked;
  void (*clickCallback)(void *);
  void *userCallbackData;
  bool hover = false;
  virtual void setHover(sf::Vector2i mousePos);
  virtual void mouseOut();
  virtual void click(sf::Vector2i mousePos);
  virtual sf::FloatRect getGlobalBounds();
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  void setPosition(float x, float y);
  void setClickCallback(void (*callback)(void *));
  void setUserCallbackData(void *);
  bool isHover();
  bool isClicked();
  void setFillColor(sf::Color color);
  void setId(int id);
  button(int id);
  button();
};