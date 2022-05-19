#pragma once
#include "Entity.h"
#include <sstream>

class TextCounter : public Entity
{
public: 
    TextCounter(float x, float y, const char* text, sf::Color color);
    void Increase();

    virtual void Update(const float dt) override;
    virtual void Draw(sf::RenderWindow& window) override;
    virtual sf::FloatRect GetBounds() override;

private:
    sf::Font font;
    const char* counterName;
    sf::Text counterText;
    std::stringstream s;
    int counter = 0;
};

