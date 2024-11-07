#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas()
{
	//emisoresDeParticulas.push_back(new EmisorDistribucionUniforme(Vector3(0), 5, 10.0,100));
	emisoresDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 20, 100));
	//emisoresDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 20.0));

}

void SistemaParticulas::update(double t)
{
	for (int i = 0; i < emisoresDeParticulas.size(); i++) {
		emisoresDeParticulas[i]->integrate(t);
	}
	particulas = emisoresDeParticulas.back()->getParticles();
}
