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
	for (int i = 0; i < obj1->points.size(); i++)
	{
		float area = 0.f;
		Vector2* P = obj1->points[i];

		Vector2* A = obj2->ul;
		Vector2* B = obj2->ur;
		Vector2* C = obj2->lr;
		Vector2* D = obj2->ll;

		area += AreaOfTriangle(P, A, D) + AreaOfTriangle(P, D, C) + AreaOfTriangle(P, C, B) + AreaOfTriangle(P, B, A);

		if (abs(obj2->area - area) < 5000.f)
		{
			return true;
		}
	}
	return false;
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
					obj2->HandleCollision(obj1);
				}
			}
		}
	}
}

CollisionDetector::~CollisionDetector()
{
}
