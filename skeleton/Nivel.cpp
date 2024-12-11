#include "Nivel.h"

Nivel::Nivel(Vector3 posBasket, PxPhysics* physics, PxScene* scene, int niv):nivel(niv)
{
	basket = new Basket(PxVec3(0, 30, 0));
	basket->addBasketToScene(physics, scene);
}
