#include "Particle.h"
#include <random>
#include <list>


class SistemaParticulas
{
public:
	SistemaParticulas(Vector3 pos, float t, float dt) :pos(pos), tiempoDeVida(t), desviacion(dt) {};

	float distribucionNormal(float media, float dt);

	void createParticle();

	void integrate(float t);

private:
	std::vector<Particle*> fuente;
	std::list<Particle*> eliminate;
	float tiempoDeVida, desviacion;
	Vector3 pos;
};

