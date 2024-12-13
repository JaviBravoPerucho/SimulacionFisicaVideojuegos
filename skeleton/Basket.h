#pragma once
#include <PxPhysicsAPI.h>

#include "RenderUtils.hpp"

using namespace physx;

class Basket
{
public:
	Basket(PxVec3 position):initPos(position) {  }

	void addBasketToScene(PxPhysics* physics, PxScene* scene);

	PxVec3 getInitPos()const { return initPos; }

	~Basket() {
		for (auto& r : renderItems) {
			r->release();
		}
		actors.clear();
	}

protected:
	PxVec3 initPos;
	std::vector<PxRigidStatic*> actors;
	std::vector<RenderItem*> renderItems;

};

