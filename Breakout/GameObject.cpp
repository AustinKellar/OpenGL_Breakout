#include "GameObject.h"

#include <GLFW/glfw3.h>
#include <gl/GL.h>

GameObject::GameObject()
{
	this->position = NULL;
	this->width = NULL;
	this->height = NULL;
}

GameObject::GameObject(Vector2* initialPosition, float width, float height)
{
	this->position = initialPosition;
	this->width = width;
	this->height = height;
}

void GameObject::Draw()
{
	glBegin(GL_QUADS);

	// bottom left
	glVertex3f(position->x - (width / 2.f), position->y - (height / 2.f), 0.0);

	// top left
	glVertex3f(position->x - (width / 2.f), position->y + (height / 2.f), 0.0);

	// top right
	glVertex3f(position->x + (width / 2.f), position->y + (height / 2.f), 0.0);

	// bottom right
	glVertex3f(position->x + (width / 2.f), position->y - (height / 2.f), 0.0);

	glEnd();
}

void GameObject::Update()
{
	Draw();
}

GameObject::~GameObject()
{
}
