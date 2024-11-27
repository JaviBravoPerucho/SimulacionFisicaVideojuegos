#include "SistemaFuerzas.h"

void SistemaFuerzas::update(double t)
{
	particles = sisParticulas->getParticles();
	Vector3 v = Vector3(0);

	if (!force_registry.empty()) {
		for (auto it : force_registry) {
			v += it.first->setForce(it.second);
			it.first->update(t);
			it.second->addForce(v);
		}
	}
	else {
		for (auto p : particles) {
			v = Vector3(0, 0, 0);
			for (auto g : generadores) {
				auto iterator = std::find(force_registry.begin(), force_registry.end(), make_pair(g, p));
				if (iterator != force_registry.end())v = g->setForce(p);
				else v += g->setForce(p);
	
				g->update(t);
			}

			p->addForce(v);
		}
	}
	
}

void SistemaFuerzas::generateSpringDemo() {
	//Primero une dos particulas
	Particle* p1 = new Particle({ -10.0, 10.0, 0.0 }, { 0.0,0.0,0.0 }, { 0.0,0.0,0.0 }, 60, 0.8);
	Particle* p2 = new Particle({ 10, 0, 10.0 }, { 0.0,0.0,0.0 }, { 0.0,0.0,0.0 }, 60, 0.8);
	p2->setMass(2.0);

	SpringForceGenerator* f1 = new SpringForceGenerator(Vector3(0), Vector3(10), 1, 10, p2);

	SpringForceGenerator* f2 = new SpringForceGenerator(Vector3(0), Vector3(10), 1, 10, p1);

	generadores.push_back(f1);
	generadores.push_back(f2);
	sisParticulas->addParticle(p1);
	sisParticulas->addParticle(p2);
	force_registry.push_back({ f2, p2 });
	force_registry.push_back({ f1, p1 });


	//Segundo desde un lado fijo
	Particle* p3 = new Particle({ -10.0, 20.0, 0.0 }, { 0.0,0.0,0.0 }, { 0.0,0.0,0.0 }, 60, 0.8);
	AnchoredSpringFG* f3 = new AnchoredSpringFG(1, 13, { 10.0,20.0,0.0 });
	generadores.push_back(f3);
	sisParticulas->addParticle(p3);
	force_registry.push_back({ f3, p3 });

	
}

void SistemaFuerzas::generateBuoyancyDemo()
{
	model_t agua = { { -10.0, 30.0, 0.0 }, { 0.0,0.0,0.0 }, { 0.0,0.0,0.0 }, 60, 500, BOX, {0, 0, 1, 0.5}, {10, 5, 10} };//Pos, vel, ac, tiempo, masa, forma,color,dimensiones
	Particle* p = new Particle(agua);
	sisParticulas->addParticle(p);

	model_t cubo = { { -10.0, 40.0, 0.0 }, { 0.0,0.0,0.0 }, { 0.0,0.0,0.0 }, 60, 10, BOX, {1, 1, 1, 1}, {3, 3, 3} };
	Particle* p2 = new Particle(cubo);
	sisParticulas->addParticle(p2);

	BuoyancyForceGenerator* bfg = new BuoyancyForceGenerator(3, 27, 1000, p);
	force_registry.push_back({ bfg, p2 });

	GravitationalForce* gf = new GravitationalForce({ -10, 40, 0 }, { 100,100,100 });
	force_registry.push_back({ gf, p2 });

}
