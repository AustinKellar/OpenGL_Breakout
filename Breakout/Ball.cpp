#include "Ball.h"

Ball::Ball() : GameObject()
{
}

Ball::Ball(Vector2* initialPosition, float width, float height) : GameObject(initialPosition, width, height)
{
	this->name = "Ball";
	velocity->x = 3.5f;
	velocity->y = -3.5f;
	xVelLastFrame = velocity->x;
	yVelLastFrame = velocity->y;
}

bool Ball::HitFromTop(float wy, float hx)
{
	return (wy > hx && wy > -hx);
}

bool Ball::HitFromLeft(float wy, float hx)
{
	return (wy > hx && wy <= -hx);
}

bool Ball::HitFromRight(float wy, float hx)
{
	return (wy <= hx && wy > -hx);
}

bool Ball::HitFromBottom(float wy, float hx)
{
	return (wy <= hx && wy <= -hx);
}


void Ball::HandleCollision(GameObject* other)
{
	float w = this->halfWidth + other->halfWidth;
	float h = this->halfHeight + other->halfHeight;
	float dx = this->position->x - other->position->x;
	float dy = this->position->y - other->position->y;

	float wy = w * dy;
	float hx = h * dx;

	if ((HitFromTop(wy, hx) || HitFromBottom(wy, hx)) && velocity->y * yVelLastFrame > 0.f)
	{
		velocity->y *= -1.005;
	}

	if ((HitFromLeft(wy, hx) || HitFromRight(wy, hx)) && velocity->x * xVelLastFrame > 0.f)
	{
		velocity->x *= -1.005;
	}
}

void Ball::Update()
{
	GameObject::Update();
	yVelLastFrame = velocity->y;
	xVelLastFrame = velocity->x;
}

Ball::~Ball()
{
}
