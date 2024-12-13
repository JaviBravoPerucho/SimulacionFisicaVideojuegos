#pragma once
#include "Basket.h"
#include "GeneradorFuerzasSolidos.h"

enum ObstacleType {
	DERIZQ, DERIZQ2, ARRABA, DIAGONAL
};

enum Difficulty {
	DIF1, DIF2, DIF3
};

const Vector3 POS_MUE1 = { 20,40,10 };
const Vector3 POS_MUE2 = { -40,40,10 };
const Vector3 POS_MUE3 = { -10,-30,50 };
const Vector3 POS_MUE4 = { -10,30,50 };
const Vector3 POS_MUE5 = { -10,40,70 };
const INT BALL_DIM = { 5 };



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

