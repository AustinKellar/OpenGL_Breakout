#include "CollisionDetector.h"

CollisionDetector::CollisionDetector()
{
}

CollisionDetector::CollisionDetector(std::vector<GameObject*>* gameObjects)
{
	this->gameObjects = gameObjects;
}

float AreaOfTriangle(Vector2* p1, Vector2* p2, Vector2* p3)
{
	return ( ( p1->x * ( p2->y - p3->y ) ) + ( p2->x * ( p3->y - p1->y ) ) + ( p3->x * ( p1->y - p2->y ) ) / 2.f );
}

bool IsCollision(GameObject* obj1, GameObject* obj2)
{
	float w = obj1->halfWidth + obj2->halfWidth;
	float h = obj1->halfHeight + obj2->halfHeight;
	float dx = obj1->position->x - obj2->position->x;
	float dy = obj1->position->y - obj2->position->y;
	float wy = w * dy;
	float hx = h * dx;

	return abs(dx) <= w && abs(dy) <= h;
}

void CollisionDetector::DetectCollisions()
{
	for (int i = 0; i < gameObjects->size(); i++)
	{
		obj1 = (*gameObjects)[i];
		for (int j = 0; j < gameObjects->size(); j++)
		{
			if (i != j)
			{
				obj2 = (*gameObjects)[j];
				if (IsCollision(obj1, obj2))
				{
					obj1->HandleCollision(obj2);
				}
			}
		}
	}
}

CollisionDetector::~CollisionDetector()
{
}
