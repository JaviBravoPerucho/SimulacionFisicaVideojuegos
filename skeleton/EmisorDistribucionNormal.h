#pragma once
#include "Emisor.h"

class EmisorDistribucionNormal : public Emisor
{
public:
	EmisorDistribucionNormal(Vector3 pos, double t, double dt, float limite,float masa, float te) : Emisor(pos, t, limite,te), desviacion(dt)
	{
		Vector3 posaux = Vector3(distribucionNormal(0, desviacion), distribucionNormal(0, desviacion), distribucionNormal(0, desviacion));
		Vector3 ac = Vector3(0, 0, 0);
		float tiempo = tiempoDeVida + tiempoTotal;
		setModel({ posaux, Vector3(0, 0, 0), ac, tiempo, masa, PUNTO, {1,1,1,1} });
	};

	float distribucionNormal(float media, float dt);

	void createParticle() override;

private:
	float desviacion;
};

