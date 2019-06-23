#pragma once
#include <vector>
#include "GameObject.h"
#include "CollisionDetector.h"

class Engine
{
public:
	// constructors and destructors
	Engine();
	~Engine();

	// methods
	GameObject* Instantiate(GameObject* gameObject);
	void Destroy(GameObject* gameObject);
	void Update();

private:
	std::vector<GameObject*> gameObjects;
	CollisionDetector* collisionDetector;
};

