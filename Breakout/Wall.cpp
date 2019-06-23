#include "Wall.h"



Wall::Wall()
{
}

Wall::Wall(Vector2* initialPosition, float width, float height) : GameObject::GameObject(initialPosition, width, height)
{
	this->name = "Wall";
}

void Wall::HandleCollision(GameObject* other)
{

}

void Wall::Update()
{
	GameObject::Update();
}


Wall::~Wall()
{
}
