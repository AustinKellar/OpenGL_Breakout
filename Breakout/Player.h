#pragma once
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>
class Player : public GameObject
{
public:
	Player();
	Player(Vector2* initialPosition, float width, float height, GLFWwindow* window);
	virtual void Update();
	~Player();

protected:
	void HandleInput();
	GLFWwindow* window;
};

