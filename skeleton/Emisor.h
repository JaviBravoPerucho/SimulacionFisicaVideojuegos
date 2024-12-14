#pragma once
#include "Particle.h"
#include <random>
#include <list>


class Emisor
{
public:
	Emisor(Vector3 pos, double t, float limite, float te) :stopEmitting(false), pos(pos), tiempoDeVida(t), tiempoTotal(0), fuente(0), limiteEspacio(limite), modelo_particula(), tiempoEmitiendo(te) {};

	virtual void createParticle() = 0;

	void integrate(double t);

	std::list<Particle*> getParticles() const { return fuente; }

	void setModel(model_t model) { modelo_particula = {model.pos, model.vel, model.ac, model.tiempo, model.masa, model.forma, model.color}; };
	model_t getModelo() const { return modelo_particula; }
	bool eliminar()const { return tiempoTotal >= tiempoEmitiendo; }

	void setEmitting(bool emit) { stopEmitting = emit; }

protected:
	std::list<Particle*> fuente;
	double tiempoDeVida, tiempoTotal, limiteEspacio, tiempoEmitiendo;
	Vector3 pos;
	model_t modelo_particula;
	bool stopEmitting;
};

