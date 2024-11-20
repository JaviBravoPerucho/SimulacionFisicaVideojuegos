#include "SpringForceGenerator.h"

Vector3 SpringForceGenerator::setForce(Particle* particle)
{
	Vector3 relative_pos_vector = _other->getPos() - particle->getPos();
	Vector3 force;

	const float length = relative_pos_vector.normalize();
	const float delta_x = length - _resting_length;

	force = relative_pos_vector * delta_x * _k;

	return force;
}
