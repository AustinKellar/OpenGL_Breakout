#include "Ball.h"

Ball::Ball() : GameObject()
{
}

Ball::Ball(Vector2* initialPosition, float width, float height) : GameObject(initialPosition, width, height)
{
	this->name = "Ball";
	velocity->x = 6.f;
	velocity->y = -6.f;
	hitFromTopLastFrame = hitFromLeftLastFrame = hitFromRightLastFrame = hitFromBottomLastFrame = false;
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

	if (HitFromTop(wy, hx))
	{
		if (!hitFromTopLastFrame)
		{
			hitFromTopLastFrame = true;
			velocity->y *= -1;
		}
	}
	else
	{
		hitFromTopLastFrame = false;
	}

	if (HitFromLeft(wy, hx))
	{
		if (!hitFromLeftLastFrame)
		{
			hitFromLeftLastFrame = true;
			velocity->x *= -1;
		}
	}
	else
	{
		hitFromLeftLastFrame = false;
	}

	if (HitFromRight(wy, hx))
	{
		if (!hitFromRightLastFrame)
		{
			hitFromRightLastFrame = true;
			velocity->x *= -1;
		}
	}
	else
	{
		hitFromRightLastFrame = false;
	}

	if (HitFromBottom(wy, hx))
	{
		if (!hitFromBottomLastFrame)
		{
			hitFromBottomLastFrame = true;
			velocity->y *= -1;
		}
	}
	else
	{
		hitFromBottomLastFrame = false;
	}
}

void Ball::Update()
{
	GameObject::Update();
}

Ball::~Ball()
{
}
