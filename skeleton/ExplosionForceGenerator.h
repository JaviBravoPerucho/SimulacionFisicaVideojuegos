#pragma once
#include "ForceGenerator.h"
#include <numbers>

const float k = 10000;

class ExplosionForceGenerator : public ForceGenerator
{
public:
	ExplosionForceGenerator(Vector3 p, Vector3 v, float R, float timeConstant) :ForceGenerator(p, v), R(R), time(500), T(timeConstant), explode(false)
	{
		const float xc = initPos.x;
		const float yc = initPos.y;
		const float zc = initPos.z;
		r = sqrt(pow(p.x - xc, 2) + pow(p.y - yc, 2) + pow(p.z - zc, 2));
		timeInicial = time;
	};

	Vector3 fuerzaExplosion(Particle* p) {
		const float difX = p->getPos().x - initPos.x;
		const float difY = p->getPos().y - initPos.y;
		const float difZ = p->getPos().z - initPos.z;
		const float e = exp(-(0/T));
		const Vector3 aux = Vector3(difX, difY, difZ);
		r = aux.magnitude();
		Vector3 Fe = Vector3((k / (r * r)) * difX * e, (k / (r * r)) * difY * e, (k / (r * r)) * difZ * e);

		if (r >= R)Fe = Vector3(0);

		return Fe;
	}

	Vector3 setForce(Particle* p)override;

	void update(float t);

	void setExplode() { explode = !explode; }

private:
	Vector3 viento;
	float time,T, r, R, timeInicial;
	bool explode;

};

