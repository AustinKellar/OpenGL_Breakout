#pragma once
#include <vector>
#include "GameObject.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Instantiate(GameObject* gameObject);
	void Destroy(GameObject* gameObject);
	void Update();

private:
	std::vector<GameObject*> gameObjects;
};

