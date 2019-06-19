#include "Engine.h"



Engine::Engine()
{
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
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}
}

Engine::~Engine()
{
}
