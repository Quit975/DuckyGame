#pragma once
#include "Entity.h"
#include <sstream>
#include <SFML/Graphics/Text.hpp>

class TextCounter : public Entity
{
public: 
    TextCounter(SceneNode* Parent, float x, float y, const char* text, sf::Color color);
    void Increase();

    //Scene Node
    virtual void OnUpdate(const float dt) override;

private:
    const char* counterName;
    sf::Text counterText;
    std::stringstream s;
    int counter = 0;
};

