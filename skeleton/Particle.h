#pragma once
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

using namespace physx;

class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel);
	~Particle();

	void integrate(double t);

private:
	Vector3 vel;
	Vector3 pose;
	Vector3 a;
	float damping_ratio;
	PxTransform* transform;
	RenderItem* renderItem;
};

