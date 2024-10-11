#include "SistemaParticulas.h"

float SistemaParticulas::distribucionNormal(float media, float dt)
{
	static std::default_random_engine generator;
	std::normal_distribution<float> distribution(media, dt);
	return distribution(generator);
}

void SistemaParticulas::createParticle()
{
	Vector3 position = Vector3(0);
	Vector3 vel = Vector3(distribucionNormal(0, desviacion), distribucionNormal(20, desviacion), distribucionNormal(0, desviacion));
	Vector3 ac = Vector3(0,-10,0);
	fuente.push_back(new Particle(position, vel, ac, tiempoDeVida));
}

void SistemaParticulas::integrate(float t)
{
	createParticle();

	for (auto p : fuente) {
		p->integrate(t);

		if (p->death(t))eliminate.push_back(p);
	}

	/*for (auto e : eliminate) {
		eliminate.remove(e);
		delete e;
	}*/
}
