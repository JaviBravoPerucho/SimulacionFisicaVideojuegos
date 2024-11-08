#pragma once
#include "Emisor.h"

class EmisorDistribucionUniforme : public Emisor
{
public:
	EmisorDistribucionUniforme(Vector3 pos, double t, double dt, float limite, float masa) : Emisor(pos, t, limite), desviacion(dt)
	{
		Vector3 vel = Vector3(distribucionUniforme(1.0, desviacion), distribucionUniforme(2.0, desviacion), distribucionUniforme(1.0, desviacion));
		Vector3 ac = Vector3(0, -10, 0);
		float tiempo = tiempoDeVida + tiempoTotal;
		setModel({ pos, vel, ac,tiempo, masa });
	};

	double distribucionUniforme(double a, double b);

	void createParticle() override;

private:
	double desviacion;
};

