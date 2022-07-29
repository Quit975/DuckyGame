#include "TextCounter.h"
#include "ResourceManager.h"

TextCounter::TextCounter(SceneNode* Parent):
    Entity(Parent),
    IRenderable(Parent->GetScene())
{
    counterText.setFont(ResourceManager::Get().GetFont("Text"));
    counterText.setCharacterSize(24);
    counterText.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

TextCounter* TextCounter::SetText(const char* NewText)
{
    counterName = NewText;
    s << counterName << " : " << counter;
    counterText.setString(s.str());
    return this;
}

TextCounter* TextCounter::SetColor(sf::Color NewColor)
{
    counterText.setFillColor(NewColor);
    return this;
}

void TextCounter::Increase()
{
    counter++;
    s.str(std::string());
    s << counterName << " : " << counter;
    counterText.setString(s.str());
}

void TextCounter::OnDraw(sf::RenderTarget& target)
{
    target.draw(counterText, GetWorldTransform().getTransform());
}
