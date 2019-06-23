#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall();
	Wall(Vector2* initialPosition, float width, float height);
	~Wall();

	virtual void HandleCollision(GameObject* other);
	virtual void Update();
};

