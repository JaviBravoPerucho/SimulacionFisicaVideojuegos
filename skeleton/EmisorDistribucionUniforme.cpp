#include "EmisorDistribucionUniforme.h"

double EmisorDistribucionUniforme::distribucionUniforme(double a, double b)
{
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> distribution(a, b);
	return distribution(gen);
	
}

void EmisorDistribucionUniforme::createParticle()
{
	Vector4 color = { (float)distribucionUniforme(0,1),(float)distribucionUniforme(0,1), (float)distribucionUniforme(0,1), 1 };
	modelo_particula.color = color;
	Particle* p = new Particle(modelo_particula);
	p->setVel(Vector3(distribucionUniforme(-desviacion, desviacion), distribucionUniforme(-desviacion, desviacion), distribucionUniforme(-desviacion, desviacion)));
	p->setTiempo(tiempoDeVida + tiempoTotal);
	fuente.push_back(p);
}