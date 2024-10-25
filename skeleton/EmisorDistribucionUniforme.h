#pragma once
#include "Emisor.h"

class EmisorDistribucionUniforme : public Emisor
{
public:
	EmisorDistribucionUniforme(Vector3 pos, double t, double dt) : Emisor(pos, t), desviacion(dt) {};

	double distribucionUniforme(double a, double b);

	void createParticle() override;

private:
	double desviacion;
};

