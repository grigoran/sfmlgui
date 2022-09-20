#include "button.h"
#include "list.h"
#include <SFML/Graphics.hpp>
#include <vector>
class gui {
private:
  std::vector<uielement *> uielements;
  sf::RenderWindow window;
  sf::Vector2i mousePos;
  void draw();

public:
  gui(int resolutionX, int resolutionY, const char *title);
  void pushElement(uielement *elem);
  void update();
  bool isOpen();
};