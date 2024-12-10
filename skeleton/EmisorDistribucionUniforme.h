#pragma once
#include "Emisor.h"
#include <random>

class EmisorDistribucionUniforme : public Emisor
{
public:
	EmisorDistribucionUniforme(Vector3 pos, double t, double dt, float limite, float masa, float te) : Emisor(pos, t, limite,te), desviacion(dt)
	{
		Vector3 vel = Vector3(distribucionUniforme(-desviacion, desviacion), distribucionUniforme(-desviacion, desviacion), distribucionUniforme(-desviacion, desviacion));
		Vector3 ac = Vector3(0, 0, 0);
		float tiempo = tiempoDeVida + tiempoTotal;

		Vector4 color = { (float)distribucionUniforme(0,1),(float)distribucionUniforme(0,1), (float)distribucionUniforme(0,1), 1 };
		setModel({ pos, vel, ac,tiempo, masa, PUNTO, color});
	};

	double distribucionUniforme(double a, double b);

	void createParticle() override;

private:
	double desviacion;
};

