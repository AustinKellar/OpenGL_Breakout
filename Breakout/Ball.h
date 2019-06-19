#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball();
	Ball(Vector2* initialPosition, float width, float height);
	~Ball();
	virtual void HandleCollision(GameObject* other);
	virtual void Update();
};

