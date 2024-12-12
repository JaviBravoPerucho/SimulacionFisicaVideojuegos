#pragma once
#include "Nivel.h"
#include "GeneradorFuerzasSolidos.h"

const Vector3 POS_OBS1 = { 30,40,30 };
const Vector3 POS_OBS2 = { -30,29,30 };
const Vector3 POS_OBS3 = { -10,-30,50 };
const Vector3 POS_OBS4 = { 0,50,70 };
const Vector3 BOX_DIM = { 5,5,5 };

class Nivel3 : public Nivel
{
public:
	Nivel3(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv) : Nivel::Nivel(posBasket, phys, scene, niv) {
		PxVec3 fuerza = PxVec3(0, -10, 0);
		gfs = new GeneradorFuerzasSolidos(nullptr, fuerza, { 0,0,0 }, { 1000,1000,1000 });
		gPhysics = phys;
		gScene = scene;
		numObstaculos = 0;
		obs1 = nullptr;
		obs2 = nullptr;
		obs3 = nullptr;
		obs4 = nullptr;
	};
	
	void addObstacle(ObstacleType tipo);

	void updateObstacles();

private:
	SolidoRigido* obs1;
	SolidoRigido* obs2;
	SolidoRigido* obs3;
	SolidoRigido* obs4;
	int numObstaculos;
	physx::PxPhysics* gPhysics;
	physx::PxScene* gScene;
};

