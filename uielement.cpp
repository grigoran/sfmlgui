#include "uielement.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
void uielement::draw(sf::RenderTarget &target, sf::RenderStates states) const {}

void uielement::setHover(sf::Vector2i mousePos) {}
sf::FloatRect uielement::getGlobalBounds() { return sf::FloatRect(); }
void uielement::click(sf::Vector2i mousePos){};
void uielement::mouseOut(){};