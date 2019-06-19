#pragma once
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>
class Player : public GameObject
{
public:
	Player();
	Player(Vector2* initialPosition, float width, float height, GLFWwindow* window);
	~Player();
	virtual void HandleCollision(GameObject* other);
	virtual void Update();

protected:
	void HandleInput();
	GLFWwindow* window;
};

