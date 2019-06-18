#pragma once
#include "Vector2.h"
class GameObject
{
public:
	Vector2* position;
	GameObject();
	GameObject(Vector2* initialPosition, float width, float height);
	virtual void Update();
	~GameObject();

protected:
	float width;
	float height;
	Vector2* velocity;

private:
	void Draw();
	void ApplyPhysics();
};

