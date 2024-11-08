#pragma once
#include "Emisor.h"

class EmisorDistribucionNormal : public Emisor
{
public:
	EmisorDistribucionNormal(Vector3 pos, double t, double dt, float limite,float masa) : Emisor(pos, t, limite), desviacion(dt)
	{
		Vector3 vel = Vector3(distribucionNormal(0, desviacion), distribucionNormal(20, desviacion), distribucionNormal(0, desviacion));
		Vector3 ac = Vector3(0, 0, 0);
		float tiempo = tiempoDeVida + tiempoTotal;
		setModel({ pos, vel, ac, tiempo, masa });
	};

	float distribucionNormal(float media, float dt);

	void createParticle() override;

private:
	float desviacion;
};

