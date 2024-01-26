//
// Created by Theo Castillo on 23/01/2024.
//

#include "Particle.h"


Particle::Particle(sf::Vector2f initilalPosition,sf::Vector2f myVelocity,float myRadius){
    position = initilalPosition;
    velocity = myVelocity;
    radius = myRadius;
    acceleration = sf::Vector2f(0,0);

    circle.setPosition(position);
    circle.setRadius(radius);
    circle.setFillColor(sf::Color::White);
}

sf::Vector2f Particle::forceGravitationelle(Particle p) {
    sf::Vector2f vectorDist = distance(p);
    float dist = sqrt(pow(vectorDist.x, 2) + pow(vectorDist.y, 2));
    dist = std::max(dist,50.0f);
    float force = G / (dist * dist);

    return {-force * vectorDist.x / dist, -force * vectorDist.y / dist};
}

sf::Vector2f Particle::distance(Particle p){
    return {position.x - p.getPosition().x,position.y - p.getPosition().y};
}

void Particle::update(float dt) {
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;

    position.x += velocity.x * dt * 60;
    position.y += velocity.y * dt * 60;
    circle.setPosition(position);
}

void Particle::applyGravity(Particle center) {
    const sf::Vector2f forceG = forceGravitationelle(center);
    acceleration.x = forceG.x;
    acceleration.y = forceG.y;
}


void Particle::draw(sf::RenderWindow& win) {
    win.draw(circle);
}

void Particle::drawHalo(sf::RenderWindow& win, float size, float opacity) {
    sf::CircleShape halo;
    sf::Vector2f haloPosition = position + sf::Vector2f(radius, radius);
    halo.setPosition(haloPosition);
    halo.setRadius(radius + size);
    halo.setOrigin(halo.getRadius(), halo.getRadius()); // Set the origin to the center
    halo.setFillColor(sf::Color(255, 255, 255, opacity)); // Convert opacity to alpha
    win.draw(halo);
}

sf::Vector2f Particle::getPosition() {
    return position;
}

sf::Vector2f Particle::getVelocity() {
    return velocity;
}

sf::CircleShape Particle::getCircle() {
    return circle;
}

float Particle::getG(){
    return G;
}

void Particle::setG(float value) {
    G = value;
}

void Particle::setColor(sf::Color color) {
    circle.setFillColor(color);
}


