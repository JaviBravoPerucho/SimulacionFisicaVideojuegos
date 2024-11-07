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
	Vector3 position = Vector3(0);
	Vector3 vel = Vector3(distribucionUniforme(1.0, desviacion), distribucionUniforme(2.0, desviacion), distribucionUniforme(1.0, desviacion));
	Vector3 ac = Vector3(0, -10, 0);
	Particle* p = new Particle(position, vel, ac, tiempoDeVida + tiempoTotal, 2.0f);
	fuente.push_back(p);
}