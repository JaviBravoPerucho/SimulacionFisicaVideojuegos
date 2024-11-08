#pragma once
#include "Particle.h"
#include <random>
#include <list>


class Emisor
{
public:
	Emisor(Vector3 pos, double t, float limite) :pos(pos), tiempoDeVida(t), tiempoTotal(0), fuente(0), limiteEspacio(limite), modelo_particula() {};

	virtual void createParticle() = 0;

	void integrate(double t);

	std::list<Particle*> getParticles() const { return fuente; }

	void setModel(model_t model) { modelo_particula = {model.pos, model.vel, model.ac, model.tiempo, model.masa}; };
	model_t getModelo() const { return modelo_particula; }


protected:
	std::list<Particle*> fuente;
	double tiempoDeVida, tiempoTotal, limiteEspacio;
	Vector3 pos;
	model_t modelo_particula;
};

