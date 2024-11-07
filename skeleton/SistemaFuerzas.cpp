#include "SistemaFuerzas.h"

void SistemaFuerzas::update(double t)
{
	particles = sisParticulas->getParticles();
	Vector3 v;
	for (auto p : particles) {
		v = Vector3(0, 0, 0);
		for (auto g : generadores) {
			v += g->setForce(p);
		}
		std::cout << v.x << " " << v.y << " " << v.z << endl;
		p->addForce(v);
	}
}
