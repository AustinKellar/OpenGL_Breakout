#include "GameObject.h"

#include <GLFW/glfw3.h>
#include <gl/GL.h>

GameObject::GameObject()
{
	this->position = NULL;
	this->width = NULL;
	this->height = NULL;
	this->velocity = NULL;
}

GameObject::GameObject(Vector2* initialPosition, float width, float height)
{
	this->position = initialPosition;
	this->width = width;
	this->height = height;
	this->velocity = new Vector2(0.f, 0.f);
	this->area = width * height;

	this->ul = new Vector2(initialPosition->x - (width / 2.f), initialPosition->y + (height / 2.f));
	this->ur = new Vector2(initialPosition->x + (width / 2.f), initialPosition->y + (height / 2.f));
	this->ll = new Vector2(initialPosition->x - (width / 2.f), initialPosition->y - (height / 2.f));
	this->lr = new Vector2(initialPosition->x + (width / 2.f), initialPosition->y - (height / 2.f));

	this->points = { ul, ur, ll, lr };
}

void GameObject::ApplyPhysics()
{
	position->x += velocity->x;
	position->y += velocity->y;
}

void GameObject::Draw()
{
	glBegin(GL_QUADS);

	ll->x = position->x - (width / 2.f);
	ll->y = position->y - (height / 2.f);

	ul->x = position->x - (width / 2.f);
	ul->y = position->y + (height / 2.f);

	ur->x = position->x + (width / 2.f);
	ur->y = position->y + (height / 2.f);

	lr->x = position->x + (width / 2.f);
	lr->y = position->y - (height / 2.f);

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

GameObject::~GameObject()
{
}
