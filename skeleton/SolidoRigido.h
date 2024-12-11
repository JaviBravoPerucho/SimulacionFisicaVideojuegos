#pragma once
#include "PxRigidDynamic.h"
#include "core.hpp"
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"

using namespace physx;

class SolidoRigido
{
public:
	SolidoRigido(PxTransform t, PxGeometry* geo, Vector3 linear_v, Vector3 ang_v, float mass, Vector4 color, PxPhysics* phys, PxScene* scene, PxVec3 inertia);

	PxRigidDynamic* getRigidDynamic()const { return solid; }

protected:
	PxRigidDynamic* solid;
	PxShape* shape;
	RenderItem* renderItem;
};

