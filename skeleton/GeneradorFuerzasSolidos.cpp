#include "GeneradorFuerzasSolidos.h"

void GeneradorFuerzasSolidos::applyForces()
{
	std::list<SolidoRigido*> solidos = generador->getSolids();

	for (auto s : solidos) {
		s->getRigidDynamic()->addForce(fuerza);
	}
}
