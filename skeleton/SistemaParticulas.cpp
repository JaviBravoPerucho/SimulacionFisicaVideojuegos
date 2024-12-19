#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas():tiempoTotal(0)
{
}

void SistemaParticulas::update(double t)
{
	for (auto e: emisoresDeParticulas) {
		e->integrate(t);
		particulas = e->getParticles();
		if (e->eliminar())emisoresDeParticulasAEliminar.push_back(e);
	}

	for (auto e : emisoresDeParticulasAEliminar) {
		if(e->getParticles().empty())emisoresDeParticulas.remove(e);//Solo se elimina cuando no quedan partículas para poder aplicarles las fuerzas
	}
}

void SistemaParticulas::eliminarEmisor(Emisor* emisor) {
	emisoresDeParticulasAEliminar.push_back(emisor);
}

void SistemaParticulas::añadirEmisor(Emisor* emisor) {
	emisoresDeParticulas.push_back(emisor);
}

void SistemaParticulas::integrateParticles(double t)
{
	tiempoTotal += t;

	for (auto e : emisoresDeParticulas) {
		particulas = e->getParticles();
		for (auto& p : particulas)
			p->integrate(t);
	}

}

