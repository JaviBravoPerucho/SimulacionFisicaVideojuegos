#include "Emisor.h"




void Emisor::integrate(double t)
{
	tiempoTotal += t;
	createParticle();

	std::list<Particle*>::iterator it = fuente.begin();

	while (it != fuente.end()) {

		(*it)->integrate(t);

		if (tiempoTotal >= (*it)->t() || (*it)->estaFuera(limiteEspacio) ) {
			delete (*it);
			it = fuente.erase(it);
		}
		else it++;
	}
}