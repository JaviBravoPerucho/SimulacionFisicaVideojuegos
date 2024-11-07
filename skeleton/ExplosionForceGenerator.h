#pragma once
#include "ForceGenerator.h"

class ExplosionForceGenerator : public ForceGenerator
{
public:
	ExplosionForceGenerator(Vector3 p, Vector3 v, float R) :ForceGenerator(p, v), k(3), R(R)
	{
		float xc = initPos.x + R;
		float yc = initPos.y + R;
		float zc = initPos.z + R;
		r = sqrt(pow(p.x - xc, 2) + pow(p.y - yc, 2) + pow(p.z - zc, 2));
	};

	Vector3 fuerzaExplosion(Particle* p) {
		float difX = p->getPos().x - p->getPos().x + R;
		float difY = p->getPos().y - p->getPos().y + R;
		float difZ = p->getPos().z - p->getPos().z + R;
		r = sqrt(pow(difX, 2) + pow(difY, 2) + pow(difZ, 2));
		Vector3 Fe = Vector3((k / (r * r)) * difX, (k / (r * r)) * difY, (k / (r * r)) * difZ);

		if (r >= R)Fe = Vector3(0);

		return Fe;
	}

	Vector3 setForce(Particle* p)override { return fuerzaExplosion(p); }

private:
	Vector3 viento;
	float t, r, R, k;

};

