#pragma once
#include "Basket.h"
#include "GeneradorFuerzasSolidos.h"

enum ObstacleType {
	DERIZQ, DERIZQ2, ARRABA, DIAGONAL
};

enum Difficulty {
	DIF1, DIF2, DIF3
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
	virtual void addObstacle(ObstacleType tipo) {};
	virtual void updateObstacles() {};
	virtual void setDif(Difficulty tipo) {};
	virtual void updateMuelles() {};
	virtual void nuevoViento() {};

	virtual ~Nivel() {
		delete basket;
		delete gfs;
	}

protected:
	Basket* basket;
	GeneradorFuerzasSolidos* gfs = NULL;
	int nivel;
};

