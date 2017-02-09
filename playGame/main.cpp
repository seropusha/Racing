
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Graphics.hpp>

int widht = 1024;
int height = 768;

void drawQuad(sf::RenderWindow &w, sf::Color c, int x1, int y1, int w1, int x2, int y2, int w2) {
    sf::ConvexShape shape(4);
    shape.setFillColor(c);
    shape.setPoint(0, sf::Vector2f(x1-w1,y1));
    shape.setPoint(1, sf::Vector2f(x2-w2,y2));
    shape.setPoint(2, sf::Vector2f(x2+w2,y2));
    shape.setPoint(3, sf::Vector2f(x1+w1,y1));
    w.draw(shape);
}

int main(int, char const**) {
    sf::RenderWindow window(sf::VideoMode(widht, height), "Racing window");
    window.setFramerateLimit(40);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            window.clear();
            drawQuad(window, sf::Color::Green, 500, 500, 200, 500, 300, 100);
            window.display();
        }
    }
    
    return EXIT_SUCCESS;
}
