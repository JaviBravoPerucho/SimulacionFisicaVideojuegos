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
		particulas = e->getParticles();
		if (e->eliminar())emisoresDeParticulasAEliminar.push_back(e);
	}
	//if (!particulas.empty())integrateParticles(t);

	for (auto e : emisoresDeParticulasAEliminar) {
		if(e->getParticles().empty())emisoresDeParticulas.remove(e);//Solo se elimina cuando no quedan part�culas para poder aplicarles las fuerzas
	}
}

void SistemaParticulas::eliminarEmisor(Emisor* emisor) {
	emisoresDeParticulas.remove(emisor);
}

void SistemaParticulas::a�adirEmisor(Emisor* emisor) {
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

