#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel):vel(Vel),pose(Pos)
{
	PxSphereGeometry geometry(1);
	PxShape* shape = CreateShape(geometry);
	transform = new PxTransform(pose);
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
	RegisterRenderItem(renderItem);
	a = Vector3(10,0,0);
	damping_ratio = 0.99;
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void Particle::integrate(double t) {
	pose = pose + vel * t;
	vel = vel * damping_ratio +a * t;

	transform->p = pose;

}