#pragma once
#include "Entity.h"
#include "Scene/IRenderable.h"
#include <sstream>
#include <SFML/Graphics/Text.hpp>

class TextCounter : public Entity, public IRenderable
{
public: 
    TextCounter(SceneNode* Parent);

    TextCounter* SetText(const char* NewText);
    TextCounter* SetColor(sf::Color NewColor);
    void Increase();

    //IRenderable
    virtual void OnDraw(sf::RenderTarget& target) override;

private:
    const char* counterName;
    sf::Text counterText;
    std::stringstream s;
    int counter = 0;
};

