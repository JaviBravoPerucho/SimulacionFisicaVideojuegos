#include "Nivel.h"

Nivel::Nivel(Vector3 posBasket, PxPhysics* physics, PxScene* scene, int niv):nivel(niv)
{
	basket = new Basket(posBasket);
	basket->addBasketToScene(physics, scene);
}
