#include "Ball.h"



Ball::Ball() : GameObject()
{
}

Ball::Ball(Vector2* initialPosition, float width, float height) : GameObject(initialPosition, width, height)
{
}

void Ball::Update()
{
	GameObject::Update();
}

Ball::~Ball()
{
}
