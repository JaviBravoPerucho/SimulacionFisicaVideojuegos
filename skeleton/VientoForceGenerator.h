#pragma once
#include "ForceGenerator.h"

const float u = 0.9;

class VientoForceGenerator : public ForceGenerator
{
public:
	VientoForceGenerator(Vector3 p, Vector3 v, Vector3 f) :ForceGenerator(p, v), viento(f), k1(u) {

	}

	Vector3 fuerzaViento(Particle* p) {
		return k1 * (viento - p->getVel());
	}

	Vector3 setForce(Particle* p);
	void update(float t) {};

	void setViento(Vector3 nuevo) { viento = nuevo; }

private:

	Vector3 viento;
	float k1;
};

