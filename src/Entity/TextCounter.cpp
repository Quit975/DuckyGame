#include "TextCounter.h"
#include "ResourceManager.h"

TextCounter::TextCounter(SceneNode* Parent, float x, float y, const char* text, sf::Color color):
    Entity(Parent),
    counterName{text}
{
    s << counterName << " count : " << counter;

    counterText.setFont(ResourceManager::Get().GetFont("Text"));
    counterText.setString(s.str());
    counterText.setCharacterSize(24);
    counterText.setFillColor(color);
    counterText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    counterText.setPosition(x, y);
}

void TextCounter::Increase()
{
    counter++;
    s.str(std::string());
    s << counterName << " count : " << counter;
    counterText.setString(s.str());
}

void TextCounter::OnUpdate(const float dt)
{
}