#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 ac, float tiempoDeVida, float m):vel(Vel),pose(Pos), masa(m), a(ac), tiempo(tiempoDeVida), fuerzaTotal(0)
{

	transform = physx::PxTransform(pose);
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &transform, Vector4(1, 1, 1, 1));

	damping_ratio = 0.99;
	vs = vel.magnitude();
}

Particle::~Particle()
{
	renderItem->release();
	renderItem = nullptr;
}

void Particle::integrate(double t) {
	a = fuerzaTotal/masa;
	pose += vel * t;
	vel  += a * t;
	vel *= pow(damping_ratio, t);

	transform.p = pose;
}


