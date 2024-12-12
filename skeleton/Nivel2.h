#pragma once
#include "Nivel.h"
#include "GeneradorFuerzasSolidos.h"
#include <random>

class Nivel2 : public Nivel
{
public:
	Nivel2(Vector3 posBasket, PxPhysics* phys, PxScene* scene, int niv) : Nivel::Nivel(posBasket, phys, scene, niv) {
		PxVec3 fuerza = PxVec3(0, -10, 0);
		gfs = new GeneradorFuerzasSolidos(nullptr, fuerza, { 0,0,0 }, { 1000,1000,1000 });
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(-3, 3); // define the range
		vientoValue = distr(gen);
		PxVec3 fuerzaViento = PxVec3(vientoValue, 1, 0);
		viento = new GeneradorFuerzasSolidos(nullptr, fuerzaViento, { 0,0,0 }, { 1000,1000,1000 });
	}

	void addSolid(SolidoRigido* sr)override {
		gfs->addSolid(sr);
		viento->addSolid(sr);
	}

	void applyForces()override {
		gfs->applyForces();
		viento->applyForces();
	}

	int getVientoValue()const override { return vientoValue; }
	void nuevoViento() {
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(-3, 3); // define the range
		vientoValue = distr(gen);
		PxVec3 fuerzaViento = PxVec3(vientoValue, 1, 0);
		viento->setForce(fuerzaViento);
	};
	~Nivel2() {
		delete viento;
	}

private:
	GeneradorFuerzasSolidos* viento;
	int vientoValue;
};

