#include "Particle.h"
#include <random>
#include <list>


class SistemaParticulas
{
public:
	SistemaParticulas(Vector3 pos, double t, double dt) :pos(pos), tiempoDeVida(t), desviacion(dt), eliminate(0), tiempoTotal(0), fuente(0) {};

	float distribucionNormal(float media, float dt);
	float distribucionUniforme(float a, float b);

	void createParticle();

	void integrate(double t);

private:
	std::list<Particle*> fuente;
	std::list<Particle*> eliminate;
	double tiempoDeVida, desviacion, tiempoTotal;
	Vector3 pos;
};

