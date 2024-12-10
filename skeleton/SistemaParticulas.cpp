#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas():tiempoTotal(0)
{
	//emisoresDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 2, 100, 2.0f));
	//emisoresDeParticulas.push_back(new EmisorDistribucionNormal(Vector3(0), 5, 5.0, 200.0f));

}

void SistemaParticulas::update(double t)
{
	for (auto e: emisoresDeParticulas) {
		e->integrate(t);
		if (e->eliminar())emisoresDeParticulasAEliminar.push_back(e);
	}
	if(!emisoresDeParticulas.empty())particulas = emisoresDeParticulas.back()->getParticles();

	//if (!particulas.empty())integrateParticles(t);

	for (auto e : emisoresDeParticulasAEliminar) {
		if(particulas.empty())emisoresDeParticulas.remove(e);//Solo se elimina cuando no quedan partículas para poder aplicarles las fuerzas
	}
}

void SistemaParticulas::eliminarEmisor(Emisor* emisor) {
	emisoresDeParticulas.remove(emisor);
}

void SistemaParticulas::añadirEmisor(Emisor* emisor) {
	emisoresDeParticulas.push_back(emisor);
}

void SistemaParticulas::integrateParticles(double t)
{
	tiempoTotal += t;

	std::list<Particle*>::iterator it = particulas.begin();

	while (it != particulas.end()) {
		(*it)->integrate(t);
		it++;
	}
}

