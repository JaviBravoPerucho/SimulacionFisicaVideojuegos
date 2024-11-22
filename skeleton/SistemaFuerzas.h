#pragma once
#include "AnchoredSpringFG.h"
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

	void generateSpringDemo();

private:
	list<ForceGenerator*> generadores;
	SistemaParticulas* sisParticulas;
	list<Particle*> particles;
	list<pair<ForceGenerator*, Particle*>> force_registry;

};

