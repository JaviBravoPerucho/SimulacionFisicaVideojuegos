#pragma once
#include "Nivel.h"
#include "SpringForceSolids.h"

const Vector3 POS_MUE1 = { 20,40,10 };
const Vector3 POS_MUE2 = { -40,40,10 };
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
		PxGeometry* sphere = new PxSphereGeometry(BALL_DIM);
		muelle1 = new SolidoRigido(PxTransform(POS_MUE1), sphere, Vector3(0), Vector3(0), 5000.0f, Vector4(1, 0, 0, 1), gPhysics, gScene, PxVec3(0));
		muelle2 = new SolidoRigido(PxTransform(POS_MUE2), sphere, Vector3(0), Vector3(0), 5000.0f, Vector4(1, 0, 0, 1), gPhysics, gScene, PxVec3(0));
		generadorMuelles1 = new SpringForceSolids(PxVec3(0), PxVec3(0), PxVec3(20), 1000, 30, muelle2);
		generadorMuelles1->addSolid(muelle1);
		generadorMuelles2 = new SpringForceSolids(PxVec3(0), PxVec3(0), PxVec3(20), 1000, 30, muelle1);
		generadorMuelles2->addSolid(muelle2);
	}

	void setDif(Difficulty tipo);
	void updateMuelles();

	~Nivel4() {
		delete muelle1;
		delete muelle2;
		delete generadorMuelles1;
		delete generadorMuelles2;
	}

private:
	SolidoRigido* muelle1;
	SolidoRigido* muelle2;
	physx::PxPhysics* gPhysics;
	physx::PxScene* gScene;
	SpringForceSolids* generadorMuelles1;
	SpringForceSolids* generadorMuelles2;
};

