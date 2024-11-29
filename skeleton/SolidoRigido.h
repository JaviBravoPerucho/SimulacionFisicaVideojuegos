#pragma once
#include "PxRigidDynamic.h"
#include "core.hpp"
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"

using namespace physx;

class SolidoRigido
{
public:
	SolidoRigido(PxTransform t, PxBoxGeometry geo, Vector3 linear_v, Vector3 ang_v, float density, Vector4 color, PxPhysics* phys, PxScene* scene);

protected:
	PxRigidDynamic* solid;
	PxShape* shape;
	RenderItem* renderItem;
};

