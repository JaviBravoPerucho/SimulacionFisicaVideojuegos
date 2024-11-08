#pragma once
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

using namespace physx;

struct model_t {
	Vector3 pos;
	Vector3 vel;
	Vector3 ac;
	float tiempo;
	float masa;
};


class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 ac, float tiempoDeVida, float m);
	Particle(model_t p);
	~Particle();

	void integrate(double t);

	float t()const { return tiempo; }
	void setTiempo(float t) { tiempo = t; }
	PxTransform trans()const { return transform; }
	Vector3 getPos()const { return pose; }
	Vector3 getVel()const { return vel; }
	Vector3 getAc()const { return a; }
	float getMasa()const { return masa; }

	bool estaFuera(double limite)const { return transform.p.x >= limite || transform.p.y >= limite || transform.p.z >= limite; }

	void addForce(Vector3 f) {	fuerzaTotal = f;};

	void setVel(Vector3 v) { vel = v; }
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

