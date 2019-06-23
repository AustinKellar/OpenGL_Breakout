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
	velocity->x = 3.f;
	velocity->y = -3.f;
}

Direction Ball::GetDirectionOfCollision(GameObject* other)
{
	float self_bottom = this->position->y + (this->height / 2.f);
	float self_right = this->position->x + (this->width / 2.f);
	float other_bottom = other->position->y + (other->height / 2.f);
	float other_right = other->position->x + (other->width / 2.f);

	float bottom_collision = other_bottom - this->position->y;
	float top_collision = self_bottom - other->position->y;
	float left_collision = self_right - other->position->x;
	float right_collision = other_right - this->position->x;

	if (top_collision < bottom_collision && top_collision < left_collision && top_collision < right_collision)
	{
		return TOP;
	}
	else if (bottom_collision < top_collision && bottom_collision < left_collision && bottom_collision < right_collision)
	{
		return BOTTOM;
	}
	else if (left_collision < right_collision && left_collision < top_collision && left_collision < bottom_collision)
	{
		return LEFT;
	}
	else if (right_collision < left_collision && right_collision < top_collision && right_collision < bottom_collision)
	{
		return RIGHT;
	}
	else
	{
		return INSIDE;
	}
}

void Ball::HandleCollision(GameObject* other)
{
	Direction dir = GetDirectionOfCollision(other);

	printf("%d\n", dir);
	
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
