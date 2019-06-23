#pragma once
#include "GameObject.h"

enum Direction : short;

class Ball : public GameObject
{
public:
	Ball();
	Ball(Vector2* initialPosition, float width, float height);
	~Ball();

	virtual void HandleCollision(GameObject* other);
	virtual void Update();
private:
	Direction GetDirectionOfCollision(GameObject* other);
};

