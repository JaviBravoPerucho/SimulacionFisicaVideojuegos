#pragma once
#include "Basket.h"
#include "GeneradorFuerzasSolidos.h"

class Nivel
{
public:
	Nivel(Vector3 posBasket, PxPhysics* physics, PxScene* scene,int nivel);

	Vector3 getBasketPos()const {
		return basket->getInitPos();
	}

	virtual void addSolid(SolidoRigido* sr) {
		gfs->addSolid(sr);
	}
	virtual void applyForces() {
		gfs->applyForces();
	}

	int getNivel()const { return nivel; }

	virtual int getVientoValue()const = 0;

protected:
	Basket* basket;
	GeneradorFuerzasSolidos* gfs = NULL;
	int nivel;
};

