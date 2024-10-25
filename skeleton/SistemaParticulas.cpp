#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas()
{
	//sistemaDeParticulas.push_back(new EmisorDistribucionUniforme(Vector3(0), 5, 2.0));
	//sistemaDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 2.0));
	sistemaDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 20.0));
}

void SistemaParticulas::update(double t)
{
	for (int i = 0; i < sistemaDeParticulas.size(); i++) {
		sistemaDeParticulas[i]->integrate(t);
	}
}
