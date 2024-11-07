#pragma once
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

using namespace physx;

class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 ac, float tiempoDeVida, float m);
	~Particle();

	void integrate(double t);

	float t()const { return tiempo; }
	PxTransform trans()const { return transform; }
	Vector3 getPos()const { return pose; }
	Vector3 getVel()const { return vel; }

	bool estaFuera(double limite)const { return transform.p.x >= limite || transform.p.y >= limite || transform.p.z >= limite; }

	void addForce(Vector3 f) {	fuerzaTotal = f;};
private:
	Vector3 vel;
	Vector3 pose;
	Vector3 a;
	Vector3 fuerzaTotal;

	float damping_ratio, tiempo;
	PxTransform transform;
	RenderItem* renderItem;
	float masa;
	int vs;
};

