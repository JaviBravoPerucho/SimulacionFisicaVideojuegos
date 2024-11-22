#pragma once
#include "EmisorDistribucionNormal.h"
#include "EmisorDistribucionUniforme.h"

class SistemaParticulas
{
public:
	SistemaParticulas();

	void update(double t);

	std::list<Particle*> getParticles()const { return particulas; }

	void addParticle(Particle* p) { particulas.push_back(p); }

	void integrateParticles(double t);

private:
	std::vector<Emisor*> emisoresDeParticulas;
	std::list<Particle*> particulas;
	float tiempoTotal;
};
