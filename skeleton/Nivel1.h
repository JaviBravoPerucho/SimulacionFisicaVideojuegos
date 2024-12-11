#pragma once
#include "Nivel.h"
#include "GeneradorFuerzasSolidos.h"

class Nivel1 : public Nivel
{
public:
	Nivel1(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv) : Nivel::Nivel(posBasket, phys, scene, niv) {
		PxVec3 fuerza = PxVec3(0, -10, 0);
		gfs = new GeneradorFuerzasSolidos(nullptr, fuerza, { 0,0,0 }, { 1000,1000,1000 });
	};

private:

};

