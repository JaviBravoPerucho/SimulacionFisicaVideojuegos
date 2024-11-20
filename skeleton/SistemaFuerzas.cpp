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

void SistemaFuerzas::generateSpringDemo() {
	Particle* p1 = new Particle({ -10.0, 10.0, 0.0 }, { 0.0,0.0,0.0 }, { 0.0,0.0,0.0 }, 0.85, 60);
	Particle* p2 = new Particle({ 10.0, 10.0, 0.0 }, { 50.0,0.0,0.0 }, { 0.0,0.0,0.0 }, 0.85, 60);
	p2->setMass(2.0);

	SpringForceGenerator* f1 = new SpringForceGenerator(Vector3(0), Vector3(10), 1, 10, p2);

	SpringForceGenerator* f2 = new SpringForceGenerator(Vector3(0), Vector3(10), 1, 10, p1);

	generadores.push_back(f1);
	generadores.push_back(f2);
	particles.push_back(p1);
	particles.push_back(p2);
}
