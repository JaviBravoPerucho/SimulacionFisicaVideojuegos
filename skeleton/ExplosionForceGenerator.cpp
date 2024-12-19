#include "ExplosionForceGenerator.h"

Vector3 ExplosionForceGenerator::setForce(Particle* p)
{
	if (explode) {
		return fuerzaExplosion(p);
	}
	else return Vector3(0);

}

void ExplosionForceGenerator::update(float t)
{
	time -= t;
}
