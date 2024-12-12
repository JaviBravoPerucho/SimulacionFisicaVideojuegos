#include "SpringForceSolids.h"

void SpringForceSolids::setForce(SolidoRigido* solid)
{
	Vector3 relative_pos_vector = _other->getRigidDynamic()->getGlobalPose().p - solid->getRigidDynamic()->getGlobalPose().p;
	Vector3 force;

	const float length = relative_pos_vector.normalize();
	const float delta_x = length - _resting_length;

	force = relative_pos_vector * delta_x * _k;

	fuerza = force;
}
