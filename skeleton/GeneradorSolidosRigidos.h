#pragma once
#include "SolidoRigido.h"
#include <list>
#include <random>

class GeneradorSolidosRigidos
{
public:
	GeneradorSolidosRigidos(PxVec3 pos, int maxElems, PxGeometry* geo, Vector3 linear_v, Vector3 ang_v, float d, Vector4 c, PxPhysics* p, PxScene* s);

	void addSolid(float t);

	float distribucionNormal(float media, float dt);

	void integrate(float t);

	std::list<SolidoRigido*> getSolids()const { return solidos; }

protected:
	Vector3 init_pos;
	std::list<SolidoRigido*> solidos;
	int max_elems;
	PxGeometry* geometry;
	Vector3 linear;
	Vector3 ang;
	float density;
	Vector4 color;
	PxPhysics* phys;
	PxScene* scene;
};

