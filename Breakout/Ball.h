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
private:
	bool HitFromTop(float wy, float hx);
	bool HitFromLeft(float wy, float hx);
	bool HitFromRight(float wy, float hx);
	bool HitFromBottom(float wy, float hx);

	bool hitFromTopLastFrame;
	bool hitFromLeftLastFrame;
	bool hitFromRightLastFrame;
	bool hitFromBottomLastFrame;
};

