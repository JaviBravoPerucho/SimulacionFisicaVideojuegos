#pragma once
#include "Nivel.h"
#include "GeneradorFuerzasSolidos.h"

const Vector3 POS_MUE1 = { 30,40,30 };
const Vector3 POS_MUE2 = { -30,40,30 };
const Vector3 POS_MUE3 = { -10,-30,50 };
const Vector3 POS_MUE4 = { -10,30,50 };
const Vector3 POS_MUE5 = { -10,40,70 };
const INT BALL_DIM = { 5 };

class Nivel4 : public Nivel
{
public:
	Nivel4(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv) : Nivel::Nivel(posBasket, phys, scene, niv) {
		PxVec3 fuerza = PxVec3(0, -10, 0);
		gfs = new GeneradorFuerzasSolidos(nullptr, fuerza, { 0,0,0 }, { 1000,1000,1000 });
		gPhysics = phys;
		gScene = scene;
		muelle1 = nullptr;
		muelle2 = nullptr;
		muelle3 = nullptr;
		muelle4 = nullptr;
		muelle5 = nullptr;
	}

	void addMuelle(MuelleType tipo);

private:
	SolidoRigido* muelle1;
	SolidoRigido* muelle2;
	SolidoRigido* muelle3;
	SolidoRigido* muelle4;
	SolidoRigido* muelle5;
	physx::PxPhysics* gPhysics;
	physx::PxScene* gScene;
};

