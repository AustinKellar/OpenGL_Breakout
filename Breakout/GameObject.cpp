#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>

GameObject::GameObject()
{
	this->position = NULL;
	this->width = NULL;
	this->height = NULL;
	this->velocity = NULL;
	this->toBeDestroyed = false;
}

GameObject::GameObject(Vector2* initialPosition, float width, float height)
{
	this->position = initialPosition;
	this->width = width;
	this->height = height;
	this->halfWidth = (width / 2.f);
	this->halfHeight = (height / 2.f);
	this->velocity = new Vector2(0.f, 0.f);
	this->area = width * height;

	this->ul = new Vector2(initialPosition->x - halfWidth, initialPosition->y + halfHeight);
	this->ur = new Vector2(initialPosition->x + halfWidth, initialPosition->y + halfHeight);
	this->ll = new Vector2(initialPosition->x - halfWidth, initialPosition->y - halfHeight);
	this->lr = new Vector2(initialPosition->x + halfWidth, initialPosition->y - halfHeight);

	this->name = "Unnamed GameObject";

	this->points = { ul, ur, ll, lr };
	this->toBeDestroyed = false;
}

void GameObject::ApplyPhysics()
{
	position->x += velocity->x;
	position->y += velocity->y;
}

void GameObject::Draw()
{
	glBegin(GL_QUADS);

	ll->x = position->x - halfWidth;
	ll->y = position->y - halfHeight;

	ul->x = position->x - halfWidth;
	ul->y = position->y + halfHeight;

	ur->x = position->x + halfWidth;
	ur->y = position->y + halfHeight;

	lr->x = position->x + halfWidth;
	lr->y = position->y - halfHeight;

	glVertex3f(ll->x,ll->y, 0.0);
	glVertex3f(ul->x, ul->y, 0.0);
	glVertex3f(ur->x, ur->y, 0.0);
	glVertex3f(lr->x, lr->y, 0.0);

	glEnd();
}

void GameObject::Update()
{
	ApplyPhysics();
	Draw();
}

void GameObject::Destroy()
{
	this->toBeDestroyed = true;
}

GameObject::~GameObject()
{
}
