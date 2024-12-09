#include "GeneradorFuerzasSolidos.h"

void GeneradorFuerzasSolidos::applyForces()
{
	if (generador != nullptr) {
		std::list<SolidoRigido*> solidos = generador->getSolids();

		for (auto s : solidos) {
			s->getRigidDynamic()->addForce(fuerza);
		}
	}
	
	for (auto s : solids) {
		s->getRigidDynamic()->addForce(fuerza);
	}
}
