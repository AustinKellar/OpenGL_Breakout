#include "Brick.h"



Brick::Brick()
{
	this->name = "Brick";
}

Brick::Brick(Vector2* initialPosition, float width, float height) : GameObject::GameObject(initialPosition, width, height)
{
	this->name = "Brick";
}

void Brick::HandleCollision(GameObject* other)
{
	Destroy();
}

void Brick::Update()
{
	GameObject::Update();
}


Brick::~Brick()
{
}
