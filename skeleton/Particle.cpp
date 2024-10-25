#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 ac, float tiempoDeVida):vel(Vel),pose(Pos), masa(0), a(ac), tiempo(tiempoDeVida)
{

	transform = physx::PxTransform(pose);
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &transform, Vector4(1, 1, 1, 1));
	RegisterRenderItem(renderItem);
	damping_ratio = 0.99;
	vs = vel.magnitude();
}

Particle::~Particle()
{
	renderItem = nullptr;
}

void Particle::integrate(double t) {
	pose = pose + vel * t;
	vel = vel * pow(damping_ratio, t) +a * t;

	transform.p = pose;
}


