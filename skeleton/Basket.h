#pragma once
#include <PxPhysicsAPI.h>

#include "RenderUtils.hpp"

using namespace physx;

class Basket
{
public:
	Basket(PxVec3 position):initPos(position) {  }

	void addBasketToScene(PxPhysics* physics, PxScene* scene);

protected:
	PxVec3 initPos;
};

