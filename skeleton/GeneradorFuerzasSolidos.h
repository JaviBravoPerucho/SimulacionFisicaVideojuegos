#pragma once
#include "GeneradorSolidosRigidos.h"

class GeneradorFuerzasSolidos
{
public:
	GeneradorFuerzasSolidos(GeneradorSolidosRigidos* gsr, PxVec3 f, PxVec3 init, PxVec3 v) :fuerza(f), initPos(init), volumen(v), generador(gsr) {};

	void applyForces();

	void addSolid(SolidoRigido* solid) { solids.push_back(solid); };

protected:
	PxVec3 fuerza;
	PxVec3 initPos;
	PxVec3 volumen;
	GeneradorSolidosRigidos* generador;
	std::vector<SolidoRigido*> solids;
};

