#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas():tiempoTotal(0)
{
	//emisoresDeParticulas.push_back(new EmisorDistribucionUniforme(Vector3(0), 5, 10.0,100, 2.0f, 10));
	//emisoresDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 2, 100, 2.0f, 10));
	emisoresDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 5.0, 200.0f, 10));

}

void SistemaParticulas::update(double t)
{
	for (int i = 0; i < emisoresDeParticulas.size(); i++) {
		emisoresDeParticulas[i]->integrate(t);
	}
	if(!emisoresDeParticulas.empty())particulas = emisoresDeParticulas.back()->getParticles();

	if (!particulas.empty())integrateParticles(t);
}

void SistemaParticulas::integrateParticles(double t)
{
	tiempoTotal += t;

	std::list<Particle*>::iterator it = particulas.begin();

	while (it != particulas.end()) {

		(*it)->integrate(t);

		if (tiempoTotal >= (*it)->t()) {
			delete (*it);
			it = particulas.erase(it);
		}
		else it++;
	}
}

