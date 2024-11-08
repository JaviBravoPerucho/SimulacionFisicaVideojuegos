#include "EmisorDistribucionNormal.h"


float EmisorDistribucionNormal::distribucionNormal(float media, float dt)
{
	static std::default_random_engine generator;
	std::normal_distribution<float> distribution(media, dt);
	return distribution(generator);
}


void EmisorDistribucionNormal::createParticle()
{
	Particle* p = new Particle(modelo_particula);
	p->setVel(Vector3(distribucionNormal(0, desviacion), distribucionNormal(20, desviacion), distribucionNormal(0, desviacion)));
	p->setTiempo(tiempoDeVida + tiempoTotal);
	fuente.push_back(p);
}
