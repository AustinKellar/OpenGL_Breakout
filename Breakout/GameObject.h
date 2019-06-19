#pragma once
#include "Vector2.h"
#include <vector>
class GameObject
{
public:
	Vector2* position;
	float width;
	float height;
	float area;
	
	Vector2* ul;
	Vector2* ll;
	Vector2* ur;
	Vector2* lr;
	std::vector<Vector2*> points;

	GameObject();
	GameObject(Vector2* initialPosition, float width, float height);
	~GameObject();

	virtual void HandleCollision(GameObject* other) = 0;
	virtual void Update();
	
protected:
	Vector2* velocity;

private:
	void Draw();
	void ApplyPhysics();
};

