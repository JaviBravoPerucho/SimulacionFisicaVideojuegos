#include "EmisorDistribucionNormal.h"


float EmisorDistribucionNormal::distribucionNormal(float media, float dt)
{
	static std::default_random_engine generator;
	std::normal_distribution<float> distribution(media, dt);
	return distribution(generator);
}


void EmisorDistribucionNormal::createParticle()
{
	Vector3 position = Vector3(0);
	Vector3 vel = Vector3(distribucionNormal(0, desviacion), distribucionNormal(20, desviacion), distribucionNormal(0, desviacion));
	Vector3 ac = Vector3(0, -10, 0);
	Particle* p = new Particle(position, vel, ac, tiempoDeVida + tiempoTotal);
	fuente.push_back(p);
}
