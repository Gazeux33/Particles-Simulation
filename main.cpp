
#include "main.h"
#include "Particle.h"



int main()
{

    //window
    sf::RenderWindow window;
    window.create(sf::VideoMode(WIN_WIDTH,WIN_HEIGHT,32),"PlayGround");
    sf::Clock clock;

    //list
    int nbParticle = 100;
    std::vector<Particle> particlesList;

    int maxMass = 10000000;

    //center
    float radiusCenter = 10.0f;
    sf::Vector2f positionCenter = sf::Vector2f(WIN_WIDTH/2,WIN_HEIGHT/2);
    sf::Vector2f velicityCenter = sf::Vector2f(0,0);
    Particle center = Particle(positionCenter,velicityCenter,maxMass,radiusCenter);
    particlesList.emplace_back(center);


    int maxRadius = 10;

    // particles creation
    for(int i = 1; i < nbParticle; i++) {
        sf::Vector2f position = sf::Vector2f(rand() % WIN_WIDTH, rand() % WIN_HEIGHT);

        float dx = position.x - center.getPosition().x;
        float dy = position.y - center.getPosition().y;
        sf::Vector2f velocity = sf::Vector2f(-dy / 1000, dx / 1000);
        int mass = rand()% maxMass/3;
        float radius = maxRadius * mass / maxMass;
        particlesList.emplace_back(position, velocity, mass,radius);
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


        for(auto &currentParticle : particlesList) { // for each particle
            currentParticle.update(dt);// update the particle
        }
        for(auto &currentParticle : particlesList) { // for each particle
            sf::Vector2f newAcceleration = sf::Vector2f(0,0);
            for(auto &p:particlesList) {
                if(&p != &currentParticle) {
                    newAcceleration += currentParticle.forceGravitationelle(p)/currentParticle.getMass();
                }
            }
            currentParticle.setAcceleration(newAcceleration);
        }
        for(auto &currentParticle : particlesList) { // for each particle
            currentParticle.draw(window); // draw the particle
            currentParticle.drawHalo(window,2.0f,10.0f);
        }
        window.display(); // display the window
    }
    return 0;
}

