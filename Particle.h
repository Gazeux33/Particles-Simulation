//
// Created by Theo Castillo on 23/01/2024.
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/Graphics.hpp"

class Particle {
private:
    sf::CircleShape circle;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;
    float radius;
    float G = 6.67430e-4;


    sf::Vector2f distance(Particle p);
public:
    Particle(sf::Vector2f initilalPosition,sf::Vector2f myVelocity,float myMass,float myRadius);
    sf::Vector2f forceGravitationelle(Particle p);
    void update(float dt);
    void draw(sf::RenderWindow& win);
    sf::Vector2f getPosition();
    sf::Vector2f getVelocity();
    sf::CircleShape getCircle();
    void applyGravity(Particle center);
    float getG();
    void setG(float value);
    void setColor(sf::Color color);
    void drawHalo(sf::RenderWindow& win,float size,float opacity);
    float getMass();
    void setAcceleration(sf::Vector2f newValue);
};



#endif //PARTICLE_H
