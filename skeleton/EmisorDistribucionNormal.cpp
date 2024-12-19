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
	modelo_particula.pos = Vector3(distribucionNormal(1, desviacion), distribucionNormal(1, desviacion), distribucionNormal(1, desviacion));
	p->setTiempo(tiempoDeVida + tiempoTotal);
	fuente.push_back(p);
}
