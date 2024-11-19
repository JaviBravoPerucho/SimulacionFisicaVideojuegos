#pragma once
#include "ForceGenerator.h"
#include "SistemaParticulas.h"
#include <iostream>

class SistemaFuerzas
{
public:

	SistemaFuerzas(SistemaParticulas* p) :sisParticulas(p) {};

	void addGenerator(ForceGenerator* g) {
		generadores.push_back(g);
	}

	void removeGenerator(ForceGenerator* g) {
		generadores.remove(g);
	}

	void update(double t);

private:
	list<ForceGenerator*> generadores;
	SistemaParticulas* sisParticulas;
	list<Particle*> particles;

};

