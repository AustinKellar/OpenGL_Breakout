#pragma once
#include <vector>
#include "GameObject.h"
#include <cstdlib>

class CollisionDetector
{
public:
	CollisionDetector();
	CollisionDetector(std::vector<GameObject*> gameObjects);
	void DetectCollisions();
	~CollisionDetector();

private:
	std::vector<GameObject*> gameObjects;
	GameObject* obj1;
	GameObject* obj2;
};

