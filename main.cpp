
#include "main.h"
#include "Particle.h"



int main()
{

    //window
    sf::RenderWindow window;
    window.create(sf::VideoMode(WIN_WIDTH,WIN_HEIGHT,32),"PlayGround");
    sf::Clock clock;

    //list
    int nbParticle = 300;
    std::vector<Particle> particlesList;

    //center
    sf::Vector2f positionCenter = sf::Vector2f(WIN_WIDTH/2,WIN_HEIGHT/2);
    sf::Vector2f velicityCenter = sf::Vector2f(0,0);
    float radiusCenter = 10.0f;
    Particle center = Particle(positionCenter,velicityCenter,radiusCenter);
    //center.setColor(sf::Color::Blue);


    // particles creation
    for(int i = 1; i < nbParticle; i++) {
        sf::Vector2f position = sf::Vector2f(rand() % WIN_WIDTH, rand() % WIN_HEIGHT);

        float dx = position.x - center.getPosition().x;
        float dy = position.y - center.getPosition().y;
        sf::Vector2f velocity = sf::Vector2f(-dy/1000, dx/1000);
        float radius = 5;
        particlesList.emplace_back(position, velocity, radius);
    }

    //main loop
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        window.clear(sf::Color(18,2,23)); // clear the window


        window.draw(center.getCircle()); // draw the center

        for(auto &p : particlesList) { // for each particle
            p.update(dt);// update the particle
            p.applyGravity(center);// apply the gravity
            p.draw(window); // draw the particle
            p.drawHalo(window,30.0f,10.0f);
        }
        window.display(); // display the window
    }
    return 0;
}
