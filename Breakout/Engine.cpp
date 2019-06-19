#include "Engine.h"



Engine::Engine()
{
	collisionDetector = new CollisionDetector(&gameObjects);
}

void Engine::Instantiate(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);
}

void Engine::Destroy(GameObject* gameObject)
{

}

void Engine::Update()
{
	collisionDetector->DetectCollisions();
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}
}

Engine::~Engine()
{
}
