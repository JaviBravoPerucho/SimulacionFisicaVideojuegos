#pragma once
#include "Particle.h"
#include <random>
#include <list>

class Emisor
{
public:
	Emisor(Vector3 pos, double t) :pos(pos), tiempoDeVida(t), tiempoTotal(0), fuente(0), limiteEspacio(10) {};

	virtual void createParticle() = 0;

	void integrate(double t);

protected:
	std::list<Particle*> fuente;
	double tiempoDeVida, tiempoTotal, limiteEspacio;
	Vector3 pos;
};

