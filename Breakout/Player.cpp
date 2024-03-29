#include "Player.h"


Player::Player() : GameObject()
{
}

Player::Player(Vector2* initialPosition, float width, float height, GLFWwindow* window) : GameObject(initialPosition, width, height)
{
	this->window = window;
	this->name = "Player";
}

void Player::HandleInput() 
{
	velocity->x = 0.f;

	if (glfwGetKey(window, GLFW_KEY_D) && position->x < 750.f)
	{
		velocity->x = 7.f;
	}

	if (glfwGetKey(window, GLFW_KEY_A) && position->x > 50.f)
	{
		velocity->x = -7.f;
	}
}

void Player::HandleCollision(GameObject* other)
{

}

void Player::Update()
{
	HandleInput();
	GameObject::Update();
}


Player::~Player()
{
}
