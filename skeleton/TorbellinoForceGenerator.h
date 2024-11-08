#pragma once
#include "ForceGenerator.h"


class TorbellinoForceGenerator : public ForceGenerator
{
public:
	TorbellinoForceGenerator(Vector3 p, Vector3 v) :ForceGenerator(p, v), k(3) {};

	Vector3 fuerzaTorbellino(Particle* p) {
		Vector3 aux = {
		-(p->getPos().z - initPos.z),
		50-(p->getPos().y-initPos.y),
		p->getPos().z - initPos.x
		};
		return (k * aux) - p->getVel();
	}

	Vector3 setForce(Particle* p)override { return fuerzaTorbellino(p); }
	void update(float t) {};

private:
	Vector3 viento;
	float k;
};

