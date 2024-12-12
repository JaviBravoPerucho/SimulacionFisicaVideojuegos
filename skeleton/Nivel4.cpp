#include "Nivel4.h"

void Nivel4::setDif(Difficulty tipo)
{

	switch (tipo) {
	case DIF1:
		generadorMuelles1->setK(10000);
		generadorMuelles2->setK(10000);
		break;
	case DIF2:
		generadorMuelles1->setK(100000);
		generadorMuelles2->setK(100000);
		break;
	case DIF3:
		generadorMuelles1->setK(1000000);
		generadorMuelles2->setK(1000000);
		break;
	}
}

void Nivel4::updateMuelles() {
	generadorMuelles1->setForce(muelle1);
	generadorMuelles2->setForce(muelle2);
	generadorMuelles1->applyForces();
	generadorMuelles2->applyForces();
}