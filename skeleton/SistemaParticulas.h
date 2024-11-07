#pragma once
#include "EmisorDistribucionNormal.h"
#include "EmisorDistribucionUniforme.h"

class SistemaParticulas
{
public:
	SistemaParticulas();

	void update(double t);

	std::list<Particle*> getParticles()const { return particulas; }

private:
	std::vector<Emisor*> emisoresDeParticulas;
	std::list<Particle*> particulas;
};
