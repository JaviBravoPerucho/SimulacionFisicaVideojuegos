#include "SistemaParticulas.h"

float SistemaParticulas::distribucionNormal(float media, float dt)
{
	static std::default_random_engine generator;
	std::normal_distribution<float> distribution(media, dt);
	return distribution(generator);
}

float SistemaParticulas::distribucionUniforme(float a, float b)
{
	static std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(a, b);
	return distribution(generator);
}

void SistemaParticulas::createParticle()
{
	Vector3 position = Vector3(0);
	Vector3 vel = Vector3(distribucionNormal(0, desviacion), distribucionNormal(20, desviacion), distribucionNormal(0, desviacion));
	Vector3 ac = Vector3(0,-10,0);
	Particle* p = new Particle(position, vel, ac, tiempoDeVida + tiempoTotal);
	fuente.push_back(p);
}

void SistemaParticulas::integrate(double t)
{
	tiempoTotal += t;
	createParticle();

	eliminate.clear();
	for (auto p : fuente) {
		if (p != nullptr) {
			p->integrate(t);

			if (tiempoTotal >= p->t())eliminate.push_back(p);
		}
	}
	if (!eliminate.empty()) {
		for (auto e : eliminate) {
			if (e != nullptr) {
				//eliminate.remove(e);
			}
		}
	}
}
