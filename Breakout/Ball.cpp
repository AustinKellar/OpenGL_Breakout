#include "Ball.h"

enum Direction : short
{
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
	INSIDE
};

Ball::Ball() : GameObject()
{
}

Ball::Ball(Vector2* initialPosition, float width, float height) : GameObject(initialPosition, width, height)
{
	this->name = "Ball";
	velocity->x = 3.f;
	velocity->y = -3.f;
}

Direction Ball::GetDirectionOfCollision(GameObject* other)
{
	float w = this->halfWidth + other->halfWidth;
	float h = this->halfHeight + other->halfHeight;
	float dx = this->position->x - other->position->x;
	float dy = this->position->y - other->position->y;

	float wy = w * dy;
	float hx = h * dx;

	if (wy > hx)
	{
		if (wy > -hx)
		{
			return TOP;
		}
		else
		{
			return LEFT;
		}
	}
	else
	{
		if (wy > -hx)
		{
			return RIGHT;
		}
		else
		{
			return BOTTOM;
		}
	}
}

void Ball::HandleCollision(GameObject* other)
{
	Direction dir = GetDirectionOfCollision(other);

	if (dir == TOP)
	{
		printf("Hit from top\n");
	}
	
	if (dir == BOTTOM)
	{
		printf("Hit from bottom\n");
	}

	if (dir == LEFT)
	{
		printf("Hit from left\n");
	}

	if (dir == RIGHT)
	{
		printf("Hit from right\n");
	}

	if (dir == INSIDE)
	{
		printf("Hit from inside\n");
	}

	if (dir == TOP || dir == BOTTOM)
	{
		velocity->y *= -1;
	}
	if (dir == RIGHT || dir == LEFT)
	{
		velocity->x *= -1;
	}
}

void Ball::Update()
{
	GameObject::Update();
}

Ball::~Ball()
{
}
