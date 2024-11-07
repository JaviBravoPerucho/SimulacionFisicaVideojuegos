#pragma once
#include "Particle.h"
#include <random>
#include <list>

class Emisor
{
public:
	Emisor(Vector3 pos, double t, float limite) :pos(pos), tiempoDeVida(t), tiempoTotal(0), fuente(0), limiteEspacio(limite) {};

	virtual void createParticle() = 0;

	void integrate(double t);

	std::list<Particle*> getParticles() const { return fuente; }

protected:
	std::list<Particle*> fuente;
	double tiempoDeVida, tiempoTotal, limiteEspacio;
	Vector3 pos;
};

