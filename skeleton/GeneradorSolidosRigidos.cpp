#include "GeneradorSolidosRigidos.h"

GeneradorSolidosRigidos::GeneradorSolidosRigidos(PxVec3 pos, int maxElems, PxGeometry* geo, Vector3 linear_v, Vector3 ang_v, float d, Vector4 c, PxPhysics* p, PxScene* s) :
	init_pos(pos), max_elems(maxElems), geometry(geo), linear(linear_v), ang(ang_v), density(d), color(c), phys(p), scene(s)
{
}

void GeneradorSolidosRigidos::addSolid(float t)
{
	Vector3 pos = Vector3(distribucionNormal(init_pos.x, 20), distribucionNormal(init_pos.y, 20), distribucionNormal(init_pos.z, 20));
	PxTransform tr(pos);

	PxReal radius = 1.0f;
	PxReal mass = 10.0f;

	PxReal inertia = (2.0f / 5.0f) * mass * radius * radius;
	PxVec3 inertiaTensor(inertia+t, inertia+t, inertia+t);

	SolidoRigido* solid = new SolidoRigido(tr, geometry, linear, ang, density, color, phys, scene, inertiaTensor);

	solidos.push_back(solid);
}


float GeneradorSolidosRigidos::distribucionNormal(float media, float dt)
{
	static std::default_random_engine generator;
	std::normal_distribution<float> distribution(media, dt);
	return distribution(generator);
}

void GeneradorSolidosRigidos::integrate(float t)
{
	if(solidos.size() <= max_elems)addSolid(t);
}
