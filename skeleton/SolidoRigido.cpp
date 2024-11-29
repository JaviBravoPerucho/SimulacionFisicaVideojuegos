#include "SolidoRigido.h"

SolidoRigido::SolidoRigido(PxTransform t, PxBoxGeometry geo, Vector3 linear_v, Vector3 ang_v, float density, Vector4 color, PxPhysics* phys, PxScene* scene)
{
	solid = phys->createRigidDynamic(t);
	solid->setLinearVelocity(linear_v);
	solid->setAngularVelocity(ang_v);
	shape = CreateShape(geo);
	solid->attachShape(*shape);
	PxRigidBodyExt::updateMassAndInertia(*solid, density);
	scene->addActor(*solid);

	renderItem = new RenderItem(shape, solid, color);
}
