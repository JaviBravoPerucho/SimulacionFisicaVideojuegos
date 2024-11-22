#pragma once
#include "ForceGenerator.h"


class GravitationalForce : public ForceGenerator {
public:
	GravitationalForce(Vector3 initPos, Vector3 volumen) :ForceGenerator(initPos, volumen) { gravedad = Vector3(0, -G,  0); };

	Vector3 setForce(Particle* p) override;
	void update(float t) {};

private:
	Vector3 gravedad;
};