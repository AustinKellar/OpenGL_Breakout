#include "Ball.h"



Ball::Ball() : GameObject()
{
}

Ball::Ball(Vector2* initialPosition, float width, float height) : GameObject(initialPosition, width, height)
{
	velocity->x = 3.f;
	velocity->y = -3.f;
}

void Ball::HandleCollision(GameObject* other)
{

}

void Ball::Update()
{
	GameObject::Update();
}

Ball::~Ball()
{
}
