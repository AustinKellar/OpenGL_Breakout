#pragma once
#include "Vector2.h"
#include <vector>
#include <string.h>
#include <iostream>

class GameObject
{
public:
	// fields
	Vector2* position;
	std::string name;
	float width;
	float height;
	float halfWidth;
	float halfHeight;
	float area;
	Vector2* ul;
	Vector2* ll;
	Vector2* ur;
	Vector2* lr;

	std::vector<Vector2*> points;

	// constructors and destructor
	GameObject();
	GameObject(Vector2* initialPosition, float width, float height);
	~GameObject();


	// methods
	virtual void HandleCollision(GameObject* other) = 0;
	virtual void Update();
	
protected:
	Vector2* velocity;

private:
	void Draw();
	void ApplyPhysics();
};

