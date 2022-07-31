#include "StaticImage.h"
#include "Components/SpriteComponent.h"

StaticImage::StaticImage(SceneNode* Parent):
	Entity(Parent)
{
	spriteComp = CreateComponent<SpriteComponent>("spriteComp");
}

StaticImage::~StaticImage()
{
}

StaticImage* StaticImage::SetImageTexture(const char* TexID)
{
	spriteComp->SetTexture(TexID);
	return this;
}
