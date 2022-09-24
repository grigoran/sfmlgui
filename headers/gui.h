#include "button.h"
#include "list.h"
#include <SFML/Graphics.hpp>
#include <vector>
class Gui {
private:
  std::vector<uielement *> uielements;
  sf::RenderWindow window;
  sf::Vector2i mousePos;
  void draw();

public:
  Gui(int resolutionX, int resolutionY, const char *title);
  void pushElement(uielement *elem);
  void update();
  bool isOpen();
};