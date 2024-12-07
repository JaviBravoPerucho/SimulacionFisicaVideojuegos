#include "SolidoRigido.h"

SolidoRigido::SolidoRigido(PxTransform t, PxGeometry* geo, Vector3 linear_v, Vector3 ang_v, float density, Vector4 color, PxPhysics* phys, PxScene* scene, PxVec3 inertia)
{
	PxReal staticFriction = 0.5f;
	PxReal dynamicFriction = 0.3f;
	PxReal restitution = 0.7f; // Bounciness

	PxMaterial* material = phys->createMaterial(staticFriction, dynamicFriction, restitution);
	solid = phys->createRigidDynamic(t);
	solid->setLinearVelocity(linear_v);
	solid->setAngularVelocity(ang_v);
	shape = CreateShape(*geo, material);
	solid->attachShape(*shape);
	//PxReal radius = 1.0f;
	PxReal mass = 10.0f;

	//PxReal inertia = (2.0f / 5.0f) * mass * radius * radius;
	//PxVec3 inertiaTensor(inertia, inertia, inertia);

	solid->setMass(mass);
	solid->setMassSpaceInertiaTensor(inertia);
	//PxRigidBodyExt::updateMassAndInertia(*solid, density);
	scene->addActor(*solid);

	renderItem = new RenderItem(shape, solid, color);
}
