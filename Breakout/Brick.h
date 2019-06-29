#pragma once
#include "GameObject.h"
#include "Engine.h"
class Brick : public GameObject
{
public:
	Brick();
	Brick(Vector2* initialPosition, float width, float height);
	~Brick();

	virtual void HandleCollision(GameObject* other);
	virtual void Update();
};

