#include "Frog.h"
#include <stdlib.h>
#include <time.h>

float VecLength(sf::Vector2<float> vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

Frog::Frog()
{
    frogShape = sf::RectangleShape({ 20.f, 20.f });
    frogShape.setPosition(400, 300);
    frogShape.setOrigin(10.f, 10.f);
    frogBuffer.loadFromFile("Res/froggy.wav");
    frogSound.setBuffer(frogBuffer);
    frogSound.setLoop(true);
    frogSound.setAttenuation(80.f);
    frogSound.setMinDistance(600.f);
    frogSound.play();

    frogCatchBuffer.loadFromFile("Res/frogCatch.wav");
    frogCatchSound.setBuffer(frogCatchBuffer);
    frogCatchSound.setVolume(100.f);
    frogCatchSound.setAttenuation(0.f);

    srand(time(NULL));
}

void Frog::Update(const float dt)
{
    frogShape.move(speed * xMovementDir * dt, speed * yMovementDir * dt);
    if (frogShape.getPosition().x <= 0.f)
        xMovementDir = 1;
    else if (frogShape.getPosition().x >= WindowWidth)
        xMovementDir = -1;

    if (frogShape.getPosition().y <= 0.f)
        yMovementDir = 1;
    else if (frogShape.getPosition().y >= WindowHeight)
        yMovementDir = -1;

    frogSound.setPosition(frogShape.getPosition().x, frogShape.getPosition().y, 0.f);
}

void Frog::Draw(sf::RenderWindow& window)
{
#ifndef _RELEASE
    sf::RectangleShape shape({20.f, 20.f});
    shape.setPosition(frogShape.getPosition().x, frogShape.getPosition().y);
    shape.setFillColor(sf::Color::Magenta);
    window.draw(shape);
#endif // _RELEASE
}

sf::FloatRect Frog::GetBounds()
{
    return frogShape.getGlobalBounds();
}

void Frog::Catch()
{
    frogCatchSound.play(); 
}

void Frog::TeleportAFP(sf::Vector2<float> playerLoc, float playerRad)
{
    float frogDiagonal = VecLength(frogShape.getSize());
    float minDistance = playerRad + safeDistance + frogDiagonal / 2;
    sf::Vector2<float> newFrogLoc{};
    sf::Vector2<float> FPDistance{};        //distance between the centers of the frog and the player

    while (!(VecLength(FPDistance) > minDistance)) {
        float x = rand() % 760 + 20;
        float y = rand() % 560 + 20;

        newFrogLoc = sf::Vector2(x, y);
        FPDistance = newFrogLoc - playerLoc;
    }
    frogShape.setPosition(newFrogLoc);
}

