#include "SistemaFuerzas.h"

void SistemaFuerzas::update(double t)
{
	particles = sisParticulas->getParticles();
	Vector3 v;
	for (auto p : particles) {
		v = Vector3(0, 0, 0);
		for (auto g : generadores) {
			v += g->setForce(p);
			g->update(t);
		}

		p->addForce(v);
	}
}
