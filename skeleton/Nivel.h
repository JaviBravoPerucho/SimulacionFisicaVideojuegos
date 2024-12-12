#pragma once
#include "Basket.h"
#include "GeneradorFuerzasSolidos.h"

enum ObstacleType {
	DERIZQ, DERIZQ2, ARRABA, DIAGONAL
};

enum MuelleType {
	DOBLE1, DOBLE2, ANCHORED
};


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

	virtual int getVientoValue()const { return 0; };
	virtual void addObstacle(ObstacleType tipo) = 0;
	virtual void updateObstacles() = 0;
	virtual void addMuelle(MuelleType tipo) = 0;

protected:
	Basket* basket;
	GeneradorFuerzasSolidos* gfs = NULL;
	int nivel;
};

