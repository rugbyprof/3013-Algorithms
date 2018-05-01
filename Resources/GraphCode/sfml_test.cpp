#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(50.f);
    float x=1.0;
    float y=1.0;
    float yinc = 2;
    float xinc = 2;
    shape.setPosition(x,y);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);

        shape.setPosition(x+=xinc,y+=yinc);
        if(x <= 0 || x>950){
            xinc *= -1;
        }
        if(y <= 0 || y>950){
            yinc *= -1;
        }
        window.display();
    }
    return 0;
}