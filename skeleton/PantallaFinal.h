#pragma once
#include "Nivel.h"
#include "ggPos.h"

class PantallaFinal : public Nivel
{
public:
	PantallaFinal(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv);

	void createSolid(PxScene* s, PxPhysics* p, PxTransform t, PxMaterial* m);

private:
};

