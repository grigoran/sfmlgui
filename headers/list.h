#include "uielement.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class list : public uielement {
private:
  sf::Color rectColor;
  sf::Color rectHoverColor;
  sf::RectangleShape rect;
  sf::RectangleShape menuBackground;
  sf::Text *content;
  sf::Text selectedContent;
  sf::Font font;
  int fontSize;
  int fontSpacing;
  int contentSize;
  int selectedItem;
  bool isChanged;
  bool hover;
  void (*changeCallback)(void *, int);
  static void defaultCallback(void *, int);
  void *userCallbackData;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  virtual void click(sf::Vector2i mousePos);
  virtual void setHover(sf::Vector2i mousePos);
  virtual void mouseOut();
  virtual sf::FloatRect getGlobalBounds();

  bool isMenuOpen;

public:
  void setUserCallbackData(void *data);
  void setChangeCallback(void (*callback)(void *, int));
  void setContent(const char **content, int size);
  void setPosition(float x, float y);
  bool changed();
  int getSelectedItem();
  list();
};