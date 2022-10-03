#include "uielement.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>

class Plot : public uielement {
private:
  sf::RectangleShape rect;
  sf::Vector2f size;
  const float *data;
  // sf::Vertex *vert;
  sf::CircleShape *vert;
  int resolution;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  void update();
  void setPosition(float x, float y);
  Plot(const float *data, int size);
};