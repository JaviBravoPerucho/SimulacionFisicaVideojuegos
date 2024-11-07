#include "GravitationalForce.h"

Vector3 GravitationalForce::setForce(Particle* p)
{
    Vector3 dist = initPos - p->getPos();
	if (abs(dist.x) <= volumen.x && abs(dist.y) <= volumen.y && abs(dist.z) <= volumen.z) {
		return gravedad;
	}
	else {
		return Vector3(0, 0, 0);
	}
}
