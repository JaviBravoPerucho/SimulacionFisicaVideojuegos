#pragma once
#include "ForceGenerator.h"
#include <numbers>

const float k = 10000;

class ExplosionForceGenerator : public ForceGenerator
{
public:
	ExplosionForceGenerator(Vector3 p, Vector3 v, float R, float timeConstant) :ForceGenerator(p, v), R(R), time(20), T(timeConstant)
	{
		float xc = initPos.x + R;
		float yc = initPos.y + R;
		float zc = initPos.z + R;
		r = sqrt(pow(p.x - xc, 2) + pow(p.y - yc, 2) + pow(p.z - zc, 2));
		timeInicial = time;
	};

	Vector3 fuerzaExplosion(Particle* p) {
		float difX = p->getPos().x - p->getPos().x + R;
		float difY = p->getPos().y - p->getPos().y + R;
		float difZ = p->getPos().z - p->getPos().z + R;
		float e = pow(exp(1), -(time / T));
		r = sqrt(pow(difX, 2) + pow(difY, 2) + pow(difZ, 2));
		Vector3 Fe = Vector3((k / (r * r)) * difX * e, (k / (r * r)) * difY * e, (k / (r * r)) * difZ * e);

		if (r >= R)Fe = Vector3(0);

		return Fe;
	}

	Vector3 setForce(Particle* p)override;

	void update(float t);

private:
	Vector3 viento;
	float time,T, r, R, timeInicial;

};

