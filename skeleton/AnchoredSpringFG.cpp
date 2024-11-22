#include "AnchoredSpringFG.h"

AnchoredSpringFG::AnchoredSpringFG(double k, double resting, const Vector3& anchor_pos):
	SpringForceGenerator(Vector3(0), Vector3(100), k, resting, nullptr)
{
	_other = new Particle({ anchor_pos, { 0,0,0 }, {0,0,0}, 0, 1e6, BOX });
}

AnchoredSpringFG::~AnchoredSpringFG() {
	delete _other;
}