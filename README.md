TODO: убрать айди из кнопки.

gui:
gui(int resolutionX, int resolutionY, const char *title) -init gui
void pushElement(uielement *elem) - add element to gui
void update() - must call in infinite loop
bool isOpen() - true when window is open

TODO: Добавить в uielement метод "virtual char getElTipe()" и если элемент не список список, то добавлять его перед списками

uielement:
virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const - inherited from sf::Drawable
virtual void click() - call automaticaly in gui when element is clicked
virtual void setHover(bool state) - call automaticaly in gui when element is hovered
virtual sf::FloatRect getGlobalBounds() - must return global bounds of the element
virtual void mouseOut() - call when mouse out element

button:
setPosition(float x, float y) - set position of the button
void setFillColor(sf::Color color) - set button fill color
void setId(int id) - set id of the button
setClickCallback(void (\*callback)(int,void \*)) - set click callback
void setUserCallbackData(void \*);
example:

    struct testData{
        int x;
        int y;
    }
    void clickCallback(int id, void *userCallbackData) {
      testData *data = (testData *)userCallbackData;
      std::cout<<data.x;
      std::cout<<data.y;
    }

    void main(){
        button btn;
        testData* data;
        btn.setUserCallbackData(&data);
        btn.setClickCallback(clickCallback);
    }

isHover() - true when hover on button;
bool isClicked() - true when button clicked (can use instead of callback)

list:
bool changed() - true if changed;
int getSelectedItem() - return selectedItem;
