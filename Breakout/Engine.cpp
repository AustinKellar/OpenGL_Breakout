#include "Engine.h"

Engine::Engine()
{
	collisionDetector = new CollisionDetector(&gameObjects);
}

GameObject* Engine::Instantiate(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);
	return gameObject;
}

void Engine::Update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->toBeDestroyed)
		{
			gameObjects.erase(gameObjects.begin() + i);
		}
	}

	collisionDetector->DetectCollisions();
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}
}

Engine::~Engine()
{
}
