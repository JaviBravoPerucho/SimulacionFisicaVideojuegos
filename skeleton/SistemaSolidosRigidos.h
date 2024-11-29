#pragma once
#include "SolidoRigido.h"
#include <list>

class SistemaSolidosRigidos
{
public:
	SistemaSolidosRigidos();

	void update(double t);

	std::list<SolidoRigido*> getSolids()const { return solidos; }

	void addSolid(SolidoRigido* sr) { solidos.push_back(sr); }

	//void integrateSolids(double t);

private:
	std::list<SolidoRigido*> solidos;
};

