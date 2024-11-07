#pragma once
#include "Emisor.h"

class EmisorDistribucionUniforme : public Emisor
{
public:
	EmisorDistribucionUniforme(Vector3 pos, double t, double dt, float limite) : Emisor(pos, t, limite), desviacion(dt) {};

	double distribucionUniforme(double a, double b);

	void createParticle() override;

private:
	double desviacion;
};

