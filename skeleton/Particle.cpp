#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 ac):vel(Vel),pose(Pos), masa(0), a(ac)
{
	PxSphereGeometry geometry(1);
	PxShape* shape = CreateShape(geometry);
	transform = new PxTransform(pose);
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
	RegisterRenderItem(renderItem);
	damping_ratio = 0.99;
	vs = vel.magnitude();
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void Particle::integrate(double t) {
	pose = pose + vel * t;
	vel = vel * pow(damping_ratio, t) +a * t;

	transform->p = pose;

}